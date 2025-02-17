#pragma once


#include <nvm/types.h>



#define ARG8 ((uint8_t*)(++code))
#define ARG16 ((uint16_t*)(++code))
#define ARG32 ((uint32_t*)(++code))
#define ARG64 ((uint64_t*)(++code))

#define ADDR32 ((uint32_t)(*ARG32))
#define ADDR64 ((uint64_t)(*ARG64))


#define _SERVICE_NOP ++code



// move literal to the register
// movrd
#define _SERVICE_MOVRD1 acc1 = *ARG32; ++code
#define _SERVICE_MOVRD2 acc2 = *ARG32; ++code
#define _SERVICE_MOVR1D64 acc1 = *ARG64; ++code
#define _SERVICE_MOVR2D64 acc2 = *ARG64; ++code


// load data to the register from memory
// movrp
#define _SERVICE_MOVR1P8 acc1 = *(uint8_t)ADDR64; ++code
#define _SERVICE_MOVR1P16 acc1 = *(uint16_t)ADDR64; ++code
#define _SERVICE_MOVR1P32 acc1 = *(uint32_t)ADDR64; ++code
#define _SERVICE_MOVR1P64 acc1 = *(uint64_t)ADDR64; ++code

/*
// push a literal to the top of stack
// pushd
#define _SERVICE_PUSHD arg = *ARG32; _ASM("pushq %0", nonereg, arg); ++code
#define _SERVICE_PUSHD64 arg = *ARG64; _ASM("pushq %0", nonereg, arg); ++code; ++code


// push a value from heap to the top of stack
// pushrp
#define _SERVICE_PUSHR1P8 arg = *((uint8_t*)acc1); _ASM("pushw %0", nonereg, arg); ++code
#define _SERVICE_PUSHR1P16 arg = *((uint16_t*)acc1); _ASM("pushw %0", nonereg, arg); ++code
#define _SERVICE_PUSHR1P32 arg = *((uint32_t*)acc1); _ASM("pushq %0", nonereg, arg); ++code
#define _SERVICE_PUSHR1P64 arg = *((uint64_t*)acc1); _ASM("pushq %0", nonereg, arg); ++code
#define _SERVICE_PUSHR2P8 arg = *((uint8_t*)acc2); _ASM("pushw %0", nonereg, arg); ++code
#define _SERVICE_PUSHR2P16 arg = *((uint16_t*)acc2); _ASM("pushw %0", nonereg, arg); ++code
#define _SERVICE_PUSHR2P32 arg = *((uint32_t*)acc2); _ASM("pushq %0", nonereg, arg); ++code
#define _SERVICE_PUSHR2P64 arg = *((uint64_t*)acc2); _ASM("pushq %0", nonereg, arg); ++code


// push a register value to the top of stack
// pushr
#define _SERVICE_PUSHR1 _ASM("pushq %0", nonereg, acc1); ++code
#define _SERVICE_PUSHR2 _ASM("pushq %0", nonereg, acc2); ++code


// pop value into register
// popr
#define _SERVICE_POPR1 _ASM("popq %0", acc1, acc1); ++code
#define _SERVICE_POPR2 _ASM("popq %0", acc2, acc2); ++code
*/

// jump from the literal
// jmpd
#define _SERVICE_JMPD code = base + *ARG32
#define _SERVICE_JMPD64 code = base + *ARG64


// jump from register
// jmpr
#define _SERVICE_JMPR1 code = base + acc1
#define _SERVICE_JMPR2 code = base + acc2


// jump relatively (with sign-check)
// jmpn
#define _SERVICE_JMPN code = code + (int32_t)(*ARG32)
#define _SERVICE_JMPN64 code = code + (int64_t)(*ARG64)


// compare registers for equality and jump
// ifeq
#define _SERVICE_IFEQ arg = *ARG64; if (acc1 == acc2){code = base + arg;}else{code = base + *ARG64;}


// compare registers, and jump if first is bigger
// ifgr
#define _SERVICE_IFGR arg = *ARG64; if (acc1 > acc2){code = base + arg;}else{code = base + *ARG64;}


// compare registers, and jump if second is bigger
// iflt
#define _SERVICE_IFLT arg = *ARG64; if (acc1 < acc2){code = base + arg;}else{code = base + *ARG64;}


// compare registers, and jump if not equal
// ifneq
#define _SERVICE_IFNEQ arg = *ARG64; if (acc1 != acc2){code = base + arg;}else{code = base + *ARG64;}


// jump if first register is zero
// ifz
#define _SERVICE_IFZ arg = *ARG64; if (!acc1){code = base + arg;}else{code = base + *ARG64;}


// jump if all registers non-zero
// ifand
#define _SERVICE_IFAND arg = *ARG64; if (acc1 && acc2){code = base + arg;}else{code = base + *ARG64;}


// jump if any register non-zero
// ifor
#define _SERVICE_IFOR arg = *ARG64; if (acc1 || acc2){code = base + arg;}else{code = base + *ARG64;}






// exit current executing process safely
// exit
#define _SERVICE_EXIT return


// halt with exit code in the acc1
// halt
#define _SERVICE_HALT arg = *ARG8; printf("NVM: halted at %p (relative address %p).\nExit code: %d.", (void*)code, (void*)(code - base), arg); exit(arg)