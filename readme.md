# Readme 


## Parsing ##

### Already done

  - Removing whitespace and comments
  - Spliting each line by spaces to move opcodes, addresses, encoded data and parameters into string vector

### ToDo

## Program Code ##
  
### Already done

  - Creating program word structure and program memory array
  - Based on parsed disassembly text filling the program memory array 
    - Creating union types for each instruction format
    - Creating maps of instruction names to opcode numbers
    - Encoding parsed line into created union based on instruction type/format
    - Saving some useful data like 
      - instruction program memory address
      - jump-to address for jump type instructions
      
### ToDo

## PIC18 CPU ##

### Already done

  - Simple clock state machine
  - Instruction pipeline framework based on the state machine
  - Program counter operation flow 
    - Fetch increments at the beginning, reads from the PC address at the end
    - GoTo instruction overwrites PC at the end of the cycle so that there is a jump to that instruction
  - Simple debug print for common registers and the access bank
  - CPU executes most literal instructions
  - CPU modifies STATUS register based on the arithmetic operation
  - CPU writes to memory based on data bus structure

### ToDo

  - CPU executes file accessing instructions
  - CPU executes bit type instructios 
  - CPU executes control instructions 
    - Save/Restore context workflow needed
      - Shadow register
      - Stack implementation
  - Interrupt vector

## Memory ##

### Already done

  - Access bank implementation (pointers to program memory range)
  - Last instruction clock step writes data to memory location from the data bus

### ToDo

  - Define addresses to memory registers for implemented modules

## Modules ##

### ToDo

  - Test module idea of putting module handlers in main clock handler or add more clocks

#### DMA
  
  - Read and test how dma exactly works along the cpu

#### TMR
  
  - Add TMR0 and test its operation
