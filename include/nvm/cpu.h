#pragma once

#include <nvm/stack.h>


#ifdef __cplusplus
extern "C"{
#endif



/*
The main NVM translation unit

`nvm_cpu` stores all nessecary for virtual machine data, like loaded bytecode, stack size, etc.

You can allocate new NVM CPU with `nvm_createCpu()` function.
*/
typedef struct{
  /*
  A pointer to the bytecode program.
  */
  nvm_opcode_t* src;

  /*
  A pointer to the function table.
  */
  uintptr_t* fn_table;

  /*
  Current CPU state.
  */
  nvm_state_t state;
} nvm_cpu;



/*
Create a new CPU object.

\param file A file the CPU object will be loaded from.

\returns A pointer to `nvm_cpu`; NULL on error.
*/
nvm_cpu* nvm_createCpu(FILE*);



#ifdef __cplusplus
}
#endif