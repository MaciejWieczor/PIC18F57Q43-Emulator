#include <time.h>
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
* @state - int current state of the mcu
* @request - int that requests some changes to mcu operation*/
int machine_State(int state, int request, Code * code, Memory * memory);

int init_Memory(Code * code, Memory * memory);

int init_Clock(Clock * clock);

int fetch_Instruction(Code * code, Memory * memory);

int execute_Instruction(Code * code, Memory * memory);
