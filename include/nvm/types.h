#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*
An NVM typedef for opcode.
*/
typedef uint8_t nvm_opcode_t;


/*
An NVM typedef for opcode's argument.

In this version there's only 32 bit support.
*/
typedef int32_t nvm_arg_t;


/*
An NVM size type used for all sized objects like program or stack.

There's only 32-bit with because max bytecode size cannot be bigger than 4 GB.
*/
typedef uint32_t nvm_size_t;



/*
An NVM size type used for CPU state

Basically this is unsigned char.
*/
typedef uint8_t nvm_state_t;



/*
An NVM size type used for real bytecode size. 64 bit basically.
*/
typedef uint64_t nvm_size64_t;



#ifdef NVM_DEBUG
  #define NVM_ALLOW_ARG_CHECKS
#endif


#ifndef NVM_RELEASE
  #define nvm_error(l, m) (size_t)(printf("(%d) \033[31m\033[1m%s\033[0m\n", l, m) && 0);
#else
  #define nvm_error(__VA_ARGS__) 0
#endif


#ifdef NVM_ALLOW_ARG_CHECKS
  #define nvm_arg_check(x) x
#else
  #define nvm_arg_check(x)
#endif


#ifdef NVM_ALLOW_MEMCPY
 #define nvm_memcpy memcpy
#else
  #define nvm_memcpy memmove
#endif


#ifdef __forceinline
  #define nvm_inline __forceinline
#elif defined(__always_inline)
  #define nvm_inline __always_inline
#else
  #define nvm_inline inline
#endif