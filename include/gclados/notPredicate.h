// Author: Artiom Tretjakovas
// Description: This file contains not predicate.

#ifndef GCLADOS_NOT_PREDICATE_H
#define GCLADOS_NOT_PREDICATE_H

#include "predicate.h"

// Function, which creates predicate, that inverts previous predicate result.
GcladosPredicate gcladosNot(GcladosPredicate predicate);

#endif
