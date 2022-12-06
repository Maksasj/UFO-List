// Author: Artiom Tretjakovas
// Description: This file contains predicates for checking booleans from the <stdbool.h>.

#ifndef GCLADOS_BOOL_PREDICATES_H
#define GCLADOS_BOOL_PREDICATES_H

#include "predicate.h"

// Predicate, that checks if specified value is "true" or not.
// Note: more information about predicates is in the "predicate.h" file.
GcladosPredicate gcladosToBeTruthy();
// Predicate, that checks if specified value is "false" or not.
// Note: more information about predicates is in the "predicate.h" file.
GcladosPredicate gcladosToBeFalsy();

#endif