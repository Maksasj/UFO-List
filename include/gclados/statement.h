// Author: Artiom Tretjakovas
// Description: This file contains functions for creating / executing statement.

#ifndef GCLADOS_STATEMENT_H
#define GCLADOS_STATEMENT_H

#include "predicate.h"

// Function, that executes given statement.
void gcladosCreateStatement(const char *functionName,
                            int line,
                            char *filePath,
                            void *value,
                            GcladosPredicate predicate);

#endif
