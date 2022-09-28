#include "structs.h"

#ifndef MODULES_H
#define MODULES_H

/* TMR0 definitions */

#define TMR0L     0x318
#define TMR0H     0x319
#define T0CON0    0x31A
#define T0CON1    0x31B

union T0CON0_bits {
  u8 data;
  struct {
  u8 EN   : 1;
  u8 empty: 1;
  u8 OUT  : 1;
  u8 MD16 : 1;
  u8 OUTPS: 4;
  };
};

union T0CON1_bits {
  u8 data;
  struct {
  u8 CS   : 3;
  u8 empty: 1;
  u8 OUT  : 4;
  };
};

union TMR0_16 {
  u16 data;
  struct {
    u8 tmr0h;
    u8 tmr0l;
  };
};

struct TMR0 {
  u8 * tmr0h_p;
  u8 * tmr0l_p;
  u8 * t0con1_p;
  u8 * t0con0_p;
};

/* MODULES */

typedef struct Modules {
  struct TMR0 tmr0;
} Modules;

/* This function saves data memory location to pointers in module structs for easier
* access */
void init_Modules(Memory * memory, Modules * modules);

/* Function handler when tmr0 gets a rising edge from its CS */
void module_tmr0(Modules * modules, Bus * bus);


#endif
