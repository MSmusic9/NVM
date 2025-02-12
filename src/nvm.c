#include "nvm.h"
#include "opcodes.h"


#define gen_case(code, op) case code: \
++ip; \
op(); \
break



static nvm_inline void fetch(nvm_cpu* cpu){
  
  switch ()
}



nvm_state_t nvm_stop(nvm_cpu* cpu){
  if (!nvm_checkCpuState(cpu)) return 0;

  cpu->state = 0;
  return 1;
}



nvm_state_t nvm_start(nvm_cpu* cpu){
  while (!feof(cpu->file)){
    fetch(cpu);
  }

  return 1;
}