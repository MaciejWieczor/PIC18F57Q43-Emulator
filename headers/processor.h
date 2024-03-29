#include"structs.h"

#define INSTRUCTION_LOAD 0
#define INSTRUCTION_EXECUTE 1

/* The function to give all other functions a pulse. It needs to sit 
 * in the main function and periodically call all other functions to 
 * make them progress. It compares current time with some time saved 
 * to a variable and if the difference is bigger than the period it 
 * returns a pulse
 * @tstart - timespec struct that holds starting time in seconds and nanoseconds
 * @period - long int period in nanoseconds*/
int clk_Pulse(Clock * clock, int period);

/* The function to determine in which state the mcu is while a new 
* clock pulse is registered 
* 0 is intruction load, 1 is instruction execute
* @code - 
* @memory - 
* @bus - */
void machine_State(Code * code, Memory * memory, Bus * bus);
//void machine_State(Code * code, Memory * memory, Bus * bus);
void flush_program_memory_data_latch(Memory * memory);

void save_Context_ISR(Memory * memory);

void restore_Context_ISR(Memory * memory);

void machine_State_Step(Code * code, Memory * memory, Bus * bus);

int init_Memory(Code * code, Memory * memory, Bus * bus);

int init_Clock(Clock * clock);

int fetch_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock);

int execute_Instruction(Code * code, Memory * memory, Bus * bus, u8 clock);

void print_coded_instr(Code * code, Memory * memory, Bus * bus);

void pre_Copy_Pointer_Data(Code * code, Memory * memory, Bus * bus);

void post_Copy_Pointer_Data(Code * code, Memory * memory, Bus * bus);

u32 merge_int(u8 u, u8 h, u8 l);

u16 merge_byte(u8 h, u8 l);

void TOS_to_stack(Memory * memory);

void move_to_TOS(u32 x, Memory * memory);
