#pragma once

#include <nvm/types.h>


#ifdef __cplusplus
extern "C"{
#endif



/*
A struct that implements virtual stack.

Can be created with `nvm_createStack`.

All members are private.
*/
typedef struct{
  /*
  An internal pointer to the start of stack.
  */
  nvm_arg_t *_st_ptr;

  /*
  Stack's current pointer. Must be `>=_st_ptr`.
  */
  nvm_arg_t *_bp_ptr;

  /*
  Stack's size.
  */
  nvm_size_t _size;

} nvm_stack;



/*
Allocates new NVM stack that can be used for `nvm_cpu_t`.

\param size Maximum size of stack.

\returns A pointer to allocated stack; NULL if error occured (basically malloc).
*/
nvm_stack* nvm_createStack(nvm_size_t size);



/*
Increase current stack pointer and push an argument to the top of stack.

\param stack An `nvm_stack` pointer where the data will push.
\param arg A value that will be pushed to the stack.

\returns 1 on success; NULL on error.
*/
int nvm_push(nvm_stack* stack, nvm_arg_t arg);



/*
Push to a stack a buffer of values. This is like `nvm_push` many times.

\param stack An `nvm_stack` pointer where the data will push.
\param buffer A buffer that will be pushed to the stack.
\param count Count of values to be pushed in.

\returns 1 on success; NULL on error.
*/
int nvm_pushBuffer(nvm_stack* stack, const nvm_arg_t* buffer, nvm_size_t count);



/*
Return an argument from the top of stack and decrease current stack pointer.

\param stack An `nvm_stack` pointer to pop the data from.

\returns An `nvm_arg_t` value from the top of stack.
*/
nvm_arg_t nvm_pop(nvm_stack* stack);



/*
Pop a buffer of values from stack. This is like `nvm_pushBuffers` many times.

\param stack An `nvm_stack` pointer where the data will push.
\param buffer A buffer where the data will be poped in.
\param count Count of data to be poped from.

\returns 1 on success; NULL on error.
*/
int nvm_popBuffer(nvm_stack* stack, nvm_arg_t* buffer, nvm_size_t count);



/*
Exchange stack size to the specific count of bytes.

\param stack An `nvm_stack` pointer.
\param new_size A new stack size on bytes.

\returns 1 on success; NULL on error.
*/
int nvm_exchange(nvm_stack* stack, nvm_size_t new_size);



#ifdef __cplusplus
extern "C"{
#endif