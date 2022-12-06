// Author: Artiom Tretjakovas
// Description: This file contains functions for executing / manipulating tests.

#ifndef GCLADOS_TEST_H
#define GCLADOS_TEST_H

#include <stdbool.h>

#include "dynamicArray.h"
#include "predicate.h"

// Function, which saves statement result.
typedef struct {
    char *failMessage;
    // Line of statement.
    int line;
    // Path to the file, where statement is located.
    char *filePath;
} GcladosStatementResult;

// Function, which contains information about test.
typedef struct {
    // Function which executes test.
    void (*execute)(void);
    // Description of test.
    const char *description;
} GcladosTest;

// Function, which contains test result.
typedef struct {
    bool pass;
    GcladosStatementResult statementResult;
} GcladosTestResult;

// Function, which creates new test.
GcladosTest gcladosCreateTest(void (*execute)(void), const char *description);
// Function which saves failed statement result and terminates test execution.
void gcladosAddStatementResult(GcladosStatementResult result);
// Function, which runs given test.
GcladosTestResult gcladosRunTest(GcladosTest test);
// Function, which prints given test.
void gcladosPrintTest(GcladosTest test, GcladosTestResult result);

#endif