// Author: Artiom Tretjakovas
// Description: This file contains panic function.

#ifndef GCLADOS_PANIC_H
#define GCLADOS_PANIC_H

// This function prints error message into stderr and exits with specified exit code.
void gcladosPanic(const char *message, int exitCode) __attribute__((__noreturn__));

#endif
