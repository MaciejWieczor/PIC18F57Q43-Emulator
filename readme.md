# Readme 

# ToDos

# Already done

## Parsing ##

  - Reading disassembly format
  - Striping comments and whitespace
  - Reading address, encoded program word, opcode and parameters into vector<string>

## Program Code ##
  
  - Creating array of program code structures
  - Filling array entries based on vector<string> read from the disassemblied code
    - Encoding opcodes and parameters into couple of separate union types that symbolize 
      different types of instruction formats
    - Using std::map to match opcode to its number
    - Encoding program words based on their addresses read from code text
    - Saving addresses for jump type instructions

