// Author: Artiom Tretjakovas
// Description: This file contains predicates for testing arrays.

#ifndef GCLADOS_ARRAY_PREDICATES_H
#define GCLADOS_ARRAY_PREDICATES_H

#include "predicate.h"
#include "stdlib.h"

// This predicate is used to test array. It succeeds when every element from the array satisfies specified predicate.
// Parameters:
//     predicate   - predicate, that should be satisfied by each element from the array.
//     elementSize - the size of each element in the array.
//     arrayLength - the length of specified array.
// Note: more information about predicates is in the "predicate.h" file.
GcladosPredicate gcladosEach(GcladosPredicate predicate, size_t elementSize, size_t arrayLength);

#endif
