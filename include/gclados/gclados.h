// Author: Artiom Tretjakovas
// Description: This file is the main library entrypoint. It contains main macros and entrypoint functions.

#ifndef GCLADOS_LIB_H
#define GCLADOS_LIB_H

#include "colors.h"
#include "panic.h"
#include "predicateNamespace.h"
#include "statement.h"
#include "test.h"
#include "testSuite.h"

void gcladosSetUpdateSnapshots(bool updateSnapshots);

// Function, which is used to run all test suites.
// Parameters:
//     suites[] - array of test suites.
//     count   - the dataBytes of suites array.
// Returns:
//     Test status code. EXIT_SUCCESS on success, EXIT_FAILURE when some tests failed and others if unexpected errors
//     occurred.
int gcladosRunTestSuites(GcladosTestSuite suites[], size_t count);

#define GCLADOS_CONCAT(a, b) GCLADOS_CONCAT_INNER(a, b)
#define GCLADOS_CONCAT_INNER(a, b) a##b
#define GCLADOS_ENSURE_INNER(varName, value, predicate)                                                                \
    typeof(value)(varName) = value;                                                                                    \
    gcladosCreateStatement(__FUNCTION__, __LINE__, __FILE__, &(varName), predicate)
#define GCLADOS_ENSURE_ARRAY_INNER(varName, value, predicate)                                                          \
    typeof((value)[0]) *(varName) = value;                                                                             \
    gcladosCreateStatement(__FUNCTION__, __LINE__, __FILE__, &(varName), predicate);

// Prefix for all tests. This is required to avoid naming conflicts.
// For example, if user has function "sum", when writing TEST(sum) the names could conflict. To prevent that, test name
// will be __gcladosTest_sum.
#define GCLADOS_TEST_PREFIX __gcladosTest_
// Function, which is "assert" from <assert.h> analogue. The difference between these two function is that ensure
// accepts value as first parameter and predicate as second. To see the list of all available predicates, see
// "predicateNamespace.h" file.
// The several macros which are defined above are required to wrap specified value into a
// pointer. The value will be saved in pointer of type void, which allows user to write their own predicates for custom
// types (for example, structures).
#define ensure(value, predicate) GCLADOS_ENSURE_INNER(GCLADOS_CONCAT(__gcladosValue, __COUNTER__), value, predicate)
// This function works the same as "ensure" function. One slight difference, is that it is wrapping array into pointer.
// It is required because C does not allow assigning one array to another.
// For example, this code will not compile:
//     int a[] = { 1, 2, 3 };
//     ensure(a, ...);
// Because it unwraps to:
//     int a[] = { 1, 2, 3 };
//     typeof(a) *__gcladosValue0 = a;
//     ...
// What is equal to:
//     int a[] = { 1, 2, 3 };
//     int *__gcladosValue[3] = a;
// Also, this solution avoids double pointers.
#define ensureArray(value, predicate)                                                                                  \
    GCLADOS_ENSURE_ARRAY_INNER(GCLADOS_CONCAT(__gcladosValue, __COUNTER__), value, predicate)

// Macro, for defining test case.
// Usage:
//     TEST(testName) {
//         // your assertions
//         ensure(...);
//     };
#define TEST(testName)                                                                                                 \
    void GCLADOS_CONCAT(__gcladosTestExecutor_, testName)(void);                                                       \
    GcladosTest GCLADOS_CONCAT(GCLADOS_TEST_PREFIX, testName)(char *description) {                                     \
        return gcladosCreateTest(GCLADOS_CONCAT(__gcladosTestExecutor_, testName), description);                       \
    };                                                                                                                 \
    void GCLADOS_CONCAT(__gcladosTestExecutor_, testName)(void)

#endif