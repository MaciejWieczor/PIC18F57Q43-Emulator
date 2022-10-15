#include "structs.h"
#include "modules.h"

void module_interrupt(Memory * memory, Bus * bus, int clock) {
}

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
