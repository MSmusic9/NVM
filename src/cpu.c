#include "cpu.h"



nvm_cpu* nvm_createCpu(FILE* src){
  nvm_cpu* cpu = (nvm_cpu*)malloc(sizeof(nvm_cpu));

  char buff[32];

  FILE* file = fopen((const char*)src, "r");
  fread(buff, 1, 4, cpu->file);

  if (strncmp(buff, "\xffNVM", 4)) return (nvm_cpu*)nvm_error(__LINE__, "nvm_createCpu: bad file format!");
}