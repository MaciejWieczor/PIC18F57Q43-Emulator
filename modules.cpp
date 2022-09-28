#include "structs.h"
#include "modules.h"

void init_Modules(Memory * memory, Modules * modules) {
  /*TMR0 section */
  modules->tmr0.tmr0h_p = &memory->data_memory[TMR0H];
  modules->tmr0.tmr0l_p = &memory->data_memory[TMR0L];
  modules->tmr0.t0con1_p = &memory->data_memory[T0CON1];
  modules->tmr0.t0con0_p = &memory->data_memory[T0CON0];
}

void module_tmr0(Modules * modules, Bus * bus) {
  /* TBD: Create logic for tmr0 configurations and
  *       operation */
}
