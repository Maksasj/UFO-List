#ifndef GCLADOS_STATEMENT_CONTEXT_H
#define GCLADOS_STATEMENT_CONTEXT_H

#include <stddef.h>

typedef struct {
    size_t lineNumber;
    char *fileName;
    const char *functionName;
} StatementContext;

#endif
