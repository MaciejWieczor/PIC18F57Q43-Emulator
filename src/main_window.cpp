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

    /* Load file action */
    QObject::connect(ui.actionLoad_File, SIGNAL(triggered()), this, SLOT(openFile()));
    /* Step disassembly */
    QObject::connect(ui.pushButton_disasm, SIGNAL(clicked()), this, SLOT(machine_State_Step()));
    /* Step C */
    QObject::connect(ui.pushButton_breakpoint, SIGNAL(clicked()), this, SLOT(RunUntilAddr()));
    /* Start simulation - help function to load the default program*/
    QObject::connect(ui.pushButton_start, SIGNAL(clicked()), this, SLOT(start_emulator()));
    /* Connect add plot button */
    QObject::connect(ui.pushButton_add_plot, SIGNAL(clicked()), this, SLOT(Add_Plot()));
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

  init_Memory(&priv_code, &priv_memory, &priv_bus);
  qDebug() << priv_code.clock_Cycle << "\n";
  parse_Code(&priv_code, &priv_memory);
  decode_Lines(&priv_code, &priv_memory, &priv_bus);
  cout << "PROGRAM MEMORY SIZE : " << priv_memory.program_memory.size() << "\n";

  find_IRQs(&priv_code, &priv_memory);
  find_Last_C_Lines(&priv_code);

  QString prog_str = "";
  for(C_Line &line : priv_code.c_lines) {
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

void MainWindow::update_LabelTableReturnStack () {
  char buffer [20];

  for(int i = 0 ; i < 8 ; i++) {
    sprintf(buffer, "0x%X", priv_memory.return_stack[i]); 
    ui.return_stack->setItem(i, 0,  new QTableWidgetItem(buffer));
  }
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
          points[index].push_back(QPointF(time_moment-1, 1));
        points[index].push_back(QPointF(time_moment, 1));
      }
      else { 
        if(points[index].back().y() == 1)
          points[index].push_back(QPointF(time_moment - 1, 0));
        points[index].push_back(QPointF(time_moment, 0));
      }
    }
    text_ind++;
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
          points[index].push_back(QPointF(time_moment-1, 1));
        points[index].push_back(QPointF(time_moment, 1));
      }
      else { 
        if(points[index].back().y() == 1)
          points[index].push_back(QPointF(time_moment - 1, 0));
        points[index].push_back(QPointF(time_moment, 0));
      }
    }
    text_ind++;
  }

  printf("AAAAAAAAAAAAAAAA\n");
  int i = 0;
  for(QwtPlot * plot : plots) {

    if(i == plots.size() - 1) {
      plot->enableAxis(QwtPlot::xBottom, true);
      plot->setAxisScale( QwtPlot::xBottom, 0.0, time_moment);
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

void MainWindow::update_Labels() {
  /* Update label 1 */
  update_LabelTableInstr();
  update_LabelTableCpu();
  update_LabelTableInt();
  update_LabelTableInt_Pir();
  update_LabelTableTmr0();
  update_LabelTableReturnStack();
  update_Plots();

  update_Table();

  disasm_Highlight();
  c_line_Highlight();
}

void MainWindow::RunUntilAddr() {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG
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
      module_tmr0(&priv_memory, &priv_bus, priv_code.clock_Cycle);
      priv_code.clock_Cycle++;
      if(priv_code.clock_Cycle == 4) {
          /* printf("INTERRUPT NUMBER = %d\n", priv_memory.modules.IVT_module.context); */
          priv_code.clock_Cycle = 0;
          qDebug() << "---------------------------------------------------------\n";
          /* print_coded_instr(&priv_code, &priv_memory, &priv_bus); */
      }
    }

    post_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);
    time_moment++;
    update_PlotsInv();
  }
  update_Labels();
}

void MainWindow::machine_State_Step() {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG
  gui_cur_line = priv_bus.instruction_Bus.index;
  qDebug() << "CURR LINE : " << gui_cur_line << "\n";

  pre_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);

    module_interrupt(&priv_memory, &priv_bus, &priv_code, priv_code.clock_Cycle);
  for(int i = 0 ; i < 4 ; i++) {
    fetch_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
    execute_Instruction(&priv_code, &priv_memory, &priv_bus, priv_code.clock_Cycle);
    module_tmr0(&priv_memory, &priv_bus, priv_code.clock_Cycle);
    priv_code.clock_Cycle++;
    if(priv_code.clock_Cycle == 4) {
        printf("INTERRUPT NUMBER = %d\n", priv_memory.modules.IVT_module.context);
        priv_code.clock_Cycle = 0;
        qDebug() << "---------------------------------------------------------\n";
        print_coded_instr(&priv_code, &priv_memory, &priv_bus);
    }
  }

  post_Copy_Pointer_Data(&priv_code, &priv_memory, &priv_bus);
  update_Labels();
  time_moment++;
}
