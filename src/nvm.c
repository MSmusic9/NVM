#include <nvm/nvm.h>
#include <nvm/opcodes.h>


#define NVM_DISPATCH(OP) op_##OP: \
_SERVICE_##OP; \
goto fetch;

#define NVM_CDDISPATCH(OP) op_##OP: \
_SERVICE_CD_##OP; \
goto fetch;



void _nvm_ramExec(const nvm_opcode_t* code){
  register nvm_opcode_t* base = code;
  register char* table[256];
  goto init;


init:
  table = {0};


fetch:
  goto *table[*code];


op_illegal:
  printf("NVM: illegal instruction (halting)\n");
  printf("At: RAM mode\n");
  printf("\tPhysic address: %p\n", (void*)code);
  printf("\tRelative address: &p\n", (void*)(code - base));
  return;
}



void _nvm_diskExec(FILE* handle){
  register char* table[256];
  goto init;


init:
  table = {0};


fetch:
  goto *table[nvm_fgetc(handle)];


op_illegal:
  printf("NVM: illegal instruction (halting)\n");
  printf("At: disk mode\n");
  printf("\tPhysic address: %lu\n", ftell(handle));
  printf("\tRelative address: &lu\n", ftell(handle));
  return;
}