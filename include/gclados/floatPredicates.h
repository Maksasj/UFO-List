// Author: Artiom Tretjakovas
// Description: This file contains predicates for testing values of types float, double or long double.

#ifndef GCLADOS_FLOAT_PREDICATES_H
#define GCLADOS_FLOAT_PREDICATES_H

#include "predicate.h"

#define FLOAT_PREDICATE_DEFINITIONS(name, type)                                                                        \
    /* This predicate checks if received value equals to expected value with specified precision. To match value       \
     * exactly, specify corresponding EPSILON from "float.h" */                                                        \
    GcladosPredicate gcladosToEqual##name(type value, type precision);                                                 \
    /* This predicate checks if received value is less than expected. */                                               \
    GcladosPredicate gcladosToBeLessThan##name(type value);                                                            \
    /* This predicate checks if received value is greater than expected. */                                            \
    GcladosPredicate gcladosToBeGreaterThan##name(type value);


// Predicates are described using macros, to avoid code duplication - code for all float-like values is the same, only
// type of variables differ.
// Macros are disposed at the end of file.

FLOAT_PREDICATE_DEFINITIONS(Float, float)
FLOAT_PREDICATE_DEFINITIONS(Double, double)
FLOAT_PREDICATE_DEFINITIONS(LongDouble, long double)

#undef FLOAT_PREDICATE_DEFINITIONS

#endif