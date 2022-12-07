// Author: Artiom Tretjakovas
// Description: This is file, which contains all available predicates. User of this library should use them from there,
//              not from other files.

#ifndef GCLADOS_PREDICATE_NAMESPACE_H
#define GCLADOS_PREDICATE_NAMESPACE_H

#include <stdlib.h>

#include "predicate.h"

#define NUMBER_PREDICATE_DEFINITIONS(name, type)                                                                       \
    /* This predicate checks if received value is equal to expected. */                                                \
    GcladosPredicate (*toEqual##name)(type value);                                                                     \
    /* This predicate checks if received value is less than expected. */                                               \
    GcladosPredicate (*toBeLessThan##name)(type value);                                                                \
    /* This predicate checks if received value is greater than expected. */                                            \
    GcladosPredicate (*toBeGreaterThan##name)(type value);                                                             \
    /* This predicate checks if received value is less than or equal to expected. */                                   \
    GcladosPredicate (*toBeLessThanOrEqual##name)(type value);                                                         \
    /* This predicate checks if received value is greater than or equal to expected. */                                \
    GcladosPredicate (*toBeGreaterThanOrEqual##name)(type value);

#define FLOAT_PREDICATE_DEFINITIONS(name, type)                                                                        \
    /* This predicate checks if received value is equal to expected with some precision. If you want to check if       \
     * values are equal strictly (0.3 == 0.3), then specify corresponding EPSILON from "float.h" file.*/               \
    GcladosPredicate (*toEqual##name)(type value, type precision);                                                     \
    /* This predicate checks if received value is less than expected. */                                               \
    GcladosPredicate (*toBeLessThan##name)(type value);                                                                \
    /* This predicate checks if received value is greater than expected. */                                            \
    GcladosPredicate (*toBeGreaterThan##name)(type value);

// This structure contains all available predicates.
typedef struct {
    // Number predicates

    NUMBER_PREDICATE_DEFINITIONS(Char, signed char)
    NUMBER_PREDICATE_DEFINITIONS(UnsignedChar, unsigned char)
    NUMBER_PREDICATE_DEFINITIONS(Short, signed short)
    NUMBER_PREDICATE_DEFINITIONS(UnsignedShort, unsigned short)
    NUMBER_PREDICATE_DEFINITIONS(Int, signed int)
    NUMBER_PREDICATE_DEFINITIONS(Unsigned, unsigned int)
    NUMBER_PREDICATE_DEFINITIONS(Long, signed long)
    NUMBER_PREDICATE_DEFINITIONS(UnsignedLong, unsigned long)

    // Float predicates

    FLOAT_PREDICATE_DEFINITIONS(Float, float)
    FLOAT_PREDICATE_DEFINITIONS(Double, double)
    FLOAT_PREDICATE_DEFINITIONS(LongDouble, long double)

    // String predicates

    // This predicate checks if received string is equal to expected.
    GcladosPredicate (*toEqualString)(char *string);

    // Boolean predicates

    // This predicate checks if received value is equal to true from <stdbool.h>
    GcladosPredicate (*toBeTruthy)();
    // This predicate checks if received value is equal to false from <stdbool.h>
    GcladosPredicate (*toBeFalsy)();

    // Byte / pointer predicates

    // This predicate checks if received value is equal to expected by comparing N bytes.
    GcladosPredicate (*toEqualBytes)(void *bytes, size_t n);
    // TODO: add description
    GcladosPredicate (*toMatchSnapshot)(size_t size);

    // Array predicates

    // This predicate checks if all elements from received array satisfy given predicate.
    GcladosPredicate (*each)(GcladosPredicate predicate, size_t elementSize, size_t arrayLength);

    // Miscellaneous

    // This predicate inverts output of specified predicate.
    GcladosPredicate (*not )(GcladosPredicate predicate);
} GcladosPredicateNamespace;

#undef NUMBER_PREDICATE_DEFINITIONS
#undef FLOAT_PREDICATE_DEFINITIONS

// Variable, containing all predicates. Used as namespace.
extern GcladosPredicateNamespace gclados;

#endif
