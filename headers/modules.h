#include "structs.h"

#ifndef MODULES_H
#define MODULES_H

/* IVT/interrupt definitions */

#define PIR1    0x4AF
#define PIR2    0x4B0
#define PIR3    0x4B1
#define INTCON0 0x4D6
#define PIE0    0x49E
#define PIE1    0x49F
#define PIE2    0x4A0
#define PIE3    0x4A1

union PIR1_R {
  u8 data;
  struct {
    u8 SMT1PWAIF : 1;
    u8 SMT1PRAIF : 1;
    u8 SMT1IF : 1;
    u8 CMP1F : 1;
    u8 ACTIF : 1;
    u8 ADIF : 1;
    u8 ZCDIF : 1;
    u8 INT0IF : 1;
  };
};

union PIE1_R {
  u8 data;
  struct {
    u8 SMT1PWAIE : 1;
    u8 SMT1PRAIE : 1;
    u8 SMT1IE : 1;
    u8 CMP1F : 1;
    u8 ACTIE : 1;
    u8 ADIE : 1;
    u8 ZCDIE : 1;
    u8 INT0IE : 1;
  };
};

union PIR3_R {
  u8 data;
  struct {
    u8 TMR0IF : 1;
    u8 CCP1IF : 1;
    u8 TMR1GIF : 1;
    u8 TMR1IF : 1;
    u8 TMR2IF : 1;
    u8 SPI1IF : 1;
    u8 SPI1TXIF : 1;
    u8 SPI1RXIF : 1;
  };
};

union PIE3_R {
  u8 data;
  struct {
    u8 TMR0IE : 1;
    u8 CCP1IE : 1;
    u8 TMR1GIE : 1;
    u8 TMR1IE : 1;
    u8 TMR2IE : 1;
    u8 SPI1IE : 1;
    u8 SPI1TXIE : 1;
    u8 SPI1RXIE : 1;
  };
};

union INTCON0_R {
  u8 data;
  struct {
    u8 GIEGIEH : 1;
    u8 GIEL : 1;
    u8 IPEN : 1;
    u8 empty : 2;
    u8 INT2EDG : 1;
    u8 INT1EDG : 1;
    u8 INT0EDG : 1;
  };
};

typedef struct Interrupt_Vector_Module {
  map<string, int> interrupt_vector;
  u8 context;
} Interrupt_Vector_Module;

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

typedef struct TMR0_Module {
  u8 enabled;
  int ivt_address;
} TMR0_module;

/* MODULES */

typedef struct Modules {
  Interrupt_Vector_Module IVT_module;
  TMR0_Module TMR0_module;
} Modules;

void module_interrupt(Memory * memory, Bus * bus, int clock);

void module_tmr0(Memory * memory, Bus * bus, int clock);

#endif
