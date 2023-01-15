#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void throwAllocationFailure() {
    fprintf(stderr, "Failed to allocate memory.\n");
    exit(-1);
}
