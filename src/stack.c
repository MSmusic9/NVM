#include "stack.h"
#include <string.h>
#include <stdlib.h>



nvm_stack* nvm_createStack(nvm_size_t size){
  nvm_arg_check(if (!size) return (nvm_stack*)nvm_error(__LINE__, "nvm_createStack: size is NULL!"));

  nvm_stack* st = (nvm_stack*)malloc(sizeof(nvm_stack));

  if (!st) return (nvm_stack*)nvm_error(__LINE__, "nvm_createStack: malloc returned NULL!");

  st->_size = size;

  st->_st_ptr = (nvm_arg_t*)malloc(size * sizeof(nvm_arg_t));

  if (!st->_st_ptr) return (nvm_stack*)nvm_error(__LINE__, "nvm_createStack: malloc returned NULL!");

  st->_bp_ptr = st->_st_ptr;

  return st;
}



int nvm_push(nvm_stack* stack, nvm_arg_t arg){
  nvm_arg_check(if (!stack) nvm_error(__LINE__, "nvm_push: invalid stack pointer!"));

  ++stack->_bp_ptr;

  nvm_arg_check(if (stack->_bp_ptr - stack->_st_ptr > stack->_size) return nvm_error(__LINE__, "nvm_push: stack overflow!"));

  *stack->_bp_ptr = arg;

  return 1;
}



nvm_arg_t nvm_pop(nvm_stack* stack){
  nvm_arg_check(if (!stack) nvm_error(__LINE__, "nvm_pop: invalid stack pointer!"));

  nvm_arg_t val = *stack->_bp_ptr;

  --stack->_bp_ptr;

  nvm_arg_check(if (stack->_bp_ptr - stack->_st_ptr < 0) nvm_error(__LINE__, "nvm_pop: stack underflow!"));

  return val;
}



int nvm_pushBuffer(nvm_stack* stack, const nvm_arg_t* buffer, nvm_size_t count){
  nvm_arg_check(if (!stack) nvm_error(__LINE__, "nvm_pushBuffer: invalid stack pointer!"));
  
  nvm_arg_check(if (stack->_bp_ptr - stack->_st_ptr + count * sizeof(nvm_arg_t) > stack->_size) return nvm_error(__LINE__, "nvm_pushBuffer: stack overflow!"));

  ++stack->_bp_ptr;

  nvm_memcpy(stack->_bp_ptr, buffer, count * sizeof(nvm_arg_t));

  --stack->_bp_ptr;
  stack->_bp_ptr += count;

  return 1;
}



int nvm_popBuffer(nvm_stack* stack, nvm_arg_t* buffer, nvm_size_t count){
  nvm_arg_check(if (!stack) nvm_error(__LINE__, "nvm_popBuffer: invalid stack pointer!"));
  
  nvm_arg_check(if (stack->_bp_ptr - stack->_st_ptr < 0) return nvm_error(__LINE__, "nvm_popBuffer: stack underflow!"));

  stack->_bp_ptr -= count;

  nvm_memcpy(buffer, stack->_bp_ptr, count * sizeof(nvm_arg_t));

  --stack->_bp_ptr;

  return 1;
}



int nvm_exchange(nvm_stack* stack, nvm_size_t new_size){
  nvm_arg_check(if (!(stack && new_size)) return nvm_error(__LINE__, "nvm_exchange: stack is NULL!"));

  nvm_size_t offset = stack->_bp_ptr - stack->_st_ptr;

  stack->_st_ptr = (nvm_arg_t*)realloc(stack->_st_ptr, new_size);

  if (!stack->_st_ptr) return nvm_error(__LINE__, "nvm_exchange: realloc returned NULL!");

  stack->_bp_ptr = stack->_st_ptr + offset;

  return 1;
}