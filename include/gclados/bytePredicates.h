// Author: Artiom Tretjakovas
// Description: This file contains predicates for checking raw bytes.

#ifndef GCLADOS_BYTE_PREDICATES_H
#define GCLADOS_BYTE_PREDICATES_H

#include <stdio.h>

#include "predicate.h"

// This predicate checks specified value by comparing each byte.
// Parameters:
//     *bytes - pointer to expected value.
//     count  - the size of element that should be checked. For example, when checking integer values use sizeof(int).
// Note: more information about predicates is in the "predicate.h" file.
GcladosPredicate gcladosToEqualBytes(void *bytes, size_t count);

#endif
