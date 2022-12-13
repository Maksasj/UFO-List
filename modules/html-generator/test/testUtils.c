#include "gclados.h"
#include <assert.h>
#include <string.h>


void ensureStringEquality(char *str1, char *str2) {
    assert(strlen(str1) == strlen(str2));
    int i = 0;

    while (str1[i] != '\0') {
        ensure(str1[i], gclados.toEqualChar(str2[i]));
        ++i;
    }
}
