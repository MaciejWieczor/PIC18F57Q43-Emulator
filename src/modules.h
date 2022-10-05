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

/* MODULES */

void module_tmr0(Memory * memory, Bus * bus);

#endif
