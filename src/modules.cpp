#include "structs.h"
#include "processor.h"

typedef struct IRQ_NUM_BIT {
  int addr;
  u8 bit_pos;
} IRQ_NUM_BIT;

typedef map<int, IRQ_NUM_BIT> ID_TO_PIR;

ID_TO_PIR id_to_pir = {{0x1F, {.addr = PIR3, .bit_pos = 7}} /* TMR0 */,
                       {0x1C, {.addr = PIR3, .bit_pos = 4}} /* TMR1 */,
                       {}};

/* This will return PIR address and bit position to the interrupt which ID is passed as argument */
IRQ_NUM_BIT resolve_irq_id_to_pir_addr(Memory * memory, int id, ID_TO_PIR id_to_pir) {
  return id_to_pir.find(id)->second;
}

/* This will return irq ID from pir addr and bit pos (reverse upper function)*/
int resolve_pir_addr_to_irq_id(Memory * memory, IRQ_NUM_BIT addr, ID_TO_PIR id_to_pir) {
   int key = 0;
   for (auto &i : id_to_pir) {
      if (i.second.addr == addr.addr && i.second.bit_pos == addr.bit_pos) {
         return i.first;
      }
   }
  return 0;
}

/* This takes the irq id and return the memory->modules.MODULE.ivt_address - 2 from the correct MODULE */
int resolve_irq_id_to_pc_val(Memory * memory, int id) {
  int ret;
  switch(id) {
    case TMR0_ID:
      ret = memory->modules.TMR0_module.ivt_address;
      break;
    case TMR1_ID:
      ret = memory->modules.TMR1_module.ivt_address;
    default:
      break;
  }
  return ret-2;
}

typedef struct PIR_IPR {
  int id;
  int priority;
} PIR_IPR;

/* This will poll the PIR registers and return a vector with numbers of enabled interrupt requests */
vector<PIR_IPR> polling(Memory * memory) {
  int id;
  int prior;
  IRQ_NUM_BIT irq_num_bit_tmp;
  vector<PIR_IPR> ret;
  u8 tmp_pir;
  u8 tmp_pie;
  u8 tmp_ipr;
  /* Parse all PIR registers */
  for(int i = 0 ; i < 16 ; i++) {
    /* Now parse each bit by checking parity, then bit shifting */
    tmp_pir = memory->data_memory[PIR0 + i];
    tmp_pie = memory->data_memory[PIE0 + i];
    tmp_ipr = memory->data_memory[IPR0 + i];
    for(u8 j = 0 ; j < 8 ; j++) {
      /* If the last bit is set in both PIR and PIE registers*/
      /* Sometimes modules set the IF but don't want to call the interrupt (UART for example)*/
      if(tmp_pir % 2 == 1 && tmp_pie % 2 == 1) {
        irq_num_bit_tmp = {.addr = PIR0 + i, .bit_pos = j};
        id = resolve_pir_addr_to_irq_id(memory, irq_num_bit_tmp, id_to_pir);
        prior = tmp_ipr % 2;
        PIR_IPR tmp = {.id = id, .priority = prior};
        ret.push_back(tmp);
      }
      tmp_pir /= 2;
      tmp_pie /= 2;
      tmp_ipr /= 2;
    }
    printf("\n");
  }
  return ret;
}

/* Find the biggest id and return it from the pirs that need servicing */
int find_biggest_id_in_vector(vector<PIR_IPR> pirs) {
  int max = -1;
  for(PIR_IPR elem : pirs) {
    if(elem.id > max) max = elem.id;
  }
  return max;
}

/* Find the biggest id and return it from the pirs that need servicing */
int find_biggest_high_id_in_vector(vector<PIR_IPR> pirs) {
  int max = -1;
  for(PIR_IPR elem : pirs) {
    if(elem.id > max && elem.priority) max = elem.id;
  }
  return max;
}

/* Find the biggest id and return it from the pirs that need servicing */
int find_biggest_low_id_in_vector(vector<PIR_IPR> pirs) {
  int max = -1;
  for(PIR_IPR elem : pirs) {
    if(elem.id > max && !elem.priority) max = elem.id;
  }
  return max;
}

/* This will return interrupt number that that won priority resolving */
int resolve_priority(Memory * memory, vector<PIR_IPR> pirs) {
  INTCON0_R intcon0_r;
  intcon0_r.data = memory->data_memory[INTCON0];
  int id;
  /* If user set priority then first check the ones with set IPR bits 
   * and later the ones with them cleared*/
  if(intcon0_r.IPEN) {
    id = find_biggest_high_id_in_vector(pirs);
    if(id > 0) {
      memory->modules.IVT_module.current_isr_prior_lvl = HIGH_PRIORITY_LVL;
      return id;
    }
    id = find_biggest_low_id_in_vector(pirs);
    if(id > 0) {
      memory->modules.IVT_module.current_isr_prior_lvl = LOW_PRIORITY_LVL;
      return id;
    }
  }
  /* If IPEN is cleared then just find the smallest number in the vector and service the winner */
  /* Natural priority has only high level priority in the emulator */
  else {
    id = find_biggest_id_in_vector(pirs);
    memory->modules.IVT_module.current_isr_prior_lvl = HIGH_PRIORITY_LVL;
  }
  return id;
}

/* TBD: */
void module_interrupt(Memory * memory, Bus * bus, Code * code, int clock) {
  vector<PIR_IPR> polled_pirs;
  int id;
  INTCON0_R intcon0_r;
  intcon0_r.data = memory->data_memory[INTCON0];
  INTCON1_R intcon1_r;
  intcon1_r.data = memory->data_memory[INTCON1];

  /* Parse all PIR */
  switch(memory->modules.IVT_module.context) {
    /* If we are in the main context we just poll the IFs for something to handle */
    case POLLING_CONT:
      /* TBD: IF IPEN == 1 CHECK FOR GIEL BIT AS WELL */
      /* ONLY EXECUTE THIS PART IF INTERRUPTS ARE ENABLED */
      /* If we found IRQ we let the currently loaded instruction finish */
      /* IPEN = 0, GIE = 1 */
      if(intcon0_r.GIEGIEH)
        polled_pirs = polling(memory);

      /* If size != 0 then we found an interrupt */
      printf("POLLED PIRS SIZE = %d\n", polled_pirs.size());
      if(polled_pirs.size()) {
        if(code->lines[memory->instruction_data_latch.index].length > 1)
          memory->modules.IVT_module.context = INT_LAT_0_2_CONT;
        else
          memory->modules.IVT_module.context = INT_LAT_1_CONT;

        /* We load all found IRQs into a temp vector to figure out the priority */
        /* We save IRQ ID that won the priority fight to memory*/
        id = resolve_priority(memory, polled_pirs);
        /* Get function address from IVT based on the id that won the priority */
        memory->modules.IVT_module.current_isr_addr = resolve_irq_id_to_pc_val(memory, id);

        /* TBD: IF IPEN == 1 check the priority and set STAT accordingly */
        if(intcon0_r.IPEN) {
            if(memory->modules.IVT_module.current_isr_prior_lvl == HIGH_PRIORITY_LVL) {
              intcon1_r.STAT = HIGH_M_CONT;
              memory->modules.IVT_module.last_context = HIGH_M_CONT;
            }
            else {
              intcon1_r.STAT = LOW_CONT;
              memory->modules.IVT_module.last_context = LOW_CONT;
            }
          }
        else {
            /* If IPEN == 0 set context number to HIGH CONTEXT because there is no LOW*/
            intcon1_r.STAT = HIGH_M_CONT;
          }
      }
      break;
    case LOW_CONT:
      /* ONLY EXECUTE THIS PART IF INTERRUPTS ARE ENABLED */
      /* If we found IRQ we let the currently loaded instruction finish */
      if(intcon0_r.GIEGIEH)
        polled_pirs = polling(memory);

      /* If size != 0 then we found an interrupt */
      /* We are only looking for high priority interrupts */
      printf("POLLED PIRS SIZE = %d\n", polled_pirs.size());
      if(polled_pirs.size()) {
        if(memory->modules.IVT_module.current_isr_prior_lvl == HIGH_PRIORITY_LVL) {
          memory->modules.IVT_module.last_context = HIGH_L_CONT;
          intcon1_r.STAT = HIGH_L_CONT;
          if(code->lines[memory->instruction_data_latch.index].length > 1)
            memory->modules.IVT_module.context = INT_LAT_0_2_CONT;
          else
            memory->modules.IVT_module.context = INT_LAT_1_CONT;
          /* We load all found IRQs into a temp vector to figure out the priority */
          /* We save IRQ ID that won the priority fight to memory*/
          id = resolve_priority(memory, polled_pirs);
          /* Get function address from IVT based on the id that won the priority */
          memory->modules.IVT_module.current_isr_addr = resolve_irq_id_to_pc_val(memory, id);
        }
      }
      /* If no high priority interrupts were found check if we are not leaving the ISR */
      else if(code->lines[memory->instruction_register.index].words[0] == "retfie") {
        memory->modules.IVT_module.context = POLLING_CONT;
        /* Set context number to NORMAL CONTEXT*/
        intcon1_r.STAT = POLLING_CONT;
      }
      break;
    case HIGH_L_CONT:
      /* TBD: Implement priority level */
      if(code->lines[memory->instruction_register.index].words[0] == "retfie") {
        memory->modules.IVT_module.context = LOW_CONT;
        /* Set context number to NORMAL CONTEXT*/
        intcon1_r.STAT = LOW_CONT;
      }
      break;
    case HIGH_M_CONT:
      /* Check if we just executed (it auto restores context) and if yes then go back
       * to MAIN context */
      if(code->lines[memory->instruction_register.index].words[0] == "retfie") {
        memory->modules.IVT_module.context = POLLING_CONT;
        /* Set context number to NORMAL CONTEXT*/
        intcon1_r.STAT = POLLING_CONT;
      }
      break;
    case INT_LAT_0_2_CONT:
      /* STOPCLOCK: */
      memory->pc_EN = 0;
      if(code->lines[memory->instruction_data_latch.index].length == 3)
        memory->modules.IVT_module.context = INT_LAT_0_3_CONT;
      break;
    /* Instruction is 3 cycles long */
    case INT_LAT_0_3_CONT:
      memory->pc_EN = 0;
      /* STOPCLOCK: */
      memory->modules.IVT_module.context = INT_LAT_1_CONT;
      break;
    /* Context save + IVT address calculation */
    case INT_LAT_1_CONT:
      memory->pc_EN = 0;
      /* STOPCLOCK: */
      flush_program_memory_data_latch(memory);
      save_Context_ISR(memory);
      memory->modules.IVT_module.context = INT_LAT_2_CONT;
      break;
    /* Load PC with pointer to ISR function (the one we saved in module struct)*/
    case INT_LAT_2_CONT:
      memory->pc_EN = 1;
      /* The CPU can then just increment this and load it for execution - now we are in interrupt context */
      /* STARTCLOCK: */

      TOS_to_stack(memory);
      move_to_TOS(memory->program_counter.DATA, memory);
      memory->program_counter.DATA = memory->modules.IVT_module.current_isr_addr;
      /* TBD: create two levels for interrupts */
      /* RIGHT_NOW: after doing the latency thing and going to the ISR we just go to 
       * normal program execution because the PC jumps the main context into the ISR. What 
       * needs to happen, there needs to be a special context enum based on the priority level - 
       * so we can't just interrupt a high priority interrupt. For example we could start polling but 
       * only handle the interrupt if it has higher priority (if we are in low one). If we are in high
       * priority flow we don't do any polling, we just wait for the ISR to be over and then we go back 
       * to the main context - polling. If we are in low and we find high we jump into it and then after 
       * retfie we go to LOW_CONT enum.*/
      /* For now we pretend every interrupt is high after main (so we can't interrupt it) */

      /* If IPEN we look for last state to tell if we jump into low, high or high after low*/
      if(intcon0_r.IPEN) {
        memory->modules.IVT_module.context = memory->modules.IVT_module.last_context;
      } 
      /* Else just go to high after main */
      else
        memory->modules.IVT_module.context = HIGH_M_CONT;
      break;
    default:
      break;
  }
  memory->data_memory[INTCON1] = intcon1_r.data;
}

/* TBD: */
void module_tmr1(Memory * memory, Bus * bus, int clock) {
  T1CON_R t1con_tmp;
  T1CLK_R t1clk_tmp;
  T0CON0_R tmr0_con0_tmp;
  tmr0_con0_tmp.data = memory->data_memory[T0CON0];
  t1con_tmp.data = memory->data_memory[T1CON];
  t1clk_tmp.data = memory->data_memory[T1CLK];

  /* Check if turned on*/
  if(t1con_tmp.ON) {


    /* Prescaler, postscaler */
    memory->modules.TMR1_module.pre = 1;
    for(int i = 0 ; i < t1con_tmp.CKPS ; i++) {
      memory->modules.TMR1_module.pre *= 2;
    }

    /* CHECK: SIGNAL SET IN CLK REGISTER 
     * RISING EDGE/FALLING EDGE*/

    switch(t1clk_tmp.CS) {
      /* Fosc/4 */
      case 1:
        memory->modules.TMR1_module.acc++;
        if(memory->modules.TMR1_module.acc >= 4) {
          memory->modules.TMR1_module.acc = 0;
          memory->modules.TMR1_module.pre_acc++;
        }
        break;
      /* Fosc */
      case 2:
        memory->modules.TMR1_module.acc++;
        if(memory->modules.TMR1_module.acc >= 16) {
          memory->modules.TMR1_module.acc = 0;
          memory->modules.TMR1_module.pre_acc++;
        }
        break;
      /* TMR0_OUT */
      case 10:
        /* If rising edge detected */
        if(tmr0_con0_tmp.OUT == 1 && memory->modules.TMR1_module.last_cs_val == 0) {
          memory->modules.TMR1_module.pre_acc++;
        }
        memory->modules.TMR1_module.last_cs_val = tmr0_con0_tmp.OUT;
        break;
      default:
        break;
    }

    /* If prescaler overloads we increment postscaler */
    if(memory->modules.TMR1_module.pre_acc >= memory->modules.TMR1_module.pre) {
      memory->modules.TMR1_module.pre_acc = 0;
      /* OVERFLOW */
      if(memory->data_memory[TMR1H] == 255 && memory->data_memory[TMR1L] == 255) {
        memory->data_memory[TMR1H] = 0;
        memory->data_memory[TMR1L] = 0;
        PIR3_R pir3_tmp;
        pir3_tmp.data = memory->data_memory[PIR3];
        pir3_tmp.TMR1IF = 1;
        memory->data_memory[T1CON] = t1con_tmp.data;
        memory->data_memory[PIR3] = pir3_tmp.data;
      }
      else if(memory->data_memory[TMR1L] == 255) {
        memory->data_memory[TMR1H]++;
        memory->data_memory[TMR1L] = 0;
      }
      else
        memory->data_memory[TMR1L]++;
    }
  }
}

void module_tmr0(Memory * memory, Bus * bus, int clock) {
  /* TBD: Create logic for tmr0 configurations and
  *       operation */
  T0CON0_R tmr0_con0_tmp;
  T0CON1_R tmr0_con1_tmp;
  tmr0_con0_tmp.data = memory->data_memory[T0CON0];
  tmr0_con1_tmp.data = memory->data_memory[T0CON1];

  /* Check if turned on*/
  if(tmr0_con0_tmp.EN) {

    memory->modules.TMR0_module.acc++;

    /* Prescaler, postscaler */
    memory->modules.TMR0_module.post = tmr0_con0_tmp.OUTPS + 1;
    memory->modules.TMR0_module.pre = 1;
    for(int i = 0 ; i < tmr0_con1_tmp.CKPS ; i++) {
      memory->modules.TMR0_module.pre *= 2;
    }

    if(memory->modules.TMR0_module.acc >= 4) {
      memory->modules.TMR0_module.acc = 0;
      memory->modules.TMR0_module.pre_acc++;
    }

    /* If prescaler overloads we increment postscaler */
    if(memory->modules.TMR0_module.pre_acc >= memory->modules.TMR0_module.pre) {
      memory->modules.TMR0_module.pre_acc = 0;
      memory->modules.TMR0_module.post_acc++;
    }

    if(memory->modules.TMR0_module.post_acc >= memory->modules.TMR0_module.post) {
      memory->modules.TMR0_module.post_acc = 0;
      /* Check mode */
      /* 16 bit */
      if(tmr0_con0_tmp.MD16) {
        if(memory->data_memory[TMR0L] == 255) {
          memory->data_memory[TMR0H]++;
          memory->data_memory[TMR0L] = 0;
        }
        if(memory->data_memory[TMR0H] == 255) {
          memory->data_memory[TMR0H] = 0;
          tmr0_con0_tmp.OUT = !tmr0_con0_tmp.OUT;
          memory->data_memory[TMR0L] = 0;
          PIR3_R pir3_tmp;
          pir3_tmp.data = memory->data_memory[PIR3];
          pir3_tmp.TMR0IF = 1;
          memory->data_memory[T0CON0] = tmr0_con0_tmp.data;
          memory->data_memory[PIR3] = pir3_tmp.data;
        }
      }
      /* 8 bit */
      else {
        memory->data_memory[TMR0L]++;
        if(memory->data_memory[TMR0L] == memory->data_memory[TMR0H]) {
          /* If tmr matches we toggle the out bit */
          tmr0_con0_tmp.OUT++;
          memory->data_memory[TMR0L] = 0;
          PIR3_R pir3_tmp;
          pir3_tmp.data = memory->data_memory[PIR3];
          pir3_tmp.TMR0IF = 1;
          memory->data_memory[T0CON0] = tmr0_con0_tmp.data;
          memory->data_memory[PIR3] = pir3_tmp.data;
        }
      }
    }
  }
}

/* TBD: add something to be read from the pin */
void module_ports(Memory * memory, Bus * bus, int clock) {
  int signal = SINE_WAVE;
  for(int i = 0 ; i < 6 ; i++) {
    u8 bits_tmp = memory->data_memory[ANSELA + i*8];
    for(int j = 0 ; j < 8 ; j++) {
      memory->modules.Ports_module.port_pins[i][j].val = 0x0;
      if(bits_tmp % 2 == 1) {
        // CODE IF A PORT IS IN ANALOG MODE
        memory->modules.Ports_module.port_pins[i][j].val = 0xFFFF;
        printf("PORT number %d pin %d is analog\n", i, j);
      }
      bits_tmp /= 2;
    }
  }
}

/* TBD: ADC Logic */
void module_adc(Memory * memory, Bus * bus, int clock) {
  printf("ADC : STATE=%d, CURR_TIME=%lld, END_TIME=%lld\n", memory->modules.ADC_module.state, memory->Fosc_moment * memory->Fosc_period_nano, memory->modules.ADC_module.nano_end);
  ADCON0_R adcon0_tmp;
  adcon0_tmp.data = memory->data_memory[ADCON0];
  long long tmp;
  int port_address;
  u8 port_pin;
  switch(memory->modules.ADC_module.state) {
    case ADC_WAITING:
      if(adcon0_tmp.GO && adcon0_tmp.ON) {
        if(adcon0_tmp.CS)
          memory->modules.ADC_module.nano_clock = (1e9 * (1/6e5));
        else
          memory->modules.ADC_module.nano_clock = memory->Fosc_period_nano * pow(2, 1 + memory->data_memory[ADCLK]);

        if(memory->data_memory[ADPRE]) {
          memory->modules.ADC_module.state = ADC_PRECHARGE;
          memory->modules.ADC_module.nano_end = memory->modules.ADC_module.nano_clock * memory->data_memory[ADPRE];
        }
        else if(memory->data_memory[ADACQ]) {
          memory->modules.ADC_module.state = ADC_ACQUIRE;
          memory->modules.ADC_module.nano_end = memory->modules.ADC_module.nano_clock * memory->data_memory[ADACQ];
        }
        else {
          memory->modules.ADC_module.state = ADC_CONVERT;
          memory->modules.ADC_module.nano_end = memory->modules.ADC_module.nano_clock * 24;
        }

        memory->modules.ADC_module.nano_end += memory->Fosc_moment * memory->Fosc_period_nano;
      }
      break;
    case ADC_PRECHARGE:
      tmp = memory->Fosc_moment * memory->Fosc_period_nano;
      if(tmp > memory->modules.ADC_module.nano_end) {
        if(memory->data_memory[ADACQ]) {
          memory->modules.ADC_module.state = ADC_ACQUIRE;
          memory->modules.ADC_module.nano_end = memory->modules.ADC_module.nano_clock * memory->data_memory[ADACQ];
        }
        else {
          memory->modules.ADC_module.state = ADC_CONVERT;
          memory->modules.ADC_module.nano_end = memory->modules.ADC_module.nano_clock * 24;
        }
        memory->modules.ADC_module.nano_end += tmp;
      }
      break;
    case ADC_ACQUIRE:
      tmp = memory->Fosc_moment * memory->Fosc_period_nano;
      if(tmp > memory->modules.ADC_module.nano_end) {
        /* As this is the acquire phase */
        port_address = (memory->data_memory[ADPCH])/8;
        port_pin = memory->data_memory[ADPCH] % 8;
        printf("ADC SAVE : PORT %d, PIN %d, VAL 0x%X\n", port_address, 
               port_pin, memory->modules.ADC_module.last_measured_value);
        /* Read value from port */
        memory->modules.ADC_module.last_measured_value = 
              memory->modules.Ports_module.port_pins[port_address][port_pin].val;
        printf("ADC SAVE : PORT %d, PIN %d, VAL 0x%X\n", port_address, 
               port_pin, memory->modules.ADC_module.last_measured_value);
        memory->modules.ADC_module.state = ADC_CONVERT;
        memory->modules.ADC_module.nano_end += memory->modules.ADC_module.nano_clock * memory->data_memory[ADACQ];
      }
      break;
    case ADC_CONVERT:
      tmp = memory->Fosc_moment * memory->Fosc_period_nano;
      if(tmp > memory->modules.ADC_module.nano_end) {
        memory->modules.ADC_module.state = ADC_WAITING;
        memory->data_memory[ADRES] = memory->modules.ADC_module.last_measured_value & 0x00FF;
        memory->data_memory[ADRES+1] = (memory->modules.ADC_module.last_measured_value & 0xFF00) >> 8;
        adcon0_tmp.GO = 0;
        memory->data_memory[ADCON0] = adcon0_tmp.data;
      }
      break;
  }
}

void module_uart(Memory * memory, Bus * bus, int clock) {
  /* Possible states of the module :
   * OFF - when the TXEN == 0 nothing is happening
   *       when TXEN was just set we set the TXIF flag and poll writes to UxTXB 
   * POLLING - we wait for a write to UxTXB 
   *           if there is a write and TXIF is 1 we move UxTXB into TSR 
   *           and clear the TXIF and clear the TXMTIF bit 
   * POLLING & SENDING - we just put one byte into the TSR so we do the sending 
   *                     flow but we also cleared again set TXIF flag so we look 
   *                     for a write in the UxTXB
   * SENDING - we received one byte into the UxTXB while sending another one so 
   *           now we just send - and afterwards go back to polling and sending*/
  U1CON0_R u1con0_tmp;
  u1con0_tmp.data = memory->data_memory[U1CON0];
  U1CON1_R u1con1_tmp;
  u1con1_tmp.data = memory->data_memory[U1CON1];
  U1FIFO_R u1fifo_tmp;
  u1fifo_tmp.data = memory->data_memory[U1FIFO];
  u8 tmp;
  if(memory->modules.UART_module.port_changed) {
    if(memory->data_memory[RA0PPS + 
               8*memory->modules.UART_module.port + 
                 memory->modules.UART_module.pin] != UART1_PPS) {
      memory->modules.UART_module.port_changed = 0;
    }
  }
  else {
    for(int i = 0 ; i < 6 ; i++) {
      for(int j = 0 ; j < 8 ; j++) {
        tmp = memory->data_memory[RA0PPS + i*8 + j];
        if(tmp == UART1_PPS) {
          memory->modules.UART_module.port = i;
          memory->modules.UART_module.pin = j;
          memory->modules.UART_module.port_changed = 1;
          break;
        }
      }
    }
  }
  memory->modules.UART_module.frequency_split = 16 * (1 + memory->data_memory[U1BRG]);
  printf("UART MODULE DEBUG : STATE %d, END %d, COUNTER %d, BIT %d\n",
          memory->modules.UART_module.state, 
          memory->modules.UART_module.frequency_split, 
          memory->modules.UART_module.counter, 
          memory->modules.UART_module.bit_counter);
  
  switch(memory->modules.UART_module.state) {
    case UART_OFF:
      if(u1con0_tmp.TXEN) {
        memory->modules.UART_module.state = UART_POLL;
        /* Set second bit - U1TXIF */
        memory->data_memory[PIR4] |= 0x02;
      }
      break;
    case UART_POLL:
      /* If there is a write to U1TXB we jump to next state and start transmission */
      if(memory->data_address == U1TXB) {
        printf("UART STATE 1 -> 2\n");
        memory->modules.UART_module.state = UART_POLL_SEND;
        memory->modules.UART_module.TSR = memory->data_memory[U1TXB];
        /* This will overload at frequency_split value */
        memory->modules.UART_module.counter = 0;
        memory->modules.UART_module.bit_counter = 0;
        memory->modules.UART_module.transaction_start = 1;
        memory->data_memory[PIR4] &= ~0x02;
        u1fifo_tmp.TXBE = 0;
        u1fifo_tmp.TXBF = 1;
        memory->data_memory[U1FIFO] = u1fifo_tmp.data;
      }
      break;
    case UART_POLL_SEND:
      /* TSR is busy and TXB is polling */
      /* TRANSMISSION: */
      if(memory->modules.UART_module.transaction_start) {
        memory->modules.UART_module.TSR = memory->data_memory[U1TXB];
        memory->modules.UART_module.transaction_start = 0;
        memory->data_memory[PIR4] |= 0x02;
        u1fifo_tmp.TXBE = 1;
        u1fifo_tmp.TXBF = 0;
        memory->data_memory[U1FIFO] = u1fifo_tmp.data;
        /* Set the bit to 1 - START BIT */
        memory->data_memory[PORTA + memory->modules.UART_module.port] |= 
          (0x01 << memory->modules.UART_module.pin);
      }
      memory->modules.UART_module.counter++;
      if(memory->data_address == U1TXB) {
        printf("UART STATE 2 -> 3 || CLOCK = %d\n", clock);
        memory->modules.UART_module.state = UART_SEND;
        memory->data_memory[PIR4] &= ~0x02;
        u1fifo_tmp.TXBE = 0;
        u1fifo_tmp.TXBF = 1;
        memory->data_memory[U1FIFO] = u1fifo_tmp.data;
      }
      /* CHANGE PORT STATE */
      if(memory->modules.UART_module.counter == memory->modules.UART_module.frequency_split) {
        memory->modules.UART_module.bit_counter++;
        /* IF BIT_COUNTER == 10 - TRANSMISSION OVER */
        if(memory->modules.UART_module.bit_counter > 9) {
          memory->modules.UART_module.bit_counter = 0;
          memory->data_memory[PIR4] |= 0x02;
          memory->modules.UART_module.state = UART_POLL;
          u1fifo_tmp.TXBE = 1;
          u1fifo_tmp.TXBF = 0;
          memory->data_memory[U1FIFO] = u1fifo_tmp.data;
        }
        /* Set the bit to last bit of TSR, then shift TSR right */
        if(memory->modules.UART_module.TSR % 2 == 1) {
          memory->data_memory[PORTA + memory->modules.UART_module.port] |= 
            (0x01 << memory->modules.UART_module.pin);
        }
        else {
          memory->data_memory[PORTA + memory->modules.UART_module.port] &= 
            ~(0x01 << memory->modules.UART_module.pin);
        }
        memory->modules.UART_module.TSR = memory->modules.UART_module.TSR >> 1;
        memory->modules.UART_module.counter = 0;
      }
      break;
    case UART_SEND:
      /* TSR is busy and TXB is not polling */
      memory->modules.UART_module.counter++;
      /* TRANSMISSION: */
      /* CHANGE PORT STATE */
      if(memory->modules.UART_module.counter == memory->modules.UART_module.frequency_split) {
        memory->modules.UART_module.bit_counter++;
          /* TRANSMISSION OVER */
          if(memory->modules.UART_module.bit_counter > 9) {
            memory->modules.UART_module.bit_counter = 0;
            memory->data_memory[PIR4] |= 0x02;
            memory->modules.UART_module.state = UART_POLL_SEND;
            memory->modules.UART_module.counter = 0;
            /* We paste byte from TXB into TSR */
            memory->modules.UART_module.TSR = memory->data_memory[U1TXB];
            u1fifo_tmp.TXBE = 1;
            u1fifo_tmp.TXBF = 0;
            memory->data_memory[U1FIFO] = u1fifo_tmp.data;
            memory->modules.UART_module.transaction_start = 1;
            break;
          }

          /* Set the bit to last bit of TSR, then shift TSR right */
          if(memory->modules.UART_module.TSR % 2 == 1) {
            memory->data_memory[PORTA + memory->modules.UART_module.port] |= 
              (0x01 << memory->modules.UART_module.pin);
          }
          else {
            memory->data_memory[PORTA + memory->modules.UART_module.port] &= 
              ~(0x01 << memory->modules.UART_module.pin);
          }
          memory->modules.UART_module.TSR = memory->modules.UART_module.TSR >> 1;
          memory->modules.UART_module.counter = 0;
        }
      break;
    default:
      break;
  }
}
