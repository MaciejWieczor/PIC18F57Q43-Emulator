#include "procesor.h"

#define CLOCK_PC_INC_LATCH_IR       0
#define CLOCK_PC_INC_DECODE         1
#define CLOCK_ADDRESS_PROCESS       2
#define CLOCK_LATCH_WRITE           3

enum math_operation {
	ADDITION,
	SUBTRACTION,
	LOGICAL_AND,
	LOGICAL_IOR,
	LOGICAL_XOR
};


static Program_Word read_Instruction_Bus(Code * code, Memory * memory, Bus * bus) {
  return bus->instruction_Bus; 
}

/* Here we need to check the file parameter of the instruction 
 * and resolve it to an actual address that we access in the next step */
static void decode_memory(Memory * memory, Code * code) {
      Program_Word tmp_p;
      WORD_UNION tmp;
      tmp_p = memory->instruction_register;
      tmp.program_word = tmp_p.program_word;
}

/* TBD: possible problems when working with negative numbers, to test later */
/* POSSIBLE_IDEA: copy the numbers and the operation*/
static void modify_status_reg(Memory * memory, u8 a, u8 wreg, u8 operation_type) {
  STATUS_R status;
  int temp;
  status.reg = memory->data_memory[STATUS];

  switch(operation_type) {
		case ADDITION:
      temp = a + wreg;
			break;
		case SUBTRACTION:
      temp = a - wreg;
			break;
		case LOGICAL_AND:
      temp = a & wreg;
			break;
		case LOGICAL_IOR:
      temp = a | wreg;
			break;
		case LOGICAL_XOR:
      temp = a ^ wreg;
			break;
    default:
      break;
  }

  if(operation_type == ADDITION || operation_type == SUBTRACTION) {
    if(temp & 0x100) status.C = 1;
    if(((a & 0x0F) + (wreg & 0x0F)) & 0x10) status.DC = 1;
    if((wreg & 0x80) != (temp & 0x80)) status.OV = 1;
  }
  if(temp == 0) status.Z = 1;
  if(temp < 0 ) status.N = 1;

  memory->data_memory[STATUS] = status.reg;
}

/* TBD: Implement the actual logic what each literal instruction does
 * and what data memory address it set to write the result to*/
/* LEFT_TBD:
 * RETLW
 * */
/* TBD: Add STATUS register changes based on arythmetic operations */
static void execute_literal(Memory * memory, Bus * bus) {
  int address;
  WORD_UNION p_word;
  bus->data_Bus.two_byte_write = 0;
  p_word.program_word = memory->instruction_register.program_word;

  switch(p_word.literal.opcode) {

    case INSTR_MULLW:
      bus->data_Bus.two_byte_write = 1;
      bus->data_Bus.data = p_word.literal.k * memory->data_memory[WREG];
      memory->data_address = PROD;
      break;

    case INSTR_MOVLW:
      bus->data_Bus.data = p_word.literal.k;
      memory->data_address = WREG;
      break;

    case INSTR_MOVLB:
      bus->data_Bus.data = p_word.literal.k;
      memory->data_address = BSR;
      break;

    case INSTR_ADDLW:
      bus->data_Bus.data = p_word.literal.k + memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], ADDITION);
      memory->data_address = WREG;
      break;

    case INSTR_SUBLW:
      bus->data_Bus.data = p_word.literal.k - memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], SUBTRACTION);
      memory->data_address = WREG;
      break;

    case INSTR_ANDLW:
      bus->data_Bus.data = p_word.literal.k & memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], LOGICAL_AND);
      memory->data_address = WREG;
      break;

    case INSTR_XORLW:
      bus->data_Bus.data = p_word.literal.k ^ memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], LOGICAL_XOR);
      memory->data_address = WREG;
      break;

    case INSTR_IORLW:
      bus->data_Bus.data = p_word.literal.k | memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], LOGICAL_IOR);
      memory->data_address = WREG;
      break;

    case INSTR_ADDFSR:
      address = FSR0 - 8 * p_word.addl_fsr.f;
      bus->data_Bus.data = memory->program_memory[memory->instruction_register.index].data + memory->data_memory[address];
      if(memory->data_memory[address] == 255)
        bus->data_Bus.two_byte_write = 1;
      memory->data_address = address;
      break;

    case INSTR_SUBFSR:
      address = FSR0 - 8 * p_word.addl_fsr.f;
      bus->data_Bus.data = memory->program_memory[memory->instruction_register.index].data + memory->data_memory[address];
      if(memory->data_memory[address] == 255)
        bus->data_Bus.two_byte_write = 1;
      memory->data_address = address;
      break;

    case INSTR_LFSR:
      bus->data_Bus.two_byte_write = 1;
      address = FSR0 - 8 * p_word.lfsr.fn;
      bus->data_Bus.data = memory->program_memory[memory->instruction_register.index].data;
      memory->data_address = address;
      break;

    default:
      break;
  }
}

/* Here we change the values of registers according to the opcode 
 * and the parameters */
/* TBD: put some actual operations inside here - at first at least 
 * literal/wreg operations and gotos*/
static void execute_instruction(Memory * memory, Bus * bus) {
      switch(memory->instruction_register.type) {

      /* File operations that take one byte as register address */
			case ERROR_TYPE:
        printf("ERROR - NO INSTRUCTION TYPE!");
				break;
			case BYTE_FILE:
				break;
			case BYTE_FILE_NW:
				break;
			case BYTE_SKIP:
				break;
			case BYTE_SKIP_NW:
				break;
			case BIT:
				break;
			case INHERENT:
				break;
			case BRA_COND:
				break;
			case BRA_UNCOND:
				break;
			case RET:
				break;
			case CALL:
				break;
			case GOTOI:
        memory->program_counter.DATA = memory->instruction_register.data;
				break;
			case LITERAL:
        execute_literal(memory, bus);
				break;
			case LITERAL_FSR:
				break;
			case LFSR:
				break;
      default:
        break;
  }
}

/* Here we take the value that we got from the operation and we save 
 * it back either to f or to WREG */
/* TBD: based on memory->data_address save the operation from the data_bus*/
static void write_to_memory(Memory * memory, Bus * bus) {
  if(bus->data_Bus.two_byte_write) {
    memory->data_memory[memory->data_address] = bus->data_Bus.data & 0x00FF;
    memory->data_memory[memory->data_address + 1] = (bus->data_Bus.data & 0xFF00) >> 8;
  }
  else
    memory->data_memory[memory->data_address] = bus->data_Bus.data;
}

static int fetch_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock) {
  /*In the fetch phase the Program Counter (PC) is incremented and 
   * the instruction is put out on to the bus - only in the next 
   * phase it is latched into Instruction Register*/
  switch(code->clock_Cycle) {

    case CLOCK_PC_INC_LATCH_IR:
      memory->program_counter.DATA += 2;
      code->current_Line = memory->program_counter.DATA / 2;
      break;

    case CLOCK_PC_INC_DECODE:
      break;

    case CLOCK_ADDRESS_PROCESS:
      /* The instruction is latched into the data latch after program memory */
      memory->instruction_data_latch = memory->program_memory[code->current_Line];
      break;

    case CLOCK_LATCH_WRITE:
      /* Data latch outputs the instruction onto the bus */
      bus->instruction_Bus = memory->instruction_data_latch;
      break;

    default:
      break;
  }
  return 0;
}

static int execute_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock) {
  /*Instruction from the bus is latched into the Instruction 
   * Register. Next the instruction is decoded and executed over 
   * the next few clock cycles. Data memory is read and written 
   * during execution as well.*/
  switch(code->clock_Cycle) {

    case CLOCK_PC_INC_LATCH_IR:
      memory->instruction_register = read_Instruction_Bus(code, memory, bus);
      break;

    case CLOCK_PC_INC_DECODE:
      decode_memory(memory, code);
      break;

    case CLOCK_ADDRESS_PROCESS:
      execute_instruction(memory, bus);
      break;

    case CLOCK_LATCH_WRITE:
      write_to_memory(memory, bus);
      break;

    default:
      break;
  }
  return 0;
}

static void print_encoded(Program_Word tmp_p, Memory * memory, Line * line) {
  WORD_UNION p_word;
  p_word.program_word = tmp_p.program_word;

  switch(tmp_p.type) {

		case ERROR_TYPE:
      printf("ERROR TYPE!\n");
			break;
		case BYTE_FILE: 
      printf("ENCODED : opcode %d d %d a %d f %d\n", p_word.byte.opcode, p_word.byte.d, p_word.byte.a, p_word.byte.f);
			break;
		case BYTE_FILE_NW: 
      printf("ENCODED : opcode %d a %d f %d\n", p_word.byte_nw.opcode, p_word.byte_nw.a, p_word.byte_nw.f);
			break;
		case BIT: 
      printf("ENCODED : opcode %d b %d a %d f %d\n", p_word.bit.opcode, p_word.bit.b, p_word.bit.a, p_word.bit.f);
			break;
		case INHERENT: 
      printf("ENCODED : opcode %d\n", p_word.inherent.lsb);
			break;
		case BRA_COND: 
      printf("ENCODED : opcode %d k %d\n", p_word.bra_cond.opcode, p_word.bra_cond.n);
			break;
		case BRA_UNCOND: 
      printf("ENCODED : opcode %d k %d\n", p_word.bra_uncond.opcode, p_word.bra_uncond.n);
			break;
		case RET: 
      printf("ENCODED : opcode %d k %d\n", p_word.ret.opcode, p_word.ret.s);
			break;
		case CALL: 
      printf("ENCODED : opcode %d k %X\n", p_word.call.opcode, memory->program_memory[line->address/2].data);
			break;
		case GOTOI: 
      printf("ENCODED : opcode %d k %X\n", p_word.gotoi.opcode, memory->program_memory[line->address/2].data);
			break;
		case LITERAL:
      printf("ENCODED : opcode %d k %d\n", p_word.literal.opcode, p_word.literal.k);
			break;
		case LITERAL_FSR:
      printf("ENCODED : opcode %d, fn %d, k %d\n", p_word.addl_fsr.opcode, p_word.addl_fsr.f, p_word.addl_fsr.k);
			break;
		case LFSR:
      printf("ENCODED : opcode %d, fn %d, k %X\n", p_word.lfsr.opcode, p_word.lfsr.fn, memory->program_memory[line->address/2].data);
			break;
    default:
      printf("\n");
      break;
  }
}

static void print_coded_instr(Code * code, Memory * memory, Bus * bus) {
  Program_Word tmp_p;
  WORD_UNION tmp;
  tmp_p = memory->instruction_register;
  tmp.program_word = tmp_p.program_word;
  printf("LAST INSTRUCTION (EXECUTED) : %s, ", code->lines[tmp_p.index].words[0].c_str());
  printf("\n");
  print_encoded(tmp_p, memory, &code->lines[tmp_p.index]);
  printf("NEXT INSTRUCTION (LOADED) : %s, ", code->lines[read_Instruction_Bus(code, memory, bus).index].words[0].c_str());
  printf("\n");
  print_encoded(read_Instruction_Bus(code, memory, bus), memory, &code->lines[read_Instruction_Bus(code, memory, bus).index]);
  printf("REGISTER STATE : \n");
  printf("PC : 0x%X, ", memory->program_counter.DATA);
  printf("BSR : %d, ", memory->data_memory[BSR]);
  printf("WREG : %d", memory->data_memory[WREG]);
  printf("\n");
  printf("ACCESS BANK : \n");
  printf("     0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
  for(int i = 0 ; i < 16 ; i++) {
    printf("%X : ", i);
    for(int j = 0 ; j < 16 ; j++) {
      printf("%2X ", *memory->access_bank.data[i*16 + j]);
    }
    printf("\n");
  }
}

static u16 merge_byte(u8 h, u8 l) {
  return h * 16 + l;
}

static u16 data_address(u8 bsr, u8 f) {
  return f + bsr * 0x100;
}

int clk_Pulse(Clock * clock, int period) {
  struct timespec tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &tnow);
  long int diff = tnow.tv_nsec + 10e9*tnow.tv_sec - clock->tnow.tv_nsec - 10e9*clock->tnow.tv_sec;
  //printf("time %ld, start %ld diff %ld\n", tnow.tv_nsec, tstart->tv_nsec, diff);
  /* if elapsed time bigger than period send pulse 
   * and update tstart */
  if (diff >= period) {
    clock_gettime(CLOCK_MONOTONIC, &clock->tnow);
    return 1;
  }
  /* else return zero */
  else return 0;
}

int init_Memory(Code * code, Memory * memory, Bus * bus) {
  /* Here we first set the program counter to the base address */
  memory->program_counter.DATA = code->base_address - 2;
  memory->instruction_register.program_word = 0;

  bus->instruction_Bus = {.program_word = 0, .type = ERROR_TYPE};
  bus->data_Bus.data = 0;

  code->current_Line = memory->program_counter.DATA / 2;
  code->clock_Cycle = 0;

  /* Init data memory banks */
  for(int i = 0 ; i < 64 ; i++) {
    for(int j = 0 ; j < 256 ; j++) {
      memory->data_memory.push_back(0);
    }
  }

  /* Init virtual access bank */
  for(int i = 0 ; i < 256 ; i++) {
    if( i < 96 ) {
      memory->access_bank.data[i] = &memory->data_memory[data_address(5, i)];
    }
    else {
      memory->access_bank.data[i] = &memory->data_memory[data_address(4, i)];
    }
  }

  memory->data_memory[BSR] = 0;

  return 0;
}

int init_Clock(Clock * clock) {
  clock->tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &clock->tnow);
  return 0;
}

void machine_State(Code * code, Memory * memory, Bus * bus) {
  /* Possible states are instruction load and 
    * instruction execute */
  // PRINTS FOR DEBUG

  fetch_Instruction(code, memory, bus, code->clock_Cycle);
  execute_Instruction(code, memory, bus, code->clock_Cycle);
  code->clock_Cycle++;
  if(code->clock_Cycle == 4) {
    code->clock_Cycle = 0;
    printf("---------------------------------------------------------\n");
    /* TBD Print register values for debugging purpouses */
    print_coded_instr(code, memory, bus);
  }
}
