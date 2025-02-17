#include <nvm/nvm.h>
#include <nvm/opcodes.h>



#define NVM_DISPATCH(OP) op_##OP: \
_SERVICE_##OP; \
goto fetch;



/*static nvm_inline void __nvm_rbp_add(){
  asm("addq %0, rbp" :: "r"());
}*/



static __attribute__((__cdecl)) void __nvm_exec(const nvm_opcode_t* source, void** table){
  register nvm_size64_t acc1, acc2;
  
  void* op_table[256] = {
    &&op_NOP, &&op_MOVRD1, &&op_MOVRD2,
    /*&&op_PUSHD, &&op_PUSHD64, &&op_PUSHR1P8, &&op_PUSHR1P16, &&op_PUSHR1P32, &&op_PUSHR1P64,
    &&op_PUSHR2P8, &&op_PUSHR2P16, &&op_PUSHR2P32, &&op_PUSHR2P64, &&op_PUSHR1, &&op_PUSHR2,
    &&op_POPR1, &&op_POPR2, */&&op_JMPD, &&op_JMPD64, &&op_JMPR1, &&op_JMPR2
  };

  register const nvm_opcode_t* code = source;
  register nvm_impl_t arg;
  
  register const nvm_opcode_t* base = code;
  register void** fn_table = table;

  goto fetch;


  NVM_DISPATCH(NOP);
  NVM_DISPATCH(MOVRD1);
  NVM_DISPATCH(MOVRD2);
  /*NVM_DISPATCH(PUSHD);
  NVM_DISPATCH(PUSHD64);
  NVM_DISPATCH(PUSHR1P8);
  NVM_DISPATCH(PUSHR1P16);
  NVM_DISPATCH(PUSHR1P32);
  NVM_DISPATCH(PUSHR1P64);
  NVM_DISPATCH(PUSHR2P8);
  NVM_DISPATCH(PUSHR2P16);
  NVM_DISPATCH(PUSHR2P32);
  NVM_DISPATCH(PUSHR2P64);
  NVM_DISPATCH(PUSHR1);
  NVM_DISPATCH(PUSHR2);
  NVM_DISPATCH(POPR1);
  NVM_DISPATCH(POPR2);*/
  NVM_DISPATCH(JMPD);
  NVM_DISPATCH(JMPD64);
  NVM_DISPATCH(JMPR1);
  NVM_DISPATCH(JMPR2);


fetch:
  goto *op_table[*code];


op_illegal:
  printf("NVM: illegal instruction (halting).\n");
  printf("At:\n");
  printf("\tPhysic address: %p\n", (void*)code);
  printf("\tRelative address: &p\n", (void*)(code - base));
  return;
}



int main(){
  nvm_opcode_t* c = {3, 5, 2, 0, 0, 0, 7, 0};
  __nvm_exec(c, 0);
}