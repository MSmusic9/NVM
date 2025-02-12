#pragma once

#include "stack.h"



/*
The main NVM translation unit

`nvm_cpu` stores all nessecary for virtual machine data, like loaded bytecode, stack size, etc.

You can allocate new NVM CPU with `nvm_createCpu()` function.
*/
typedef struct{
  /*
  An NVM bytecode that we load from file/buffer.

  Do not modify.
  */
  nvm_opcode_t* code;

  /*
  A pointer to bytecode's stack.

  Can be created with `nvm_createStack()` function.

  NULL if host program stack is used.
  */
  nvm_stack* stack;

  /*
  Current CPU state. Can be 0 or 1 and
  configues with `nvm_stop/nvm_start/nvm_restart` functions.
  */
  nvm_state_t state;

  /*
  An offset to current instruction.

  Don't change it. Please.
  */
  nvm_size_t ip;

  /*
  CPU's code
  */
  nvm_opcode_t* code;

} nvm_cpu;



/*
Create a new CPU object.

\param file A file the CPU object will be loaded from.

\returns A pointer to  `nvm_cpu_t`; NULL on error.
*/
nvm_cpu* nvm_createCpu(FILE*);