#pragma once

#include <nvm/stack.h>


/*
An enum that representing current executing mode.

`NVM_EXEC_TYPE_RAM` - load bytecode into RAM.
`NVM_EXEC_TYPE_DISK` - execute from the file in the disk.
*/
typedef enum{
  NVM_EXEC_TYPE_RAM, NVM_EXEC_TYPE_DISK
} nvm_exec_type;



/*
The main NVM translation unit

`nvm_cpu` stores all nessecary for virtual machine data, like loaded bytecode, stack size, etc.

You can allocate new NVM CPU with `nvm_createCpu()` function.
*/
typedef struct{
  /*
  Type of executing.
  */
  nvm_exec_type type;

  /*
  A pointer to the source (`FIlE*` or `nvm_opcode_t*`).
  */
  void* src;
} nvm_cpu;



/*
Create a new CPU object.

\param file A file the CPU object will be loaded from.
\param type An executing type (see `nvm_exec_type`).

\returns A pointer to `nvm_cpu_t`; NULL on error.
*/
nvm_cpu* nvm_createCpu(FILE*, nvm_exec_type);