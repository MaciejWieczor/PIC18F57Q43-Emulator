#include "processor.h"

#define CLOCK_PC_INC_LATCH_IR       0
#define CLOCK_PC_INC_DECODE         1
#define CLOCK_ADDRESS_PROCESS       2
#define CLOCK_LATCH_WRITE           3

enum math_operation {
  M_DEC,
	M_ADDITION,
	M_SUBTRACTION,
	M_LOGICAL_AND,
	M_LOGICAL_IOR,
	M_LOGICAL_XOR
};

static u16 data_address(u8 bsr, u8 f) {
  return f + bsr * 0x100;
}

u16 merge_byte(u8 h, u8 l) { return h * 256 + l; }

u32 merge_int(u8 u, u8 h, u8 l) { return u * 65536 + h * 256 + l; }

/* PUSH TOS further onto the stack - and load the x parameter into the TOS */
/* TBD: check for STKPTR Overflow */
static void move_to_TOS(u32 x, Memory * memory) {
  memory->data_memory[STKPTR]++;
  memory->data_memory[TOS+2] = (x & 0x00FF0000) >> 16;
  memory->data_memory[TOS+1] = (x & 0x0000FF00) >> 8;
  memory->data_memory[TOS] = x & 0x000000FF;
}

/* Updates data_memory */
/* Copy the stack into the TOS registers (in case instruction changes the value of the STKPTR)*/
static void stack_to_TOS(Memory * memory) {
  memory->data_memory[TOS+2] = (memory->return_stack[memory->data_memory[STKPTR]] & 0x00FF0000) >> 16;
  memory->data_memory[TOS+1] = (memory->return_stack[memory->data_memory[STKPTR]] & 0x0000FF00) >> 8; 
  memory->data_memory[TOS] = memory->return_stack[memory->data_memory[STKPTR]] & 0x000000FF;
}

/* TBD: check for STKPTR Underflow */
static void remove_TOS(Memory * memory) {
  memory->data_memory[STKPTR]--;
  stack_to_TOS(memory);
}

/* Updates return stack */
/* Copy the TOS back to the stack's top element (in case instruction changed TOSL or TOSH or TOSU)*/
static void TOS_to_stack(Memory * memory) {
  int tos = merge_int(memory->data_memory[TOS+2], memory->data_memory[TOS+1], memory->data_memory[TOS]);
  memory->return_stack[memory->data_memory[STKPTR]] = tos;
}

/* Saves crucial register values like Status, wreg and bsr to the fast register stack */
static void save_Context(Memory * memory) {
  memory->fast_register_stack.push_back(memory->data_memory[STATUS]);
  memory->fast_register_stack.push_back(memory->data_memory[WREG]);
  memory->fast_register_stack.push_back(memory->data_memory[BSR]);
}

/* TBD: include more registers */
/* Saves crucial register values like Status, wreg and bsr to the fast register stack */
void save_Context_ISR(Memory * memory) {
  memory->fast_register_stack.push_back(memory->data_memory[STATUS]);
  memory->fast_register_stack.push_back(memory->data_memory[WREG]);
  memory->fast_register_stack.push_back(memory->data_memory[BSR]);
}

/* Restores crucial register values like Status, wreg and bsr from the fast register stack */
static void restore_Context(Memory * memory) {

  /* Remove first three elements while saving them back into data memory*/
  memory->data_memory[BSR] = memory->fast_register_stack.back();
  memory->fast_register_stack.pop_back();
  memory->data_memory[WREG] = memory->fast_register_stack.back();
  memory->fast_register_stack.pop_back();
  memory->data_memory[STATUS] = memory->fast_register_stack.back();
  memory->fast_register_stack.pop_back();

}

/* TBD: include more registers */
/* Restores crucial register values like Status, wreg and bsr from the fast register stack */
void restore_Context_ISR(Memory * memory) {

  /* Remove first three elements while saving them back into data memory*/
  memory->data_memory[BSR] = memory->fast_register_stack.back();
  memory->fast_register_stack.pop_back();
  memory->data_memory[WREG] = memory->fast_register_stack.back();
  memory->fast_register_stack.pop_back();
  memory->data_memory[STATUS] = memory->fast_register_stack.back();
  memory->fast_register_stack.pop_back();

}

static void update_PC(Memory * memory) {
  memory->data_memory[PC] = memory->program_counter.L;
  memory->data_memory[PC+1] = memory->program_counter.H;
  memory->data_memory[PC+2] = memory->program_counter.U;
}

static int resolve_Access_Bank_Address(u8 i) {
    if( i < 96 ) {
      return data_address(5, i);
    }
    else {
      return data_address(4, i);
    }
}

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

static void modify_status_reg(Memory * memory, u8 a, u8 wreg, u8 operation_type) {
  STATUS_R status;
  int temp;
  status.reg = memory->data_memory[STATUS];

  switch(operation_type) {
    case M_DEC:
      temp = wreg - a;
      break;
		case M_ADDITION:
      temp = a + wreg;
			break;
		case M_SUBTRACTION:
      temp = a - wreg;
			break;
		case M_LOGICAL_AND:
      temp = a & wreg;
			break;
		case M_LOGICAL_IOR:
      temp = a | wreg;
			break;
		case M_LOGICAL_XOR:
      temp = a ^ wreg;
			break;
    default:
      break;
  }

  if(operation_type == M_ADDITION || operation_type == M_SUBTRACTION) {
    if(temp & 0x100) status.C = 1;
    if(((a & 0x0F) + (wreg & 0x0F)) & 0x10) status.DC = 1;
    if((wreg & 0x80) != (temp & 0x80)) status.OV = 1;
  }
  if(temp == 0) status.Z = 1;
  if(temp < 0 ) status.N = 1;

  memory->data_memory[STATUS] = status.reg;
}

void flush_program_memory_data_latch(Memory * memory) {
  memory->instruction_data_latch.index = memory->instruction_register.index; 
  memory->instruction_data_latch.program_word = 0; 
  memory->instruction_data_latch.type = NOP_TYPE;
  memory->instruction_data_latch.data = 0;
}

static void indirect_pre_ops(Memory * memory, int address) {
  int fsr_address; 
  int tmp_fsr = 0;
  int preinc_reg = 0;
  int plusw_reg = 0;
  int post_reg = 0;
  switch(address) {
    case PREINC0:
      tmp_fsr = FSR0;
      preinc_reg = PREINC0;
      break;
    case PREINC0-8:
      tmp_fsr = FSR1;
      preinc_reg = PREINC0-8;
      break;
    case PREINC0-16:
      tmp_fsr = FSR2;
      preinc_reg = PREINC0-16;
      break;
    case PLUSW0:
      tmp_fsr = FSR0;
      plusw_reg = PLUSW0;
      break;
    case PLUSW0-8:
      tmp_fsr = FSR1;
      plusw_reg = PLUSW0-8;
      break;
    case PLUSW0-16:
      tmp_fsr = FSR2;
      plusw_reg = PLUSW0-16;
      break;
    case POSTDEC0:
      tmp_fsr = FSR0;
      post_reg = POSTDEC0;
    case POSTDEC0-8:
      tmp_fsr = FSR1;
      post_reg = POSTDEC0-8;
    case POSTDEC0-16:
      tmp_fsr = FSR2;
      post_reg = POSTDEC0-16;
    case POSTINC0:
      tmp_fsr = FSR0;
      post_reg = POSTINC0;
    case POSTINC0-8:
      tmp_fsr = FSR1;
      post_reg = POSTINC0-8;
    case POSTINC0-16:
      tmp_fsr = FSR2;
      post_reg = POSTINC0-16;
    default:
      break;
  }

  /* MODIFY THE FSR VALUE */
  if(tmp_fsr) {
    fsr_address = memory->data_memory[tmp_fsr+1] * 0x100 + memory->data_memory[tmp_fsr];
    /* IF WE INCREMENTED THE FSR */
    if(preinc_reg) {
      fsr_address++;
      memory->data_memory[preinc_reg] = memory->data_memory[fsr_address];
      memory->data_memory[tmp_fsr] = fsr_address & 0x00FF;
      memory->data_memory[tmp_fsr+1] = (fsr_address & 0xFF00) >> 8;
    }
    /* IF WE JUST DID THE PLUSW */
    if(plusw_reg) {
      fsr_address += (signed char)memory->data_memory[WREG];
      memory->data_memory[preinc_reg] = memory->data_memory[fsr_address];
    }
    if(post_reg)
      memory->data_memory[post_reg] = memory->data_memory[fsr_address];
  }
}

static void indirect_post_ops(Memory * memory, int address) {
  int fsr_address; 
  int tmp_fsr = 0;
  int post_reg_dec = 0;
  int post_reg_inc = 0;
  switch(address) {
    case POSTDEC0:
      tmp_fsr = FSR0;
      post_reg_dec = POSTDEC0;
    case POSTDEC0-8:
      tmp_fsr = FSR1;
      post_reg_dec = POSTDEC0-8;
    case POSTDEC0-16:
      tmp_fsr = FSR2;
      post_reg_dec = POSTDEC0-16;
    case POSTINC0:
      tmp_fsr = FSR0;
      post_reg_inc = POSTINC0;
    case POSTINC0-8:
      tmp_fsr = FSR1;
      post_reg_inc = POSTINC0-8;
    case POSTINC0-16:
      tmp_fsr = FSR2;
      post_reg_inc = POSTINC0-16;
    default:
      break;
  }

  /* MODIFY THE FSR VALUE */
  if(tmp_fsr) {
    fsr_address = memory->data_memory[tmp_fsr+1] * 0x100 + memory->data_memory[tmp_fsr];
    if(post_reg_dec) {
      fsr_address--;
    }
    if(post_reg_inc) {
      fsr_address++;
    }
    memory->data_memory[tmp_fsr] = fsr_address & 0x00FF;
    memory->data_memory[tmp_fsr+1] = (fsr_address & 0xFF00) >> 8;
  }
}

static void execute_byte_file(Memory * memory, Bus * bus) {
  int address;
  WORD_UNION p_word;
  p_word.program_word = memory->instruction_register.program_word;

  /* Here we check for the ACCESS bit and we set the data memory 
   * address (for the write_to_memory step) accordingly */
  if(!p_word.byte.a) 
    address = resolve_Access_Bank_Address(p_word.byte.f);
  else 
    address = data_address(memory->data_memory[BSR], p_word.byte.f);



  if(p_word.byte.d)
    memory->data_address = address;
  else
    memory->data_address = WREG;

  /* Here we put data from the address specified in .f in a local variable 
   * Later we just need to put the result on the data bus and everything else will 
   * fall into place*/
  u8 temp = memory->data_memory[address];
  u8 wreg = memory->data_memory[WREG];
  union STATUS_R status;
  status.reg = memory->data_memory[STATUS];
  bus->data_Bus.write = 1;

  switch(p_word.byte.opcode) {
 		case INSTR_ADDWF:
      bus->data_Bus.data = temp + wreg;
      modify_status_reg(memory, temp, wreg, M_ADDITION);
			break;
 		case INSTR_ADDWFC:
      bus->data_Bus.data = temp + wreg + status.C;
      modify_status_reg(memory, temp+status.C, wreg, M_ADDITION);
			break;
 		case INSTR_ANDWF:
      bus->data_Bus.data = temp & wreg;
      modify_status_reg(memory, temp, wreg, M_LOGICAL_AND);
			break;
 		case INSTR_COMF:
      bus->data_Bus.data = ~temp;
      modify_status_reg(memory, ~temp, 0xFF, M_LOGICAL_AND);
			break;
 		case INSTR_DECF:
      bus->data_Bus.data = temp - 1;
      modify_status_reg(memory, 1, temp, M_DEC);
			break;
 		case INSTR_INCF:
      bus->data_Bus.data = temp + 1;
      modify_status_reg(memory, 1, temp, M_ADDITION);
			break;
 		case INSTR_IORWF:
      bus->data_Bus.data = temp | wreg;
      modify_status_reg(memory, temp, wreg, M_LOGICAL_IOR);
			break;
    /* move f to wreg or back to f */
 		case INSTR_MOVF:
      bus->data_Bus.data = temp;
			break;
 		case INSTR_RLCF:
      bus->data_Bus.data = temp << 1;
      bus->data_Bus.data += status.C;
      status.C = (temp & 0x80) >> 7;
      memory->data_memory[STATUS] = status.reg;
			break;
 		case INSTR_RLNCF:
      bus->data_Bus.data = temp << 1;
      bus->data_Bus.data += (temp & 0x80) >> 7;
			break;
 		case INSTR_RRCF:
      bus->data_Bus.data = temp >> 1;
      bus->data_Bus.data += status.C << 7;
      status.C = temp & 0x01;
      memory->data_memory[STATUS] = status.reg;
			break;
 		case INSTR_RRNCF:
      bus->data_Bus.data = temp >> 1;
      bus->data_Bus.data += (temp & 0x01) << 7;
			break;
 		case INSTR_SUBFWB:
      bus->data_Bus.data = wreg - temp - !status.C;
      modify_status_reg(memory, wreg, temp+!status.C, M_SUBTRACTION);
			break;
 		case INSTR_SUBWF:
      bus->data_Bus.data = temp - wreg;
      modify_status_reg(memory, temp, wreg, M_SUBTRACTION);
			break;
 		case INSTR_SUBWFB:
      bus->data_Bus.data = temp - wreg - !status.C;
      modify_status_reg(memory, temp, wreg+!status.C, M_SUBTRACTION);
			break;
 		case INSTR_SWAPF:
      bus->data_Bus.data = ((temp & 0xF0) >> 4) + ((temp & 0x0F) << 4);
			break;
 		case INSTR_XORWF:
      bus->data_Bus.data = temp ^ wreg;
      modify_status_reg(memory, temp, wreg, M_LOGICAL_XOR);
			break;
 		case INSTR_DECFSZ:
      bus->data_Bus.data = temp - 1;
      if(bus->data_Bus.data == 0) flush_program_memory_data_latch(memory);
			break;
 		case INSTR_DCFSNZ:
      bus->data_Bus.data = temp - 1;
      if(bus->data_Bus.data != 0) flush_program_memory_data_latch(memory);
			break;
 		case INSTR_INCFSZ:
      bus->data_Bus.data = temp + 1;
      if(bus->data_Bus.data == 0) flush_program_memory_data_latch(memory);
			break;
 		case INSTR_INFSNZ:
      bus->data_Bus.data = temp + 1;
      if(bus->data_Bus.data != 0) flush_program_memory_data_latch(memory);
			break;
    default:
      break;
  }
}

/* LEFT_TBD: 
 * MOVFF
 * MOVFFL
 * */
static void execute_byte_nw_file(Memory * memory, Bus * bus) {
  int address;
  WORD_UNION p_word;
  p_word.program_word = memory->instruction_register.program_word;

  if(!p_word.byte_nw.a) 
    address = resolve_Access_Bank_Address(p_word.byte_nw.f);
  else 
    address = data_address(memory->data_memory[BSR], p_word.byte_nw.f);

  u8 temp = memory->data_memory[address];
  u8 wreg = memory->data_memory[WREG];
  union STATUS_R status;
  status.reg = memory->data_memory[STATUS];
  bus->data_Bus.two_byte_write = 0;
  bus->data_Bus.write = 1;

  switch(p_word.byte_nw.opcode) {

		case INSTR_CPFSEQ:
      bus->data_Bus.write = 0;
      if(temp == wreg) flush_program_memory_data_latch(memory);
			break;
		case INSTR_CPFSGT:
      bus->data_Bus.write = 0;
      if(temp > wreg) flush_program_memory_data_latch(memory);
			break;
		case INSTR_CPFSLT:
      bus->data_Bus.write = 0;
      if(temp < wreg) flush_program_memory_data_latch(memory);
			break;
		case INSTR_CLRF:
      bus->data_Bus.data = 0;
      memory->data_address = address;
      status.Z = 1;
      memory->data_memory[STATUS] = status.reg;
			break;
    /* I want to save fs and fd to int data inside the program words
     * and then overwrite the address local variable by doing 
     *
     * fs = memory->instruction_register.data & 0xFFFF0000
     * fd = memory->instruction_register.data & 0x0000FFFF
     * */
		case INSTR_MOVFF:
			break;
		case INSTR_MOVFFL:
			break;
		case INSTR_TSTFSZ:
      bus->data_Bus.write = 0;
      if(temp == 0) flush_program_memory_data_latch(memory);
			break;
		case INSTR_MOVWF:
      printf("ADDRESS %X \n", address);
      bus->data_Bus.data = wreg;
      memory->data_address = address;
			break;
		case INSTR_MULWF:
      bus->data_Bus.two_byte_write = 1;
      bus->data_Bus.data = wreg * temp;
      memory->data_address = PROD;
			break;
		case INSTR_NEGF:
      bus->data_Bus.data = ~temp + 1;
      memory->data_address = address;
			break;
		case INSTR_SETF:
      bus->data_Bus.data = 0xFF;
      memory->data_address = address;
			break;
    default:
      break;
  }
}

static void execute_bit(Memory * memory, Bus * bus) {
  int address;
  WORD_UNION p_word;
  p_word.program_word = memory->instruction_register.program_word;

  if(!p_word.bit.a) 
    address = resolve_Access_Bank_Address(p_word.bit.f);
  else 
    address = data_address(memory->data_memory[BSR], p_word.bit.f);
  u8 bit_mask = 1 << p_word.bit.b;
  u8 temp = memory->data_memory[address];
  u8 wreg = memory->data_memory[WREG];
  union STATUS_R status;
  status.reg = memory->data_memory[STATUS];
  bus->data_Bus.two_byte_write = 0;
  bus->data_Bus.write = 1;

  switch(p_word.bit.opcode) {
		case INSTR_BCF:
      bus->data_Bus.data = temp & ~bit_mask;
      memory->data_address = address;
			break;
		case INSTR_BSF:
      bus->data_Bus.data = temp | bit_mask;
      memory->data_address = address;
			break;
		case INSTR_BTG:
      bus->data_Bus.data = temp ^ bit_mask;
      memory->data_address = address;
			break;
		case INSTR_BTFSC:
      if(!(temp & bit_mask)) {
        flush_program_memory_data_latch(memory);
        bus->data_Bus.write = 0;
      }
			break;
		case INSTR_BTFSS:
      if(temp & bit_mask) {
        flush_program_memory_data_latch(memory);
        bus->data_Bus.write = 0;
      }
			break;
    default:
      break;
  }
}

static void execute_inherent(Memory * memory, Bus * bus) {
  WORD_UNION p_word;
  p_word.program_word = memory->instruction_register.program_word;
  switch(p_word.inherent.lsb) {
    case INSTR_PUSH:
      move_to_TOS(memory->program_counter.DATA, memory);
      break;
    case INSTR_POP:
      remove_TOS(memory);
      break;
    default:
      break;  
  }
}

/* If the condition is true we need to flush the next instruction and overwrite 
 * the PC with the address kept in the data field. We also should check if the 
 * address is an offset that fits inside the 8 bit variable, but the disassembly 
 * takes care of that problem */
static void execute_branch_cond(Memory * memory, Bus * bus) {
  int address;
  WORD_UNION p_word;
  p_word.program_word = memory->instruction_register.program_word;

  u8 wreg = memory->data_memory[WREG];
  union STATUS_R status;
  status.reg = memory->data_memory[STATUS];
  /* not true at the start */
  u8 condition = 0;
  bus->data_Bus.write = 0;

  switch(p_word.bra_cond.opcode) {
		case INSTR_BC:
      if(status.C) condition = 1;
			break;
		case INSTR_BN:
      if(status.N) condition = 1;
			break;
		case INSTR_BNC:
      if(!status.C) condition = 1;
			break;
		case INSTR_BNN:
      if(!status.N) condition = 1;
			break;
		case INSTR_BNOV:
      if(!status.OV) condition = 1;
			break;
		case INSTR_BNZ:
      if(!status.Z) condition = 1;
			break;
		case INSTR_BOV:
      if(status.OV) condition = 1;
			break;
		case INSTR_BZ:
      if(status.Z) condition = 1;
			break;
    default:
      break;
  }
  /* If the condition was true we flush next instruction and overwrite the PC*/
  if(condition) {
    flush_program_memory_data_latch(memory);
    /* Always do minus 2 on jumps because next two clock cycles will increment the PC */
    memory->program_counter.DATA = memory->instruction_register.data - 2;
    update_PC(memory);
  }
}

/* TBD: pop from return stack and read TOS into PC */
static void execute_ret(Memory * memory, Bus * bus) {
  WORD_UNION p_word;
  p_word.program_word = memory->instruction_register.program_word;
  /* Get TOS back into the PC */
  memory->program_counter.DATA = memory->return_stack[memory->data_memory[STKPTR]];
  update_PC(memory);
  /* Change stackpointer to "remove" the top element */
  remove_TOS(memory);
  flush_program_memory_data_latch(memory);
  /* If s == 1 then use the fast register stack */
  /* Otherwise don't */
  if(p_word.call.s) {
    restore_Context(memory);
  }
}

/* TBD: use fast stack register */
static void execute_call(Memory * memory, Bus * bus) {
  TOS_to_stack(memory);
  move_to_TOS(memory->program_counter.DATA, memory);
  memory->program_counter.DATA = memory->instruction_register.data - 2;
  update_PC(memory);
  flush_program_memory_data_latch(memory);
  WORD_UNION p_word;
  p_word.program_word = memory->instruction_register.program_word;
  /* If s == 1 then use the fast register stack */
  /* Otherwise don't */
  if(p_word.call.s) {
    save_Context(memory);
  }
}

/* LEFT_TBD:
 * RETLW
 * */
static void execute_literal(Memory * memory, Bus * bus) {
  int address;
  WORD_UNION p_word;
  bus->data_Bus.two_byte_write = 0;
  p_word.program_word = memory->instruction_register.program_word;
  bus->data_Bus.write = 1;

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
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], M_ADDITION);
      memory->data_address = WREG;
      break;

    case INSTR_SUBLW:
      bus->data_Bus.data = p_word.literal.k - memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], M_SUBTRACTION);
      memory->data_address = WREG;
      break;

    case INSTR_ANDLW:
      bus->data_Bus.data = p_word.literal.k & memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], M_LOGICAL_AND);
      memory->data_address = WREG;
      break;

    case INSTR_XORLW:
      bus->data_Bus.data = p_word.literal.k ^ memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], M_LOGICAL_XOR);
      memory->data_address = WREG;
      break;

    case INSTR_IORLW:
      bus->data_Bus.data = p_word.literal.k | memory->data_memory[WREG];
      modify_status_reg(memory, p_word.literal.k, memory->data_memory[WREG], M_LOGICAL_IOR);
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
static void execute_instruction(Memory * memory, Bus * bus) {
      printf("INSTR TYPE: %d\n", memory->instruction_register.type);
      switch(memory->instruction_register.type) {

      /* File operations that take one byte as register address */
			case NOP_TYPE:
        printf("NOP!");
				break;
			case BYTE_FILE:
        execute_byte_file(memory, bus);
				break;
			case BYTE_FILE_NW:
        execute_byte_nw_file(memory, bus);
				break;
			case BIT:
        execute_bit(memory, bus);
				break;
			case INHERENT:
        execute_inherent(memory, bus);
				break;
			case BRA_COND:
        execute_branch_cond(memory, bus);
				break;
			case BRA_UNCOND:
        memory->program_counter.DATA = memory->instruction_register.data - 2;
        update_PC(memory);
        flush_program_memory_data_latch(memory);
				break;
			case RET:
        execute_ret(memory, bus);
				break;
			case CALL:
        /* Push the TOS not the current address */
        execute_call(memory, bus);
				break;
			case GOTOI:
        memory->program_counter.DATA = memory->instruction_register.data - 2;
        update_PC(memory);
        flush_program_memory_data_latch(memory);
				break;
			case LITERAL:
        execute_literal(memory, bus);
				break;
      default:
        break;
  }
}

/* Here we take the value that we got from the operation and we save 
 * it back either to f or to WREG */
/* TBD: based on memory->data_address save the operation from the data_bus*/
static void write_to_memory(Memory * memory, Bus * bus) {
  if(bus->data_Bus.write) {
    if(bus->data_Bus.two_byte_write) {
      memory->data_memory[memory->data_address] = bus->data_Bus.data & 0x00FF;
      memory->data_memory[memory->data_address + 1] = (bus->data_Bus.data & 0xFF00) >> 8;
    }
    else
      memory->data_memory[memory->data_address] = bus->data_Bus.data;
  }
  bus->data_Bus.write = 0;
}

int fetch_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock) {
  /*In the fetch phase the Program Counter (PC) is incremented and 
   * the instruction is put out on to the bus - only in the next 
   * phase it is latched into Instruction Register*/
  switch(code->clock_Cycle) {

    case CLOCK_PC_INC_LATCH_IR:
      memory->program_counter.DATA += 2;
      update_PC(memory);
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

int execute_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock) {
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

		case NOP_TYPE:
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
      printf("ENCODED : opcode %d k %X\n", p_word.bra_cond.opcode, tmp_p.data);
			break;
		case BRA_UNCOND: 
      printf("ENCODED : opcode %d k %X\n", p_word.bra_uncond.opcode, tmp_p.data);
			break;
		case RET: 
      printf("ENCODED : opcode %d k %d\n", p_word.ret.opcode, p_word.ret.s);
			break;
		case CALL: 
      printf("ENCODED : opcode %d k %X\n", p_word.call.opcode, tmp_p.data);
			break;
		case GOTOI: 
      printf("ENCODED : opcode %d k %X\n", p_word.gotoi.opcode, tmp_p.data);
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

void print_coded_instr(Code * code, Memory * memory, Bus * bus) {
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
  printf("        0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n");
  for(int i = 0 ; i < 16 ; i++) {
    printf("%4X : ", i*0x10 + 0x0460);
    for(int j = 0 ; j < 16 ; j++) {
      printf("%2X ", memory->data_memory[i*0x10 + j + 0x0460]);
    }
    printf("\n");
  }
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
  memory->instruction_register.index = 0;

  bus->instruction_Bus = {.program_word = 0, .type = NOP_TYPE};
  bus->data_Bus.data = 0;
  bus->data_Bus.data = 0;

  code->current_Line = memory->program_counter.DATA / 2;
  code->clock_Cycle = 0;

  /* Init data memory banks */
  for(int i = 0 ; i < 64 ; i++) {
    for(int j = 0 ; j < 256 ; j++) {
      memory->data_memory.push_back(0);
    }
  }
  memory->data_memory[BSR] = 0;
  memory->data_memory[STKPTR] = 0;
  update_PC(memory);

  for(int i = 0 ; i < 127 ; i++) {
    memory->return_stack[i] = 0;
  }

  return 0;
}

int init_Clock(Clock * clock) {
  clock->tnow={0,0};
  clock_gettime(CLOCK_MONOTONIC, &clock->tnow);
  return 0;
}

void pre_Copy_Pointer_Data(Code * code, Memory * memory, Bus * bus) {
  /* Copy the INDF contents to their locations */
  /* FSR0 */
  int fsr_address = memory->data_memory[FSR0+1] * 0x100 + memory->data_memory[FSR0];
  memory->data_memory[INDF0] = memory->data_memory[fsr_address];
  /* FSR1 */
  fsr_address = memory->data_memory[FSR1+1] * 0x100 + memory->data_memory[FSR1];
  memory->data_memory[INDF1] = memory->data_memory[fsr_address];
  /* FSR2 */
  fsr_address = memory->data_memory[FSR2+1] * 0x100 + memory->data_memory[FSR2];
  memory->data_memory[INDF2] = memory->data_memory[fsr_address];

  /* Copy PC into data memory */
  memory->data_memory[PC] = memory->program_counter.L;
  memory->data_memory[PC+1] = memory->program_counter.H;
  memory->data_memory[PC+2] = memory->program_counter.U;
  /* TOS from STKPTR */
  stack_to_TOS(memory);
}

void post_Copy_Pointer_Data(Code * code, Memory * memory, Bus * bus) {
  /* Copy PC from data memory into the PC variable */
  memory->program_counter.L = memory->data_memory[PC];
  memory->program_counter.H = memory->data_memory[PC+1];
  memory->program_counter.U = memory->data_memory[PC+2];

  /* save TOS back to the top of the return stack structure */
  TOS_to_stack(memory);
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


