#include "structs.h"
#include "processor.h"

typedef struct IRQ_NUM_BIT {
  int addr;
  u8 bit_pos;
} IRQ_NUM_BIT;

typedef map<int, IRQ_NUM_BIT> ID_TO_PIR;

ID_TO_PIR id_to_pir = {{0x1F, {.addr = PIR3, .bit_pos = 7}} /* TMR0 */,
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

/* TBD: */
/* This takes the irq id and return the memory->modules.MODULE.ivt_address - 2 from the correct MODULE */
int resolve_irq_id_to_pc_val(Memory * memory, int id) {
  int ret;
  switch(id) {
    case TMR0_ID:
      ret = memory->modules.TMR0_module.ivt_address;
      break;
    default:
      break;
  }
  return ret-2;
}

/* TBD: */
/* This will poll the PIR registers and return a vector with numbers of enabled interrupt requests */
vector<int> polling(Memory * memory) {
  int id;
  IRQ_NUM_BIT irq_num_bit_tmp;
  vector<int> ret;
  u8 tmp_pir;
  /* Parse all PIR registers */
  for(int i = 0 ; i < 16 ; i++) {
    /* Now parse each bit by checking parity, then bit shifting */
    tmp_pir = memory->data_memory[PIR0 + i];
    printf("PIR%d = %d : ", i, tmp_pir);
    for(u8 j = 0 ; j < 8 ; j++) {
      /* If the last bit is set */
      printf("%d ", tmp_pir % 2);
      if(tmp_pir % 2 == 1) {
        irq_num_bit_tmp = {.addr = PIR0 + i, .bit_pos = j};
        id = resolve_pir_addr_to_irq_id(memory, irq_num_bit_tmp, id_to_pir);
        ret.push_back(id);
        printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
      }
      tmp_pir /= 2;
    }
    printf("\n");
  }
  return ret;
}

/* Find the biggest id and return it from the pirs that need servicing */
int find_biggest_id_in_vector(vector<int> pirs) {
  int it = *max_element(begin(pirs), end(pirs)); // C++11
  return it;
}

/* TBD: */
/* This will return interrupt number that that won priority resolving */
int resolve_priority(Memory * memory, vector<int> pirs) {
  INTCON0_R intcon0_r;
  intcon0_r.data = memory->data_memory[INTCON0];
  int id;
  /* If user set priority then first check the ones with set IPR bits 
   * and later the ones with them cleared*/
  if(intcon0_r.IPEN) {
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
  vector<int> polled_pirs;
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
      if(intcon0_r.GIEGIEH && !intcon0_r.IPEN)
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
        }
      else {
          /* If IPEN == 0 set context number to HIGH CONTEXT because there is no LOW*/
          intcon1_r.STAT = HIGH_M_CONT;
        }
      }
      break;
    case LOW_CONT:
      /* TBD: Implement priority level */
      break;
    case HIGH_L_CONT:
      /* TBD: Implement priority level */
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
      memory->modules.IVT_module.context = HIGH_M_CONT;
      break;
    default:
      break;
  }
  memory->data_memory[INTCON1] = intcon1_r.data;
}

/* TBD: */
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
     

    /* Clock source check */ 
    
    /* Sync/Async */


    /* See if mode condition is met*/

    /* Set interrupt flag */
  }
}
