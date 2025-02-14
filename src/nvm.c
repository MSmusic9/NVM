#include <nvm/nvm.h>
#include <nvm/opcodes.h>


#define NVM_DISPATCH(OP) op_##OP: \
NVM_OP_##OP; \
goto fetch;



void nvm_start(const nvm_opcode_t* code){
  register nvm_opcode_t* base = code;
  // initialize opcode table and start loop
  goto init;

do_first_instr:
  goto *table[*code];

fetch:
  goto *table[*(++code)];

init:
  // start loop
  goto do_first_instr
}
