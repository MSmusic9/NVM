#include <nvm/nvm.h>
#include <nvm/opcodes.h>


#define NVM_DISPATCH(OP) op_##OP: \
SERVICE_##OP; \
goto fetch;

#define NVM_CDDISPATCH(OP) op_##OP: \
SERVICE_CD_##OP; \
goto fetch;



void nvm_ramExec(const nvm_opcode_t* code){
  register nvm_opcode_t* base = code;
  // initialize opcode table and start loop
  goto init;

fetch:
  goto *table[*code];

init:
  // start loop
  goto fetch;

op_illegal:
  printf("NVM: illegal instruction (halting)\n");
  printf("At: RAM mode\n");
  printf("\tPhysic address: %p\n", (void*)code);
  printf("\tRelative address: &p\n", (void*)(code - base));
  return;
}



void nvm_diskExec(FILE* handle){
  goto init;

fetch:
  goto *table[fgetc(handle)];

init:
  goto fetch;

op_illegal:
  printf("NVM: illegal instruction (halting)\n");
  printf("At: disk mode\n");
  printf("\tPhysic address: %lu\n", ftell(handle));
  printf("\tRelative address: &lu\n", ftell(handle));
  return;
}


