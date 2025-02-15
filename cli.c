/*
This is the entry point in NVM virtual machine, for working as process, not library
*/


#include <nvm/nvm.h>



void exec_file(){

}



int main(int argc, char** argv){
  int curr = 1;

  
  if (argc < 2){
    printf("CLI: no input file.\nType 'nvm.exe --help' to get list of commands.\n");
    return -1;
  }

  if (strcmp("-d", argv[curr]) || strcmp("--directory", argv[curr])){
    ++curr;
  }

  if (strcmp("-dm", argv[curr]) || strcmp("--diskmode", argv[curr])){
    ++curr;
  }

  const char* path = argv[curr];
}