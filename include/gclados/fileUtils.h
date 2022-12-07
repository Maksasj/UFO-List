#ifndef GCLADOS_FILE_UTILS_H
#define GCLADOS_FILE_UTILS_H

#include <stdio.h>

void gcladosEnsureFileExists(const char filename[]);
void gcladosMoveBlock(FILE *file, long n);

#endif
