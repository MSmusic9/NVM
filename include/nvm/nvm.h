#pragma once

#include "cpu.h"



/*
Start bytecode evaluating or continue after `nvm_stop()`.

This is the main function of all library =].

\param cpu A pointer to CPU to evaluate code from.

\returns 1 if success; NULL on error.
*/
nvm_state_t nvm_start(nvm_cpu* cpu);



/*
Stop evaluating process that `nvm_start()` started.

This is a multithread function.

\param cpu A pointer to CPU to be stopped.

\returns 1 if success; NULL on error.
*/
nvm_state_t nvm_stop(nvm_cpu* cpu);