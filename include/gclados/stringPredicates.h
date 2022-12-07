// Author: Artiom Tretjakovas
// Description: This file contains predicates for checking specified string.

#ifndef GCLADOS_STRING_PREDICATES_H
#define GCLADOS_STRING_PREDICATES_H

#include "predicate.h"

// This predicate checks if received string is equal to expected. Calls strcmp from <string.h>
GcladosPredicate gcladosToEqualString(char *string);

#endif
