// Author: Artiom Tretjakovas
// Description: This file contains helper function for stdin / stdout.

#ifndef GCLADOS_IO_UTILS_H
#define GCLADOS_IO_UTILS_H

#include <stdbool.h>
#include <stdio.h>

#include "colors.h"
#include "test.h"

// This function constructs failed statement message.
// Parameters:
//     pass      - statement result.
//     predicate - predicate that has failed.
//     value     - value, which have not passed the check.
// Returns:
//     String, that should be disposed after using it.
char *gcladosGetFailedStatementMessage(bool pass, GcladosPredicate predicate, void *value);
// Function, that prints progress bar to the specified file.
// Parameters:
//     file       - output stream.
//     percentage - value in range from 0 to 1, the progress.
//     width      - the width of the progress bar.
void gcladosPrintProgress(FILE *file, double percentage, size_t width);
// Function, that prints lines from the file to stdout.
// Parameters:
//     file            - file, from which lines should be read.
//     lineBegin       - beginning of file segment to be printed.
//     lineEnd         - end of file segment to be printed.
//     highlightedLine - line that should be highlighted.
void gcladosPrintFileLines(FILE *file, int lineBegin, int lineEnd, int highlightedLine);
// Function, that converts given pointer to hexadecimal string.
// Parameters:
//     ptr  - pointer to the value.
//     size - size of value, in bytes.
// Returns:
//     String, that should be disposed after using it.
char *gcladosConvertToHex(void *ptr, size_t size);
// Function, that prints time in human-readable format.
void gcladosPrintTime(clock_t time);

GcladosAnsiFlags gcladosDefaultFailureStyle();
GcladosAnsiFlags gcladosDefaultSuccessStyle();

#endif
