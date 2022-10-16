#include "structs.h"
#include "processor.h"

typedef struct IRQ_NUM_BIT {
  int addr;
  u8 bit_pos;
} IRQ_NUM_BIT;

/* TBD: */
/* This will return PIR address and bit position to the interrupt which ID is passed as argument */
IRQ_NUM_BIT resolve_irq_id_to_addr(Memory * memory, int id) {
}

/* TBD: */
/* This will poll the PIR registers and return a vector with numbers of enabled interrupt requests */
vector<int> polling(Memory * memory) {
}

/* TBD: */
/* This will return interrupt number that that won priority resolving */
int resolve_priority(Memory * memory, vector<int> iprs) {
}

/* TBD: */
void module_interrupt(Memory * memory, Bus * bus, int clock) {
  /* Parse all PIR */
  switch(memory->modules.IVT_module.context) {
    /* If we are in the main context we just poll the IFs for something to handle */
    case POLLING_CONT:
      /* ONLY EXECUTE THIS PART IF INTERRUPTS ARE ENABLED */
      /* If we found IRQ we let the currently loaded instruction finish */
      /* We load all found IRQs into a temp vector to figure out the priority */
      break;
    case INT_LAT_0_2_CONT:
      /* STOPCLOCK: */
      break;
    /* Instruction is 3 cycles long */
    case INT_LAT_0_3_CONT:
      /* STOPCLOCK: */
      break;
    /* Context save + IVT address calculation */
    case INT_LAT_1_CONT:
      /* STOPCLOCK: */
      flush_program_memory_data_latch(memory);
      save_Context_ISR(memory);
      break;
    /* Load PC with pointer to ISR function (the one we saved in module struct)*/
    case INT_LAT_2_CONT:
      /* The CPU can then just increment this and load it for execution - now we are in interrupt context */
      /* STARTCLOCK: */
      memory->program_counter.DATA = memory->modules.TMR0_module.ivt_address - 2;
      break;
    default:
      break;
  }
}

/* TBD: */
void module_tmr0(Memory * memory, Bus * bus, int clock) {
  /* TBD: Create logic for tmr0 configurations and
  *       operation */
  T0CON0_bits tmr0_con0_tmp;
  T0CON1_bits tmr0_con1_tmp;
  tmr0_con0_tmp.data = memory->data_memory[T0CON0];
  tmr0_con1_tmp.data = memory->data_memory[T0CON1];

  /* Check mode */

  /* Clock source check */ 
  
  /* Sync/Async */

  /* Prescaler, postscaler */

  /* See if mode condition is met*/

  /* Set interrupt flag */

  /* Check if turned on - and count */
}
