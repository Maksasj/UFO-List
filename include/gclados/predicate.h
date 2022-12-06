// Author: Artiom Tretjakovas
// Description: This file contains abstract predicate structure and utilization function.

#ifndef GCLADOS_PREDICATE_H
#define GCLADOS_PREDICATE_H

#include <stdbool.h>

#include "statementContext.h"

typedef char *(*GcladosValueToStringConverter)(void *value, void *options, bool pass);

// Structure, that saves information about predicate.
typedef struct GcladosPredicate {
    // Function for executing predicate.
    // Parameters:
    //     value   - received value.
    //     options - options, that are saved in this structure.
    bool (*execute)(StatementContext context, void *value, void *options);
    // String which describes how to use predicate.
    char *usage;
    // Boolean, used to determine should gclados print standard output (Expected / Received) or not.
    bool customOutput;
    // Function, which converts expected value to string.
    GcladosValueToStringConverter expectedValueToString;
    // Function, which converts received value to string.
    GcladosValueToStringConverter receivedValueToString;
    // Pointer to the options object.
    void *options;
    // Custom cleanup function. Optional parameter.
    void (*free)(struct GcladosPredicate *this);
} GcladosPredicate;

// Function, which disposes given predicate.
void gcladosFreePredicate(GcladosPredicate *predicate);

#endif