#include "main_window.h"
#include "parser.h"
#include "processor.h"
#include "modules.h"
#include "gui.h"
#include <string>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <QDebug>

MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    //    ui->pushButton->setText("AAA Button1");
  //

    /* Load file action */
    QObject::connect(ui.actionLoad_File, SIGNAL(triggered()), this, SLOT(openFile()));
    /* Step disassembly */
    QObject::connect(ui.pushButton_disasm, SIGNAL(clicked()), this, SLOT(machine_State_Step()));
    /* Run until addr */
    QObject::connect(ui.pushButton_breakpoint, SIGNAL(clicked()), this, SLOT(RunUntilAddr()));
    /* Run until line */
    QObject::connect(ui.pushButton_breakpoint_line, SIGNAL(clicked()), this, SLOT(RunUntilLine()));
    /* Start simulation - help function to load the default program*/
    QObject::connect(ui.pushButton_start, SIGNAL(clicked()), this, SLOT(start_emulator()));
    /* Connect add plot button */
    QObject::connect(ui.pushButton_add_plot, SIGNAL(clicked()), this, SLOT(Add_Plot()));
    QObject::connect(ui.analog_read_plot, SIGNAL(clicked()), this, SLOT(Add_Analog_Plot()));
    QObject::connect(ui.adc_out_plot, SIGNAL(clicked()), this, SLOT(Add_ADC_Plot()));
    /* Connect change value at address button */
    QObject::connect(ui.pushButton_setaddr, SIGNAL(clicked()), this, SLOT(Set_Addr()));
    /* Connect change bank selected */
    QObject::connect(ui.pb_set_bank, SIGNAL(clicked()), this, SLOT(change_Bank_Selected()));
    /* Connect add bit plot button */
    QObject::connect(ui.add_bit_plot, SIGNAL(clicked()), this, SLOT(Add_Bit_Plot()));
    /* Run until time in ms */
    QObject::connect(ui.pushButton_time, SIGNAL(clicked()), this, SLOT(RunUntilTime()));
    /* Clear plots */ 
    QObject::connect(ui.clear_all_plots, SIGNAL(clicked()), this, SLOT(clear_plots()));
    /* Clear plots */ 
    QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(reset()));
}

void MainWindow::Set_Addr() {

  if(file_loaded) {
    bool ok;
    priv_memory.data_memory[ui.textEdit_addr->toPlainText().toInt(&ok, 16)] = ui.textEdit_value->toPlainText().toInt(&ok, 10);
    update_LabelTableInstr();
    update_LabelTableCpu();
    update_LabelTableInt();
    update_LabelTableInt_Pir();
    update_LabelTableTmr0();
    update_LabelTableTmr1();
    update_LabelTableAdc();
    update_LabelTablePorts();
    update_LabelTableReturnStack();
    update_LabelTableFastReturnStack();
    update_Table();
  }
}


/* TBD: add something to be read from the pin */
void MainWindow::module_ports() {
  int period;
  bool ok;
  long double sine_val;
  unsigned short output;
  if(ui.checkBox_signal->isChecked()) {
    /* First read the period */
    /* SINE */
  }
  for(int i = 0 ; i < 6 ; i++) {
    u8 bits_tmp = priv_memory.data_memory[ANSELA + i*8];
    for(int j = 0 ; j < 8 ; j++) {
      priv_memory.modules.Ports_module.port_pins[i][j].val = 0x0;
      if(bits_tmp % 2 == 1) {
        // CODE IF A PORT IS IN ANALOG MODE
        /* memory->modules.Ports_module.port_pins[i][j].val = 0xFFFF; */
        /* printf("PORT number %d pin %d is analog\n", i, j); */
        // If checkbox is set we enable the wave
        if(ui.checkBox_signal->isChecked()) {
          if(ui.radioButton_sine->isChecked()) {
            period = ui.textEdit_period->toPlainText().toUInt(&ok, 10);
            sine_val = sin(2 * 3.14 * (priv_memory.Fosc_moment * priv_memory.Fosc_period_nano) / (period * 1e6));
            sine_val += 1;
            output = (unsigned short)(sine_val * 2048);
            current_analog_val = output;
            priv_memory.modules.Ports_module.port_pins[i][j].val = output;
            printf("SINE VALUE : 0x%X\n", output);
          }
          /* SQUARE */
          else {
            period = ui.textEdit_period->toPlainText().toUInt(&ok, 10);
            sine_val = sin(2 * 3.14 * (priv_memory.Fosc_moment * priv_memory.Fosc_period_nano) / (period * 1e6));
            if(sine_val > 0) output = 4095;
            else output = 1;
            current_analog_val = output;
            priv_memory.modules.Ports_module.port_pins[i][j].val = output;
            printf("SQUARE VALUE : 0x%X\n", output);
          }
        }
        // Else we write zeroes nable the wave
        else
          priv_memory.modules.Ports_module.port_pins[i][j].val = 0x0000;
      }
      bits_tmp /= 2;
    }
  }
}

static void set_Axis(QwtPlot * plot) {
  plot->setCanvasBackground( Qt::white );
  plot->setAxisScale( QwtPlot::yLeft, 0, 1, 1);
  /* QwtPlotGrid *grid = new QwtPlotGrid(); */
  /* grid->attach( plot ); */

  /* QwtPlotCurve *curve = new QwtPlotCurve(); */
  /* curve->setTitle( "Pixel Count" ); */
  /* curve->setPen( Qt::blue, 4 ), */
  /* curve->setRenderHint( QwtPlotItem::RenderAntialiased, true ); */
  /*  */
  /* QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse, */
  /*     QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) ); */
  /* curve->setSymbol( symbol ); */
  /*  */
  /* QPolygonF points; */
  /* points << QPointF( 0.0, 4.4 ) << QPointF( 1.0, 3.0 ) */
  /*     << QPointF( 2.0, 4.5 ) << QPointF( 3.0, 6.8 ) */
  /*     << QPointF( 4.0, 7.9 ) << QPointF( 5.0, 7.1 ); */
  /* curve->setSamples( points ); */
  /*   */
  /*   curve->attach( plot ); */
  plot->replot();
}

void MainWindow::Add_Bit_Plot() {
  if(plot_count == 0) {
    QHBoxLayout *plot_333;
    QwtPlot *qwtPlot_tmp;
    QVBoxLayout *verticalLayout_111;
    QVBoxLayout *verticalLayout_000;
    plot_333 = new QHBoxLayout();
    plot_333->setObjectName(QString::fromUtf8("plot_3"));
    verticalLayout_000 = new QVBoxLayout();
    verticalLayout_000->setObjectName(QString::fromUtf8("verticalLayout_0"));
    plot_333->addLayout(verticalLayout_000);
    qwtPlot_tmp = new QwtPlot(ui.verticalWidget_2);
    qwtPlot_tmp->setObjectName(QString::fromUtf8("qwtPlot"));
    bit_plot_axis = qwtPlot_tmp;
    verticalLayout_000->addWidget(qwtPlot_tmp);
    qwtPlot_tmp->enableAxis(QwtPlot::xBottom, false);
    QSizePolicy sizePolicy_a(QSizePolicy::Expanding, QSizePolicy::Expanding);
    qwtPlot_tmp->setSizePolicy(sizePolicy_a);
    set_Axis(qwtPlot_tmp);
    verticalLayout_111 = new QVBoxLayout();
    verticalLayout_111->setObjectName(QString::fromUtf8("verticalLayout_9"));
    plot_333->addLayout(verticalLayout_111);
    ui.verticalWidget_bit_time->addLayout(plot_333);
  }
  plot_count++;
  QHBoxLayout *plot_3;
  QwtPlot *qwtPlot;
  QVBoxLayout *verticalLayout_9;
  QVBoxLayout *verticalLayout_0;
  QTextEdit *textEdit_2;
  QTextEdit *textEdit_3;
  plot_3 = new QHBoxLayout();
  plot_3->setObjectName(QString::fromUtf8("plot_3"));
  verticalLayout_0 = new QVBoxLayout();
  verticalLayout_0->setObjectName(QString::fromUtf8("verticalLayout_0"));
  plot_3->addLayout(verticalLayout_0);
  qwtPlot = new QwtPlot(ui.verticalWidget_bit_plots_2);
  qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
  bit_plots.push_back(qwtPlot);
  verticalLayout_0->addWidget(qwtPlot);
  qwtPlot->enableAxis(QwtPlot::xBottom, false);
  QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  qwtPlot->setSizePolicy(sizePolicy);
  set_Axis(qwtPlot);
  vector<QPointF> tmp_vec;
  bit_points.push_back(tmp_vec);
  bit_points[plot_count - 1].push_back(QPointF(0, 0));
  verticalLayout_9 = new QVBoxLayout();
  verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
  textEdit_2 = new QTextEdit(ui.verticalWidget_bit_plots_2);
  textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
  textEdit_3 = new QTextEdit(ui.verticalWidget_bit_plots_2);
  textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
  QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Expanding);
  sizePolicy7.setHorizontalStretch(0);
  sizePolicy7.setVerticalStretch(0);
  sizePolicy7.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
  textEdit_2->setSizePolicy(sizePolicy7);
  sizePolicy7.setHeightForWidth(textEdit_3->sizePolicy().hasHeightForWidth());
  textEdit_3->setSizePolicy(sizePolicy7);
  verticalLayout_9->addWidget(textEdit_2);
  verticalLayout_9->addWidget(textEdit_3);
  plot_3->addLayout(verticalLayout_9);
  ui.verticalWidget_bit_plots->addLayout(plot_3);
  bit_plot_reg.push_back(textEdit_2);
  bit_plot_bit.push_back(textEdit_3);
}

void MainWindow::Add_Analog_Plot() {
  if(analog_created == 0) {
    analog_created = 1;
    QHBoxLayout *plot_3;
    QwtPlot *qwtPlot;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_0;
    QTextEdit *textEdit_2;
    plot_3 = new QHBoxLayout();
    plot_3->setObjectName(QString::fromUtf8("plot_3"));
    verticalLayout_0 = new QVBoxLayout();
    verticalLayout_0->setObjectName(QString::fromUtf8("verticalLayout_0"));
    plot_3->addLayout(verticalLayout_0);
    /* TBD: remove last plot as it is only to hold the axis */
    qwtPlot = new QwtPlot(ui.verticalWidget_analog);
    qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
    verticalLayout_0->addWidget(qwtPlot);
    qwtPlot->enableAxis(QwtPlot::xBottom, false);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    qwtPlot->setSizePolicy(sizePolicy);
    set_Axis(qwtPlot);
    qwtPlot->setCanvasBackground( Qt::white );
    qwtPlot->setAxisScale( QwtPlot::yLeft, 0, 4096, 1024);
    qwtPlot->setAxisTitle(QwtAxisId(QwtPlot::yLeft), "Analog Port"); // set the title for the second axis
    verticalLayout_9 = new QVBoxLayout();
    verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
    plot_3->addLayout(verticalLayout_9);
    ui.verticalLayout_analog->addLayout(plot_3);
    analog_plot = qwtPlot;
    analog_plot->replot();
  }
}

void MainWindow::Add_ADC_Plot() {
  if(adc_created == 0) {
    adc_created = 1;
    QHBoxLayout *plot_3;
    QwtPlot *qwtPlot;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_0;
    QTextEdit *textEdit_2;
    plot_3 = new QHBoxLayout();
    plot_3->setObjectName(QString::fromUtf8("plot_3"));
    verticalLayout_0 = new QVBoxLayout();
    verticalLayout_0->setObjectName(QString::fromUtf8("verticalLayout_0"));
    plot_3->addLayout(verticalLayout_0);
    /* TBD: remove last plot as it is only to hold the axis */
    qwtPlot = new QwtPlot(ui.verticalWidget_adc);
    qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
    verticalLayout_0->addWidget(qwtPlot);
    qwtPlot->enableAxis(QwtPlot::xBottom, false);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    qwtPlot->setSizePolicy(sizePolicy);
    qwtPlot->setCanvasBackground( Qt::white );
    qwtPlot->setAxisScale( QwtPlot::yLeft, 0, 4096, 1024);
    qwtPlot->setAxisTitle(QwtAxisId(QwtPlot::yLeft), "ADC Result"); // set the title for the second axis
    verticalLayout_9 = new QVBoxLayout();
    verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
    plot_3->addLayout(verticalLayout_9);
    ui.verticalLayout_adc->addLayout(plot_3);
    adc_plot = qwtPlot;
    adc_plot->replot();
  }
}

void MainWindow::Add_Plot() {
  QHBoxLayout *plot_3;
  QwtPlot *qwtPlot;
  QVBoxLayout *verticalLayout_9;
  QVBoxLayout *verticalLayout_0;
  QTextEdit *textEdit_2;
  plot_3 = new QHBoxLayout();
  plot_3->setObjectName(QString::fromUtf8("plot_3"));
  verticalLayout_0 = new QVBoxLayout();
  verticalLayout_0->setObjectName(QString::fromUtf8("verticalLayout_0"));
  plot_3->addLayout(verticalLayout_0);
  /* TBD: remove last plot as it is only to hold the axis */
  for (int i = 0 ; i < 9 ; i ++) {
    qwtPlot = new QwtPlot(ui.verticalWidget_plots);
    qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));
    plots.push_back(qwtPlot);
    verticalLayout_0->addWidget(qwtPlot);
    qwtPlot->enableAxis(QwtPlot::xBottom, false);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    qwtPlot->setSizePolicy(sizePolicy);
    set_Axis(qwtPlot);
    char buf [5];
    sprintf(buf, "%X\t", i);
    if(i != 8) {
      qwtPlot->setAxisTitle(QwtAxisId(QwtPlot::yLeft), buf); // set the title for the second axis
    }
    vector<QPointF> tmp_vec;
    points.push_back(tmp_vec);
    points[i].push_back(QPointF(0, 0));
  }
  verticalLayout_9 = new QVBoxLayout();
  verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
  textEdit_2 = new QTextEdit(ui.verticalWidget_plots);
  textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
  QSizePolicy sizePolicy7(QSizePolicy::Minimum, QSizePolicy::Expanding);
  sizePolicy7.setHorizontalStretch(0);
  sizePolicy7.setVerticalStretch(0);
  sizePolicy7.setHeightForWidth(textEdit_2->sizePolicy().hasHeightForWidth());
  textEdit_2->setSizePolicy(sizePolicy7);
  verticalLayout_9->addWidget(textEdit_2);
  plot_3->addLayout(verticalLayout_9);
  ui.verticalLayout_7->addLayout(plot_3);
  plot_addrs.push_back(textEdit_2);
}

void MainWindow::start_emulator() {
  qDebug() << "\nLOADING DEFAULT FILE : " << filename << "\n";
  priv_code = split_Program_Code(filename.toStdString());
  file_loaded = 1;

  init_Memory(&priv_code, &priv_memory, &priv_bus);
  qDebug() << priv_code.clock_Cycle << "\n";
  parse_Code(&priv_code, &priv_memory);
  decode_Lines(&priv_code, &priv_memory, &priv_bus);
  cout << "PROGRAM MEMORY SIZE : " << priv_memory.program_memory.size() << "\n";

  find_IRQs(&priv_code, &priv_memory);
  find_Last_C_Lines(&priv_code);

  QString prog_str = "";
  for(C_Line &line : priv_code.c_lines) {
    char buf [10];
    prog_str.append(line.line.c_str());
    prog_str.append("\n");
    line.gui_len = prog_str.length();
    printf("LINE %d - GUI LEN %d\n", line.index, line.gui_len);
  }
  ui.text_c->setText(prog_str);

  prog_str = "";
  for(Line &line : priv_code.lines) {
    char buf [10];
    sprintf(buf, "%X\t", line.address);
    prog_str.append(buf);
    sprintf(buf, "%X\t", line.coded_disasm);
    prog_str.append(buf);
    for(string word : line.words) {
    prog_str.append(word.c_str());
    prog_str.append(" ");
    }
    prog_str.append("\n");
    line.gui_len = prog_str.length();
  }
  ui.text_disasm->setText(prog_str);

  QTextCharFormat fmt;
  fmt.setBackground(Qt::yellow);

  QTextCursor cursor(ui.text_disasm->document());
  cursor.setPosition(0, QTextCursor::MoveAnchor);
  cursor.setPosition(priv_code.lines[0].gui_len, QTextCursor::KeepAnchor);
  cursor.setCharFormat(fmt);
  gui_cur_line = 0;
  priv_memory.modules.TMR0_module.acc = 0;
  priv_memory.modules.TMR0_module.post = 0;
  priv_memory.modules.TMR0_module.post_acc = 0;
  priv_memory.modules.TMR0_module.pre = 0;
  priv_memory.modules.TMR0_module.pre_acc = 0;
  priv_memory.modules.TMR0_module.enabled= 0;

  priv_memory.modules.TMR1_module.acc = 0;
  priv_memory.modules.TMR1_module.pre_acc = 0;
  priv_memory.modules.TMR1_module.pre= 0;
  priv_memory.modules.TMR1_module.last_cs_val= 0;
  priv_memory.modules.TMR1_module.enabled= 0;

  priv_memory.modules.ADC_module.last_measured_value = 0;
  priv_memory.modules.ADC_module.nano_clock = 0;
  priv_memory.modules.ADC_module.state = ADC_WAITING;

  for(int i = 0 ; i < 6 ; i++){
    for(int j = 0 ; j < 8 ; j++){
      priv_memory.modules.Ports_module.port_pins[i][j].val = 0;
    }
  }
  priv_memory.modules.IVT_module.context = 0;
  priv_memory.modules.IVT_module.last_context = 0;

  priv_memory.modules.UART_module.bit_counter = 0;
  priv_memory.modules.UART_module.counter = 0;
  priv_memory.modules.UART_module.state = UART_OFF;
  priv_memory.modules.UART_module.port = 0;
  priv_memory.modules.UART_module.port_changed = 0;
  priv_memory.modules.UART_module.transaction_start = 0;
  priv_memory.modules.UART_module.TSR = 0;
  priv_memory.modules.UART_module.port_changed = 0;
  
  priv_memory.Fosc_moment = 0;
}

void MainWindow::myclicked() {
    qDebug() << "AAA";
}

void MainWindow::openFile() {
  //custom behavior
  filename = QFileDialog::getOpenFileName(this, "Select a file to open...", QDir::currentPath());
  qDebug() << "\nLOADING FILE : " << filename << "\n";
}

static string print_encoded(Program_Word tmp_p, Memory * memory, Line * line) {
  WORD_UNION p_word;
  p_word.program_word = tmp_p.program_word;
  char buffer [100];
  int ret;
  string tmp;

  switch(tmp_p.type) {

		case NOP_TYPE:
      ret = sprintf(buffer, "NOP");
			break;
		case BYTE_FILE: 
      ret = sprintf(buffer, "OPCODE %d, D %d, A %d, F %d", p_word.byte.opcode, p_word.byte.d, p_word.byte.a, p_word.byte.f);
			break;
		case BYTE_FILE_NW: 
      ret = sprintf(buffer, "OPCODE %d, A %d, F %d", p_word.byte_nw.opcode, p_word.byte_nw.a, p_word.byte_nw.f);
			break;
		case BIT: 
      ret = sprintf(buffer, "OPCODE %d, B %d, A %d, F %d", p_word.bit.opcode, p_word.bit.b, p_word.bit.a, p_word.bit.f);
			break;
		case INHERENT: 
      ret = sprintf(buffer, "OPCODE %d", p_word.inherent.lsb);
			break;
		case BRA_COND: 
      ret = sprintf(buffer, "OPCODE %d, K %X", p_word.bra_cond.opcode, tmp_p.data);
			break;
		case BRA_UNCOND: 
      ret = sprintf(buffer, "OPCODE %d, K %X", p_word.bra_uncond.opcode, tmp_p.data);
			break;
		case RET: 
      ret = sprintf(buffer, "OPCODE %d, K %d", p_word.ret.opcode, p_word.ret.s);
			break;
		case CALL: 
      ret = sprintf(buffer, "OPCODE %d, K %X", p_word.call.opcode, tmp_p.data);
			break;
		case GOTOI: 
      ret = sprintf(buffer, "OPCODE %d, K %X", p_word.gotoi.opcode, tmp_p.data);
			break;
		case LITERAL:
      ret = sprintf(buffer, "OPCODE %d, K %d", p_word.literal.opcode, p_word.literal.k);
			break;
		case LITERAL_FSR:
      ret = sprintf(buffer, "OPCODE %d, FN %d, K %d", p_word.addl_fsr.opcode, p_word.addl_fsr.f, p_word.addl_fsr.k);
			break;
		case LFSR:
      ret = sprintf(buffer, "OPCODE %d, FN %d, K %X", p_word.lfsr.opcode, p_word.lfsr.fn, memory->program_memory[line->address/2].data);
			break;
    default:
      ret = sprintf(buffer, "");
      break;
  }
  tmp = buffer;
  return tmp;
}

void MainWindow::update_LabelTableFastReturnStack () {
  char buffer [20];
  if(priv_memory.fast_register_stack.size() > 0) {
      /* STATUS, WREG, BSR*/
    for(int i = 0 ; i < 3 ; i++) {
      sprintf(buffer, "0x%X", priv_memory.fast_register_stack[i]); 
      ui.tableWidget_frs->setItem(i, 0,  new QTableWidgetItem(buffer));
    }
  }
  else {
    for(int i = 0 ; i < 3 ; i++) {
      sprintf(buffer, "-"); 
      ui.tableWidget_frs->setItem(i, 0,  new QTableWidgetItem(buffer));
    }
  }
}

void MainWindow::update_LabelTableReturnStack () {
  char buffer [20];

  for(int i = 0 ; i < 8 ; i++) {
    sprintf(buffer, "0x%X", priv_memory.return_stack[i]); 
    ui.return_stack->setItem(i, 0,  new QTableWidgetItem(buffer));
  }
}

void MainWindow::update_LabelTableAdc () {
  char buffer [20];
  /* ADCON0 */
  sprintf(buffer, "%d", priv_memory.data_memory[ADCON0]); 
  ui.tableWidget_adc0->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* T1CON BITS */
  ADCON0_R adcon0_tmp;
  adcon0_tmp.data = priv_memory.data_memory[ADCON0];
  /* ON */
  sprintf(buffer, "%d", adcon0_tmp.ON); 
  ui.tableWidget_adc0->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* CONT */
  sprintf(buffer, "%d", adcon0_tmp.CONT); 
  ui.tableWidget_adc0->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* CS */
  sprintf(buffer, "%d", adcon0_tmp.CS); 
  ui.tableWidget_adc0->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* FM */
  sprintf(buffer, "%d", adcon0_tmp.FM); 
  ui.tableWidget_adc0->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* GO */
  sprintf(buffer, "%d", adcon0_tmp.GO); 
  ui.tableWidget_adc0->setItem(5, 0,  new QTableWidgetItem(buffer));

  /* ADCON1 */
  sprintf(buffer, "%d", priv_memory.data_memory[ADCON1]); 
  ui.tableWidget_adc0->setItem(6, 0,  new QTableWidgetItem(buffer));
  /* ADCON1 BITS */
  ADCON1_R adcon1_tmp;
  adcon1_tmp.data = priv_memory.data_memory[ADCON1];
  /* PPOL */
  sprintf(buffer, "%d", adcon1_tmp.PPOL); 
  ui.tableWidget_adc0->setItem(7, 0,  new QTableWidgetItem(buffer));
  /* IPEN */
  sprintf(buffer, "%d", adcon1_tmp.IPEN); 
  ui.tableWidget_adc0->setItem(8, 0,  new QTableWidgetItem(buffer));
  /* GPOL */
  sprintf(buffer, "%d", adcon1_tmp.GPOL); 
  ui.tableWidget_adc0->setItem(9, 0,  new QTableWidgetItem(buffer));
  /* DSEN */
  sprintf(buffer, "%d", adcon1_tmp.DSEN); 
  ui.tableWidget_adc0->setItem(10, 0,  new QTableWidgetItem(buffer));
  /* ADCON2  */
  sprintf(buffer, "%d", priv_memory.data_memory[ADCON2]); 
  ui.tableWidget_adc0->setItem(11, 0,  new QTableWidgetItem(buffer));
  /* ADCON2 BITS */
  ADCON2_R adcon2_tmp;
  adcon2_tmp.data = priv_memory.data_memory[ADCON2];
  sprintf(buffer, "%d", adcon2_tmp.PSIS); 
  ui.tableWidget_adc0->setItem(12, 0,  new QTableWidgetItem(buffer));
  sprintf(buffer, "%d", adcon2_tmp.CRS); 
  ui.tableWidget_adc0->setItem(13, 0,  new QTableWidgetItem(buffer));
  sprintf(buffer, "%d", adcon2_tmp.ACLR); 
  ui.tableWidget_adc0->setItem(14, 0,  new QTableWidgetItem(buffer));
  sprintf(buffer, "%d", adcon2_tmp.MD); 
  ui.tableWidget_adc0->setItem(15, 0,  new QTableWidgetItem(buffer));

  /* ADCLK */
  sprintf(buffer, "%d", priv_memory.data_memory[ADCLK]); 
  ui.tableWidget_adc1->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* ADPCH */
  sprintf(buffer, "%d", priv_memory.data_memory[ADPCH]); 
  ui.tableWidget_adc1->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* ADPRE */ 
  sprintf(buffer, "%d", priv_memory.data_memory[ADPRE] + 256 * priv_memory.data_memory[ADPRE + 1]); 
  ui.tableWidget_adc1->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* ADACQ */
  sprintf(buffer, "%d", priv_memory.data_memory[ADACQ] + 256 * priv_memory.data_memory[ADACQ + 1]); 
  ui.tableWidget_adc1->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* ADRES */ 
  sprintf(buffer, "%d", priv_memory.data_memory[ADRES] + 256 * priv_memory.data_memory[ADRES + 1]); 
  ui.tableWidget_adc1->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* ADPREV */ 
  sprintf(buffer, "%d", priv_memory.data_memory[ADPREV] + 256 * priv_memory.data_memory[ADPREV + 1]); 
  ui.tableWidget_adc1->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* ADACT */
  sprintf(buffer, "%d", priv_memory.data_memory[ADACT]); 
  ui.tableWidget_adc1->setItem(6, 0,  new QTableWidgetItem(buffer));

  /* ADCON3  */
  sprintf(buffer, "%d", priv_memory.data_memory[ADCON3]); 
  ui.tableWidget_adc1->setItem(7, 0,  new QTableWidgetItem(buffer));
  /* ADCON3 BITS */
  ADCON3_R adcon3_tmp;
  adcon3_tmp.data = priv_memory.data_memory[ADCON3];
  sprintf(buffer, "%d", adcon3_tmp.CALC); 
  ui.tableWidget_adc1->setItem(8, 0,  new QTableWidgetItem(buffer));
  sprintf(buffer, "%d", adcon3_tmp.SOI); 
  ui.tableWidget_adc1->setItem(9, 0,  new QTableWidgetItem(buffer));
  sprintf(buffer, "%d", adcon3_tmp.TMD); 
  ui.tableWidget_adc1->setItem(10, 0,  new QTableWidgetItem(buffer));
}

void MainWindow::update_LabelTableTmr1 () {
  char buffer [20];
  /* T1CON */
  sprintf(buffer, "%d", priv_memory.data_memory[T1CON]); 
  ui.tableWidget_tmr1->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* T1CON BITS */
  T1CON_R t1con_tmp;
  t1con_tmp.data = priv_memory.data_memory[T1CON];
  /* ON */
  sprintf(buffer, "%d", t1con_tmp.ON); 
  ui.tableWidget_tmr1->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* RD16 */
  sprintf(buffer, "%d", t1con_tmp.RD16); 
  ui.tableWidget_tmr1->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* SYNC */
  sprintf(buffer, "%d", t1con_tmp.SYNC); 
  ui.tableWidget_tmr1->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* CKPS */
  sprintf(buffer, "%d", t1con_tmp.CKPS); 
  ui.tableWidget_tmr1->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* T1GCON */
  sprintf(buffer, "%d", priv_memory.data_memory[T1GCON]); 
  ui.tableWidget_tmr1->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* T1GCON BITS */
  T1GCON_R t1gcon_tmp;
  t1gcon_tmp.data = priv_memory.data_memory[T1GCON];
  /* GVAL */
  sprintf(buffer, "%d", t1gcon_tmp.GVAL); 
  ui.tableWidget_tmr1->setItem(6, 0,  new QTableWidgetItem(buffer));
  /* GGO */
  sprintf(buffer, "%d", t1gcon_tmp.GGO); 
  ui.tableWidget_tmr1->setItem(7, 0,  new QTableWidgetItem(buffer));
  /* GSPM */
  sprintf(buffer, "%d", t1gcon_tmp.GSPM); 
  ui.tableWidget_tmr1->setItem(8, 0,  new QTableWidgetItem(buffer));
  /* GTM */
  sprintf(buffer, "%d", t1gcon_tmp.GTM); 
  ui.tableWidget_tmr1->setItem(9, 0,  new QTableWidgetItem(buffer));
  /* GPOL */
  sprintf(buffer, "%d", t1gcon_tmp.GPOL); 
  ui.tableWidget_tmr1->setItem(10, 0,  new QTableWidgetItem(buffer));
  /* GE */
  sprintf(buffer, "%d", t1gcon_tmp.GE); 
  ui.tableWidget_tmr1->setItem(11, 0,  new QTableWidgetItem(buffer));
  /* T1CLK */
  T1CLK_R t1clk_tmp;
  t1clk_tmp.data = priv_memory.data_memory[T1CLK];
  sprintf(buffer, "%d", t1clk_tmp.CS); 
  ui.tableWidget_tmr1->setItem(12, 0,  new QTableWidgetItem(buffer));
  /* T1GATE */
  T1GATE_R t1gate_tmp;
  t1gate_tmp.data = priv_memory.data_memory[T1GATE];
  sprintf(buffer, "%d", t1gate_tmp.GSS); 
  ui.tableWidget_tmr1->setItem(13, 0,  new QTableWidgetItem(buffer));
  /* TMR1 (TMR1L + 256*TMR1H) */
  sprintf(buffer, "%d", priv_memory.data_memory[TMR1L] + priv_memory.data_memory[TMR1L+1] * 256); 
  ui.tableWidget_tmr1->setItem(14, 0,  new QTableWidgetItem(buffer));
  /* ISR ADDR */
  sprintf(buffer, "0x%X", priv_memory.modules.TMR1_module.ivt_address); 
  ui.tableWidget_tmr1->setItem(15, 0,  new QTableWidgetItem(buffer));
}

void MainWindow::update_LabelTableTmr0 () {
  char buffer [20];
  /* T0CON0 */
  sprintf(buffer, "%d", priv_memory.data_memory[T0CON0]); 
  ui.tableWidget_tmr0->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* T0CON0 BITS */
  T0CON0_R t0con0_tmp;
  t0con0_tmp.data = priv_memory.data_memory[T0CON0];
  /* EN */
  sprintf(buffer, "%d", t0con0_tmp.EN); 
  ui.tableWidget_tmr0->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* OUT */
  sprintf(buffer, "%d", t0con0_tmp.OUT); 
  ui.tableWidget_tmr0->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* MD16 */
  sprintf(buffer, "%d", t0con0_tmp.MD16); 
  ui.tableWidget_tmr0->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* OUTPS */
  sprintf(buffer, "%d", t0con0_tmp.OUTPS); 
  ui.tableWidget_tmr0->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* T0CON1 */
  sprintf(buffer, "%d", priv_memory.data_memory[T0CON1]); 
  ui.tableWidget_tmr0->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* T0CON1 BITS */
  T0CON1_R t0con1_tmp;
  t0con1_tmp.data = priv_memory.data_memory[T0CON1];
  /* CS */
  sprintf(buffer, "%d", t0con1_tmp.CS); 
  ui.tableWidget_tmr0->setItem(6, 0,  new QTableWidgetItem(buffer));
  /* ASYNC */
  sprintf(buffer, "%d", t0con1_tmp.ASYNC); 
  ui.tableWidget_tmr0->setItem(7, 0,  new QTableWidgetItem(buffer));
  /* CKPS */
  sprintf(buffer, "%d", t0con1_tmp.CKPS); 
  ui.tableWidget_tmr0->setItem(8, 0,  new QTableWidgetItem(buffer));
  /* TMR0H */
  sprintf(buffer, "%d", priv_memory.data_memory[TMR0H]); 
  ui.tableWidget_tmr0->setItem(9, 0,  new QTableWidgetItem(buffer));
  /* TMR0L */
  sprintf(buffer, "%d", priv_memory.data_memory[TMR0L]); 
  ui.tableWidget_tmr0->setItem(10, 0,  new QTableWidgetItem(buffer));
  /* ISR ADDR */
  sprintf(buffer, "0x%X", priv_memory.modules.TMR0_module.ivt_address); 
  ui.tableWidget_tmr0->setItem(11, 0,  new QTableWidgetItem(buffer));
}

void MainWindow::update_LabelTableInt_Pir () {
  char buffer [20];
  for(int i = 0 ; i < 13 ; i++) {
    sprintf(buffer, "%d", priv_memory.data_memory[PIR0 + i]); 
    ui.tableWidget_pir->setItem(i, 0,  new QTableWidgetItem(buffer));
    sprintf(buffer, "%d", priv_memory.data_memory[PIE0 + i]); 
    ui.tableWidget_pir->setItem(i, 1,  new QTableWidgetItem(buffer));
    sprintf(buffer, "%d", priv_memory.data_memory[IPR0 + i]); 
    ui.tableWidget_pir->setItem(i, 2,  new QTableWidgetItem(buffer));
  }
}

void MainWindow::update_LabelTableInt () {
  char buffer [20];
  /* INTCON0 */
  sprintf(buffer, "%d", priv_memory.data_memory[INTCON0]); 
  ui.tableWidget_int->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* STATUS BITS */
  INTCON0_R intcon0_tmp;
  intcon0_tmp.data = priv_memory.data_memory[INTCON0];
  /* GIEH */
  sprintf(buffer, "%d", intcon0_tmp.GIEGIEH); 
  ui.tableWidget_int->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* GIEL */
  sprintf(buffer, "%d", intcon0_tmp.GIEL); 
  ui.tableWidget_int->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* IPEN */
  sprintf(buffer, "%d", intcon0_tmp.IPEN); 
  ui.tableWidget_int->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* INT2EDG */
  sprintf(buffer, "%d", intcon0_tmp.INT2EDG); 
  ui.tableWidget_int->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* INT1EDG */
  sprintf(buffer, "%d", intcon0_tmp.INT1EDG); 
  ui.tableWidget_int->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* INT0EDG */ 
  sprintf(buffer, "%d", intcon0_tmp.INT0EDG); 
  ui.tableWidget_int->setItem(6, 0,  new QTableWidgetItem(buffer));
  /* INTCON1 */
  sprintf(buffer, "%d", priv_memory.data_memory[INTCON1]); 
  ui.tableWidget_int->setItem(7, 0,  new QTableWidgetItem(buffer));
  INTCON1_R intcon1_tmp;
  intcon1_tmp.data = priv_memory.data_memory[INTCON1];
  /* STAT */
  sprintf(buffer, "%d", intcon1_tmp.STAT); 
  ui.tableWidget_int->setItem(8, 0,  new QTableWidgetItem(buffer));
  /* IVTAD */
  sprintf(buffer, "%d", priv_memory.modules.IVT_module.current_isr_addr); 
  ui.tableWidget_int->setItem(9, 0,  new QTableWidgetItem(buffer));
}

void MainWindow::update_LabelTableUart () {
  char buffer [20];
  /* U1CON0 */
  sprintf(buffer, "%d", priv_memory.data_memory[U1CON0]); 
  ui.tableWidget_uart_0->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* U1CON0 BITS */
  U1CON0_R u1con0_tmp;
  u1con0_tmp.data = priv_memory.data_memory[U1CON0];
  /* BRGS */
  sprintf(buffer, "%d", u1con0_tmp.BRGS); 
  ui.tableWidget_uart_0->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* ABDEN */
  sprintf(buffer, "%d", u1con0_tmp.ABDEN); 
  ui.tableWidget_uart_0->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* TXEN */
  sprintf(buffer, "%d", u1con0_tmp.TXEN); 
  ui.tableWidget_uart_0->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* RXEN */
  sprintf(buffer, "%d", u1con0_tmp.RXEN); 
  ui.tableWidget_uart_0->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* MODE */
  sprintf(buffer, "%d", u1con0_tmp.MODE); 
  ui.tableWidget_uart_0->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* U1CON1 */
  sprintf(buffer, "%d", priv_memory.data_memory[U1CON1]); 
  ui.tableWidget_uart_0->setItem(6, 0,  new QTableWidgetItem(buffer));
  /* U1CON1 BITS */
  U1CON1_R u1con1_tmp;
  u1con1_tmp.data = priv_memory.data_memory[U1CON1];
  /* ON */
  sprintf(buffer, "%d", u1con1_tmp.ON); 
  ui.tableWidget_uart_0->setItem(7, 0,  new QTableWidgetItem(buffer));
  /* WUE */
  sprintf(buffer, "%d", u1con1_tmp.WUE); 
  ui.tableWidget_uart_0->setItem(8, 0,  new QTableWidgetItem(buffer));
  /* RXBIMD */
  sprintf(buffer, "%d", u1con1_tmp.RXBIMD); 
  ui.tableWidget_uart_0->setItem(9, 0,  new QTableWidgetItem(buffer));
  /* BRKOVR */
  sprintf(buffer, "%d", u1con1_tmp.BRKOVR); 
  ui.tableWidget_uart_0->setItem(10, 0,  new QTableWidgetItem(buffer));
  /* SENDB */
  sprintf(buffer, "%d", u1con1_tmp.SENDB); 
  ui.tableWidget_uart_0->setItem(11, 0,  new QTableWidgetItem(buffer));
  /* U1BRG */
  sprintf(buffer, "%d", priv_memory.data_memory[U1BRG + 1] * 0x100 + priv_memory.data_memory[U1BRG]); 
  ui.tableWidget_uart_0->setItem(12, 0,  new QTableWidgetItem(buffer));
  /* U1RXB */
  sprintf(buffer, "%d", priv_memory.data_memory[U1RXB]); 
  ui.tableWidget_uart_0->setItem(13, 0,  new QTableWidgetItem(buffer));
  /* U1TXB */
  sprintf(buffer, "%d", priv_memory.data_memory[U1TXB]); 
  ui.tableWidget_uart_0->setItem(14, 0,  new QTableWidgetItem(buffer));

  /* UART_1 TABLE */
  /* U1CON2 */
  sprintf(buffer, "%d", priv_memory.data_memory[U1CON2]); 
  ui.tableWidget_uart_1->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* U1CON0 BITS */
  U1CON2_R u1con2_tmp;
  u1con2_tmp.data = priv_memory.data_memory[U1CON2];
  /* RUNOVF */
  sprintf(buffer, "%d", u1con2_tmp.RUNOVF); 
  ui.tableWidget_uart_1->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* RXPOL */
  sprintf(buffer, "%d", u1con2_tmp.RXPOL); 
  ui.tableWidget_uart_1->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* STP */
  sprintf(buffer, "%d", u1con2_tmp.STP); 
  ui.tableWidget_uart_1->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* C0EN */
  sprintf(buffer, "%d", u1con2_tmp.C0EN); 
  ui.tableWidget_uart_1->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* TXPOL */
  sprintf(buffer, "%d", u1con2_tmp.TXPOL); 
  ui.tableWidget_uart_1->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* FLO */
  sprintf(buffer, "%d", u1con2_tmp.FLO); 
  ui.tableWidget_uart_1->setItem(6, 0,  new QTableWidgetItem(buffer));

  /* FIFO */
  sprintf(buffer, "%d", priv_memory.data_memory[U1FIFO]); 
  ui.tableWidget_uart_1->setItem(7, 0,  new QTableWidgetItem(buffer));
  /* FIFO BITS */
  U1FIFO_R u1fifo_tmp;
  u1fifo_tmp.data = priv_memory.data_memory[U1FIFO];
  /* TXWRE */
  sprintf(buffer, "%d", u1fifo_tmp.TXWRE); 
  ui.tableWidget_uart_1->setItem(8, 0,  new QTableWidgetItem(buffer));
  /* STMPD */
  sprintf(buffer, "%d", u1fifo_tmp.STMPD); 
  ui.tableWidget_uart_1->setItem(9, 0,  new QTableWidgetItem(buffer));
  /* TXBE */
  sprintf(buffer, "%d", u1fifo_tmp.TXBE); 
  ui.tableWidget_uart_1->setItem(10, 0,  new QTableWidgetItem(buffer));
  /* TXBF */
  sprintf(buffer, "%d", u1fifo_tmp.TXBF); 
  ui.tableWidget_uart_1->setItem(11, 0,  new QTableWidgetItem(buffer));
  /* RXIDL */
  sprintf(buffer, "%d", u1fifo_tmp.RXIDL); 
  ui.tableWidget_uart_1->setItem(12, 0,  new QTableWidgetItem(buffer));
  /* XON */
  sprintf(buffer, "%d", u1fifo_tmp.XON); 
  ui.tableWidget_uart_1->setItem(13, 0,  new QTableWidgetItem(buffer));
  /* RXBE */
  sprintf(buffer, "%d", u1fifo_tmp.RXBE); 
  ui.tableWidget_uart_1->setItem(14, 0,  new QTableWidgetItem(buffer));
  /* RXBF */
  sprintf(buffer, "%d", u1fifo_tmp.RXBF); 
  ui.tableWidget_uart_1->setItem(15, 0,  new QTableWidgetItem(buffer));

}

void MainWindow::update_LabelTableCpu () {
  char buffer [20];
  /* WREG */
  sprintf(buffer, "%d", priv_memory.data_memory[WREG]); 
  ui.tableWidget_cpu->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* STATUS BITS */
  STATUS_R tmp_status;
  tmp_status.reg = priv_memory.data_memory[STATUS];
  /* N */
  sprintf(buffer, "%d", tmp_status.N); 
  ui.tableWidget_cpu->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* OV */
  sprintf(buffer, "%d", tmp_status.OV); 
  ui.tableWidget_cpu->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* Z */
  sprintf(buffer, "%d", tmp_status.Z); 
  ui.tableWidget_cpu->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* DC */
  sprintf(buffer, "%d", tmp_status.DC); 
  ui.tableWidget_cpu->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* C */
  sprintf(buffer, "%d", tmp_status.C); 
  ui.tableWidget_cpu->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* BSR */ 
  sprintf(buffer, "0x%X", priv_memory.data_memory[BSR]); 
  ui.tableWidget_cpu->setItem(6, 0,  new QTableWidgetItem(buffer));
  /* TOS */
  sprintf(buffer, "0x%X", priv_memory.return_stack[priv_memory.data_memory[STKPTR]]); 
  ui.tableWidget_cpu->setItem(7, 0,  new QTableWidgetItem(buffer));
  /* STKPTR */
  sprintf(buffer, "%d", priv_memory.data_memory[STKPTR]); 
  ui.tableWidget_cpu->setItem(8, 0,  new QTableWidgetItem(buffer));

  /* FSR0 */ 
  sprintf(buffer, "0x%.4X", priv_memory.data_memory[FSR0] + 256 * priv_memory.data_memory[FSR0 + 1]); 
  ui.tableWidget_ind_stack->setItem(0, 0,  new QTableWidgetItem(buffer));
  /* FSR1 */ 
  sprintf(buffer, "0x%.4X", priv_memory.data_memory[FSR1] + 256 * priv_memory.data_memory[FSR1 + 1]); 
  ui.tableWidget_ind_stack->setItem(1, 0,  new QTableWidgetItem(buffer));
  /* FSR2 */ 
  sprintf(buffer, "0x%.4X", priv_memory.data_memory[FSR2] + 256 * priv_memory.data_memory[FSR2 + 1]); 
  ui.tableWidget_ind_stack->setItem(2, 0,  new QTableWidgetItem(buffer));
  /* INDF0 */
  sprintf(buffer, "%d", priv_memory.data_memory[INDF0]); 
  ui.tableWidget_ind_stack->setItem(3, 0,  new QTableWidgetItem(buffer));
  /* INDF1 */
  sprintf(buffer, "%d", priv_memory.data_memory[INDF1]); 
  ui.tableWidget_ind_stack->setItem(4, 0,  new QTableWidgetItem(buffer));
  /* INDF2 */
  sprintf(buffer, "%d", priv_memory.data_memory[INDF2]); 
  ui.tableWidget_ind_stack->setItem(5, 0,  new QTableWidgetItem(buffer));
  /* TOSU */
  sprintf(buffer, "%d", priv_memory.data_memory[TOS + 2]); 
  ui.tableWidget_ind_stack->setItem(6, 0,  new QTableWidgetItem(buffer));
  sprintf(buffer, "%d", priv_memory.data_memory[TOS + 1]); 
  ui.tableWidget_ind_stack->setItem(7, 0,  new QTableWidgetItem(buffer));
  sprintf(buffer, "%d", priv_memory.data_memory[TOS + 0]); 
  ui.tableWidget_ind_stack->setItem(8, 0,  new QTableWidgetItem(buffer));
}

void MainWindow::update_LabelTablePorts () {
  char buffer [20];

  for(int i = 0 ; i < 6 ; i++) {
    sprintf(buffer, "0x%.2X", priv_memory.data_memory[PORTA + i]); 
    ui.tableWidget_ports0->setItem(i, 0,  new QTableWidgetItem(buffer));
    sprintf(buffer, "0x%.2X", priv_memory.data_memory[TRISA + i]); 
    ui.tableWidget_ports0->setItem(6 + i, 0,  new QTableWidgetItem(buffer));
    sprintf(buffer, "0x%.2X", priv_memory.data_memory[LATA + i]); 
    ui.tableWidget_ports1->setItem(i, 0,  new QTableWidgetItem(buffer));
    sprintf(buffer, "0x%.2X", priv_memory.data_memory[ANSELA + i * 8]); 
    ui.tableWidget_ports1->setItem(6 + i, 0,  new QTableWidgetItem(buffer));
  }
}

void MainWindow::update_LabelTableInstr () {
  Program_Word tmp_p;
  WORD_UNION tmp;
  QString tmp_qstr;
  char buffer [100];
  tmp_p = priv_memory.instruction_register;
  tmp.program_word = tmp_p.program_word;

  /* Program counter */
  sprintf(buffer, "0x%X", priv_memory.program_counter.DATA);
  ui.tableWidget_instr->setItem(0, 0,  new QTableWidgetItem(buffer));

  /* Executed instruction */
  sprintf(buffer, "%s %s", priv_code.lines[tmp_p.index].words[0].c_str(), 
          print_encoded(tmp_p, &priv_memory, &priv_code.lines[tmp_p.index]).c_str());
  ui.tableWidget_instr->setItem(1, 0,  new QTableWidgetItem(buffer));

  /* Next instruction */
  sprintf(buffer, "%s %s", priv_code.lines[priv_bus.instruction_Bus.index].words[0].c_str(), 
          print_encoded(priv_bus.instruction_Bus, &priv_memory, &priv_code.lines[priv_bus.instruction_Bus.index]).c_str());
  ui.tableWidget_instr->setItem(2, 0,  new QTableWidgetItem(buffer));
}

void MainWindow::update_Table () {
  ui.tableWidget->clear();
  for(int i = 0 ; i < 16 ; i++) {
    char str[10];
    sprintf(str, "%X", i);
    ui.tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(str));
    sprintf(str, "0x%X", 0x460 + i*0x10);
    ui.tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(str));

    for(int j = 0; j < 16 ; j++) {
        sprintf(str, "%X ", priv_memory.data_memory[i*0x10 + j + 0x0460]);
        ui.tableWidget->setItem(i, j,  new QTableWidgetItem(str));
    }
    sprintf(str, "%X", i);
    ui.bank_select_table->setHorizontalHeaderItem(i, new QTableWidgetItem(str));
    sprintf(str, "0x%X", 0x100 * bank_selected + i*0x10);
    ui.bank_select_table->setVerticalHeaderItem(i, new QTableWidgetItem(str));

    for(int j = 0; j < 16 ; j++) {
        sprintf(str, "%X ", priv_memory.data_memory[i*0x10 + j + 0x100 * bank_selected]);
        ui.bank_select_table->setItem(i, j,  new QTableWidgetItem(str));
    }
  }
}

void MainWindow::change_Bank_Selected () {
  if(file_loaded) {
    bool ok;
    bank_selected = ui.te_set_bank->toPlainText().toUInt(&ok, 10);
    update_Table();
  }
}

void MainWindow::c_line_Highlight () {
  /* TEST */
  printf("LAST C LINE INDEX == %d\n", priv_code.lines[gui_cur_line].last_c_index);
  printf("C LINE POS == %d\n", priv_code.c_lines[priv_code.lines[gui_cur_line].last_c_index].gui_len);
  QTextCharFormat fmt;
  fmt.setBackground(Qt::white);
  QTextCursor cursor(ui.text_c->document());
  /* Clear the background */
  cursor.setPosition(0, QTextCursor::MoveAnchor);
  cursor.setPosition(priv_code.c_lines[priv_code.c_lines.size()-1].gui_len, QTextCursor::KeepAnchor);
  cursor.setCharFormat(fmt);
  /* Set the current line to yellow */
  fmt.setBackground(Qt::yellow);
  if(gui_cur_line == 0) {
    cursor.setPosition(0, QTextCursor::MoveAnchor);
    cursor.setPosition(priv_code.c_lines[priv_code.lines[gui_cur_line].last_c_index].gui_len, QTextCursor::MoveAnchor);
  }
  else {
    cursor.setPosition(priv_code.c_lines[priv_code.lines[gui_cur_line].last_c_index-1].gui_len, QTextCursor::MoveAnchor);
    cursor.setPosition(priv_code.c_lines[priv_code.lines[gui_cur_line].last_c_index].gui_len-1, QTextCursor::KeepAnchor);
  }
  cursor.setCharFormat(fmt);
  ui.text_c->setTextCursor(cursor);
}

void MainWindow::disasm_Highlight () {
  /* TEST */
  QTextCharFormat fmt;
  fmt.setBackground(Qt::white);
  QTextCursor cursor(ui.text_disasm->document());
  /* Clear the background */
  cursor.setPosition(0, QTextCursor::MoveAnchor);
  cursor.setPosition(priv_code.lines[priv_code.lines.size()-1].gui_len, QTextCursor::KeepAnchor);
  cursor.setCharFormat(fmt);
  /* Set the current line to yellow */
  fmt.setBackground(Qt::yellow);
  if(gui_cur_line == 0) {
    cursor.setPosition(0, QTextCursor::MoveAnchor);
    cursor.setPosition(priv_code.lines[gui_cur_line].gui_len, QTextCursor::KeepAnchor);
  }
  else {
    cursor.setPosition(priv_code.lines[gui_cur_line-1].gui_len, QTextCursor::MoveAnchor);
    cursor.setPosition(priv_code.lines[gui_cur_line].gui_len-1, QTextCursor::KeepAnchor);
  }
  cursor.setCharFormat(fmt);
  ui.text_disasm->setTextCursor(cursor);
}

void MainWindow::update_PlotsInv() {
  int text_ind = 0;
  for(QTextEdit * edit : plot_addrs) {
    for(int i = 0 ; i < 8 ; i++) {
      int index = (text_ind * 8) + i;
      QwtPlot * plot = plots[index];
      bool ok;
      u8 test = priv_memory.data_memory[plot_addrs[text_ind]->toPlainText().toUInt(&ok, 16)] & (1 << i);
      if(test) {
        if(points[index].back().y() == 0)
          points[index].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano, 1));
        points[index].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 1));
      }
      else { 
        if(points[index].back().y() == 1)
          points[index].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano, 0));
        points[index].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 0));
      }
    }
    text_ind++;
  }
}

void MainWindow::update_Analog_PlotsInv() {
  if(analog_created) {
    analog_points.push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, current_analog_val));
  }

  if(adc_created) {
    adc_points.push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, priv_memory.data_memory[ADRES+1] * 0x100 + priv_memory.data_memory[ADRES]));
  }
}

void MainWindow::update_Analog_Plots() {
  if(analog_created) {
    analog_points.push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, current_analog_val));
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setTitle( "Pixel Count" );
    curve->setPen( Qt::blue, 2 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QPolygonF polygon;
    for(QPointF point : analog_points) {
      polygon << point;
    }
    curve->setSamples( polygon );
    curve->attach( analog_plot );
    analog_plot->replot();
  }

  if(adc_created) {
    adc_points.push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, priv_memory.data_memory[ADRES+1] * 0x100 + priv_memory.data_memory[ADRES]));
    QwtPlotCurve *curve_2 = new QwtPlotCurve();
    curve_2->setTitle( "Pixel Count" );
    curve_2->setPen( Qt::blue, 2 ),
    curve_2->setRenderHint( QwtPlotItem::RenderAntialiased, true );

    QPolygonF polygon2;
    for(QPointF point : adc_points) {
      polygon2 << point;
    }
    curve_2->setSamples( polygon2 );
    curve_2->attach( adc_plot );
    adc_plot->replot();
  }
}

void MainWindow::update_Plots() {
  int text_ind = 0;
  for(QTextEdit * edit : plot_addrs) {
    for(int i = 0 ; i < 8 ; i++) {
      int index = (text_ind * 8) + i;
      QwtPlot * plot = plots[index];
      bool ok;
      u8 test = priv_memory.data_memory[plot_addrs[text_ind]->toPlainText().toUInt(&ok, 16)] & (1 << i);
      if(test) {
        if(points[index].back().y() == 0)
          points[index].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano, 1));
        points[index].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 1));
      }
      else { 
        if(points[index].back().y() == 1)
          points[index].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano - 1, 0));
        points[index].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 0));
      }
    }
    text_ind++;
  }

  printf("AAAAAAAAAAAAAAAA\n");
  int i = 0;
  for(QwtPlot * plot : plots) {

    if(i == plots.size() - 1) {
      plot->enableAxis(QwtPlot::xBottom, true);
      plot->setAxisScale( QwtPlot::xBottom, reset_plot_value, priv_memory.Fosc_period_nano * priv_memory.Fosc_moment);
      plot->setAxisScale( QwtPlot::yLeft, 0, 1, 1);
    }
    QwtPlotCurve *curve = new QwtPlotCurve();
    curve->setTitle( "Pixel Count" );
    curve->setPen( Qt::blue, 2 ),
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
  
    QPolygonF polygon;
    for(QPointF point : points[i]) {
      polygon << point;
    }
    curve->setSamples( polygon );
    curve->attach( plot );
    plot->replot();
    i++;
  }
}

void MainWindow::update_Bit_PlotsInv() {
  int text_ind = 0;
  int i = 0;

  for(QTextEdit * edit : bit_plot_reg) {
      QwtPlot * plot = bit_plots[text_ind];
      bool ok;
      bool ok2;
      u8 test = priv_memory.data_memory[bit_plot_reg[text_ind]->toPlainText().toUInt(&ok, 16)] & (1 << bit_plot_bit[text_ind]->toPlainText().toUInt(&ok2, 16));
      if(test) {
        if(bit_points[text_ind].back().y() == 0)
          bit_points[text_ind].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano, 1));
        bit_points[text_ind].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 1));
      }
      else { 
        if(bit_points[text_ind].back().y() == 1)
          bit_points[text_ind].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano, 0));
        bit_points[text_ind].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 0));
      }
    text_ind++;
  }
}

void MainWindow::update_Bit_Plots() {
  int text_ind = 0;
  int i = 0;
  bool ok;
  bool ok2;
  u8 test;

  if(bit_plot_reg.size() > 0) {
    QwtPlot * plot = bit_plots[text_ind];
    for(QTextEdit * edit : bit_plot_reg) {
        plot = bit_plots[text_ind];
        test = priv_memory.data_memory[bit_plot_reg[text_ind]->toPlainText().toUInt(&ok, 16)] & (1 << bit_plot_bit[text_ind]->toPlainText().toUInt(&ok2, 16));
        if(test) {
          if(bit_points[text_ind].back().y() == 0)
            bit_points[text_ind].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano, 1));
          bit_points[text_ind].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 1));
        }
        else { 
          if(bit_points[text_ind].back().y() == 1)
            bit_points[text_ind].push_back(QPointF((priv_memory.Fosc_moment-4) * priv_memory.Fosc_period_nano, 0));
          bit_points[text_ind].push_back(QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 0));
        }
      text_ind++;
    }

  printf("SIZE OF VECTOR BIT PLOT REG : %ld\n", bit_plot_reg.size());
  printf("SIZE OF VECTOR BIT PLOT BIT : %ld\n", bit_plot_bit.size());
  printf("SIZE OF VECTOR BIT PLOTS : %ld\n", bit_plots.size());
  printf("TU SIE PROGRAM WYWALA\n");
  bit_plot_axis->enableAxis(QwtPlot::xBottom, true);
  bit_plot_axis->setAxisScale( QwtPlot::xBottom, reset_plot_value, priv_memory.Fosc_period_nano * priv_memory.Fosc_moment);
  bit_plot_axis->setAxisScale( QwtPlot::yLeft, 0, 1, 1);
  bit_plot_axis->replot();
  printf("TU SIE PROGRAM WYWALA\n");

    for(QwtPlot * plot : bit_plots) {

      QwtPlotCurve *curve = new QwtPlotCurve();
      curve->setTitle( "Pixel Count" );
      curve->setPen( Qt::blue, 2 ),
      curve->setRenderHint( QwtPlotItem::RenderAntialiased, true );
    
      QPolygonF polygon;
      for(QPointF point : bit_points[i]) {
        polygon << point;
      }
      curve->setSamples( polygon );
      curve->attach( plot );
      plot->replot();
      i++;
    }
  }
}

void MainWindow::update_Labels() {
  /* Update label 1 */
  update_LabelTableInstr();
  update_LabelTableCpu();
  update_LabelTableInt();
  update_LabelTableInt_Pir();
  update_LabelTableTmr0();
  update_LabelTableTmr1();
  update_LabelTableAdc();
  update_LabelTableUart();
  update_LabelTablePorts();
  update_LabelTableReturnStack();
  update_LabelTableFastReturnStack();
  update_Plots();
  update_Analog_Plots();
  update_Bit_Plots();

  update_Table();

  disasm_Highlight();
  c_line_Highlight();
}

static void run_modules(Memory * memory, Bus * bus, int clock) {
  module_tmr0(memory, bus, clock);
  module_tmr1(memory, bus, clock);
  module_adc(memory, bus, clock);
  module_uart(memory, bus, clock);
}

bool test_vector(vector<int> x, int key) {
    if (std::count(x.begin(), x.end(), key)) {
      return true;
    }
    else {
      return false;
    }
};

void MainWindow::RunUntilLine() {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG
  if(file_loaded) {
    bool ok;
    int line_index = ui.textEdit_line_break_addr->toPlainText().toInt(&ok, 10);

    vector<int> c_line_ind;
    for(int i = 0 ; i < priv_code.length ; i++) {
      c_line_ind.push_back(priv_code.lines[i].last_c_index);
    }

    if(line_index > *max_element(c_line_ind.begin(), c_line_ind.end())) {
      line_index = *max_element(c_line_ind.begin(), c_line_ind.end());
    };

    while(!test_vector(c_line_ind, line_index)){
      line_index++;
    }

    printf("LAST C LINE : %d, INPUT LINE INDEX : %d\n",priv_code.lines[priv_bus.instruction_Bus.index].last_c_index, line_index); 
    //priv_code.lines[gui_cur_line].last_c_index
    while(priv_code.lines[gui_cur_line].last_c_index != line_index) {
      gui_cur_line = priv_bus.instruction_Bus.index;
      qDebug() << "CURR LINE : " << gui_cur_line << "\n";

      pre_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);

        module_interrupt(&priv_memory, &priv_bus, &priv_code, priv_code.clock_Cycle);
      for(int i = 0 ; i < 4 ; i++) {
        fetch_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
        execute_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
        run_modules(&priv_memory, &priv_bus, priv_code.clock_Cycle);
        module_ports();
        priv_code.clock_Cycle++;
        priv_memory.Fosc_moment++;
        if(priv_code.clock_Cycle == 4) {
            printf("INTERRUPT NUMBER = %d\n", priv_memory.modules.IVT_module.context);
            priv_code.clock_Cycle = 0;
            qDebug() << "---------------------------------------------------------\n";
            print_coded_instr(&priv_code, &priv_memory, &priv_bus);
        }
      }

      post_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);
      priv_memory.time_moment++;
      update_PlotsInv();
      update_Analog_PlotsInv();
      update_Bit_PlotsInv();
    }
    update_Labels();
  }
}

void MainWindow::RunUntilTime() {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG
  // Check for breakpoints
  if(file_loaded) {
    bool ok;
    vector<int> breakpoints;
    vector<int> c_breakpoints;
    int tmp_line_index;

    vector<int> c_line_ind;
    for(int i = 0 ; i < priv_code.length ; i++) {
      c_line_ind.push_back(priv_code.lines[i].last_c_index);
    }

    if(!ui.textEdit_breakpoint_c0->document()->isEmpty()) {
      tmp_line_index = ui.textEdit_breakpoint_c0->toPlainText().toInt(&ok, 10);

      if(tmp_line_index > *max_element(c_line_ind.begin(), c_line_ind.end())) {
        tmp_line_index = *max_element(c_line_ind.begin(), c_line_ind.end());
      };

      while(!test_vector(c_line_ind, tmp_line_index)){
        tmp_line_index++;
      }
      c_breakpoints.push_back(tmp_line_index);
    }
    if(!ui.textEdit_breakpoint_c1->document()->isEmpty()) {
      tmp_line_index = ui.textEdit_breakpoint_c1->toPlainText().toInt(&ok, 10);

      if(tmp_line_index > *max_element(c_line_ind.begin(), c_line_ind.end())) {
        tmp_line_index = *max_element(c_line_ind.begin(), c_line_ind.end());
      };

      while(!test_vector(c_line_ind, tmp_line_index)){
        tmp_line_index++;
      }
      c_breakpoints.push_back(tmp_line_index);
    }
    if(!ui.textEdit_breakpoint_c2->document()->isEmpty()) {
      tmp_line_index = ui.textEdit_breakpoint_c2->toPlainText().toInt(&ok, 10);

      if(tmp_line_index > *max_element(c_line_ind.begin(), c_line_ind.end())) {
        tmp_line_index = *max_element(c_line_ind.begin(), c_line_ind.end());
      };

      while(!test_vector(c_line_ind, tmp_line_index)){
        tmp_line_index++;
      }
      c_breakpoints.push_back(tmp_line_index);
    }


    if(!ui.textEdit_breakpoint_0->document()->isEmpty()) {
      breakpoints.push_back(ui.textEdit_breakpoint_0->toPlainText().toInt(&ok, 16));
    }
    if(!ui.textEdit_breakpoint_1->document()->isEmpty()) {
      breakpoints.push_back(ui.textEdit_breakpoint_1->toPlainText().toInt(&ok, 16));
    }
    if(!ui.textEdit_breakpoint_2->document()->isEmpty()) {
      breakpoints.push_back(ui.textEdit_breakpoint_2->toPlainText().toInt(&ok, 16));
    }

    int time = ui.textEdit_ms->toPlainText().toInt(&ok, 10);
    while(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano < time * 1e6 && 
          !test_vector(breakpoints, priv_bus.instruction_Bus.address) &&
          !test_vector(c_breakpoints, priv_code.lines[gui_cur_line].last_c_index)) {
      gui_cur_line = priv_bus.instruction_Bus.index;
      qDebug() << "CURR LINE : " << gui_cur_line << "\n";

      pre_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);

        module_interrupt(&priv_memory, &priv_bus, &priv_code, priv_code.clock_Cycle);
      for(int i = 0 ; i < 4 ; i++) {
        fetch_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
        execute_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
        run_modules(&priv_memory, &priv_bus, priv_code.clock_Cycle);
        module_ports();
        priv_code.clock_Cycle++;
        priv_memory.Fosc_moment++;
        if(priv_code.clock_Cycle == 4) {
            printf("INTERRUPT NUMBER = %d\n", priv_memory.modules.IVT_module.context);
            priv_code.clock_Cycle = 0;
            qDebug() << "---------------------------------------------------------\n";
            print_coded_instr(&priv_code, &priv_memory, &priv_bus);
        }
      }

      post_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);
      priv_memory.time_moment++;
      update_PlotsInv();
      update_Analog_PlotsInv();
      update_Bit_PlotsInv();
    }
    update_Labels();
    printf("BREAKPOINTS COUNT : %ld\n", c_breakpoints.size());
  }
}

void MainWindow::RunUntilAddr() {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG
  if(file_loaded) {
    bool ok;
    int addr = ui.textEdit_addr_break_addr->toPlainText().toInt(&ok, 16);
    while(priv_bus.instruction_Bus.address != addr) {
      gui_cur_line = priv_bus.instruction_Bus.index;
      qDebug() << "CURR LINE : " << gui_cur_line << "\n";

      pre_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);

        module_interrupt(&priv_memory, &priv_bus, &priv_code, priv_code.clock_Cycle);
      for(int i = 0 ; i < 4 ; i++) {
        fetch_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
        execute_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
        run_modules(&priv_memory, &priv_bus, priv_code.clock_Cycle);
        module_ports();
        priv_code.clock_Cycle++;
        priv_memory.Fosc_moment++;
        if(priv_code.clock_Cycle == 4) {
            printf("INTERRUPT NUMBER = %d\n", priv_memory.modules.IVT_module.context);
            priv_code.clock_Cycle = 0;
            qDebug() << "---------------------------------------------------------\n";
            print_coded_instr(&priv_code, &priv_memory, &priv_bus);
        }
      }

      post_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);
      priv_memory.time_moment++;
      update_PlotsInv();
      update_Analog_PlotsInv();
      update_Bit_PlotsInv();
    }
    update_Labels();
  }
}

void MainWindow::machine_State_Step() {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG
  if(file_loaded) {
    gui_cur_line = priv_bus.instruction_Bus.index;
    qDebug() << "CURR LINE : " << gui_cur_line << "\n";

    pre_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);

      module_interrupt(&priv_memory, &priv_bus, &priv_code, priv_code.clock_Cycle);
    for(int i = 0 ; i < 4 ; i++) {
      fetch_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
      execute_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
      run_modules(&priv_memory, &priv_bus, priv_code.clock_Cycle);
      module_ports();
      priv_code.clock_Cycle++;
      priv_memory.Fosc_moment++;
      if(priv_code.clock_Cycle == 4) {
          printf("INTERRUPT NUMBER = %d\n", priv_memory.modules.IVT_module.context);
          priv_code.clock_Cycle = 0;
          qDebug() << "---------------------------------------------------------\n";
          print_coded_instr(&priv_code, &priv_memory, &priv_bus);
      }
    }

    post_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);
    update_Labels();
    priv_memory.time_moment++;
  }
}


void MainWindow::clear_plots() {

  if(file_loaded) {

    if(points.size() > 0)
    for(int i = 0 ; i < points.size() - 1 ; i++) {
      /* points[i] = {QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 0)}; */
      points[i] = {};
      plots[i]->detachItems();
      if(points.size() > 7) {
        plots[8]->detachItems();
      }
    }

    if(analog_created) {
      analog_points = {};
      analog_plot->detachItems();
    }

    if(adc_created) {
      adc_points = {};
      adc_plot->detachItems();
    }

    if(bit_points.size() > 0)
    for(int i = 0 ; i < bit_points.size() ; i++) {
      /* bit_points[i] = {QPointF(priv_memory.Fosc_moment * priv_memory.Fosc_period_nano, 0)}; */
      bit_points[i] = {};
      bit_plots[i]->detachItems();
    }
    if(plot_count > 0)
      plot_count = 1;
    reset_plot_value = priv_memory.Fosc_moment * priv_memory.Fosc_period_nano;

    
    /* bit_plot_axis->detachItems(); */
    /* delete ui.verticalWidget_bit_plots->widget(); */
    /* delete ui.verticalWidget_bit_time->widget(); */
    /* ui.verticalWidget_bit_time->update(); */
    /* ui.verticalWidget_bit_plots->update(); */
    /* ui.verticalWidget_plots->update(); */
    /* delete ui.verticalLayout_7->widget(); */
    /* ui.verticalLayout_7->update(); */
    /* ui.verticalWidget_bit_plots_2->update(); */
    update_Labels();
  }
}


void MainWindow::reset() {

  if(file_loaded) {
    reset_plot_value = priv_memory.Fosc_moment * priv_memory.Fosc_period_nano;
    clear_plots();
    reset_plot_value = priv_memory.Fosc_moment * priv_memory.Fosc_period_nano;
    start_emulator();
    reset_plot_value = priv_memory.Fosc_moment * priv_memory.Fosc_period_nano;
    clear_plots();
    update_Labels();
  }
}
