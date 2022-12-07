// Author: Artiom Tretjakovas
// Description: This file contains function for creating / manipulating dynamically sized array.

#ifndef GCLADOS_DYNAMIC_ARRAY_H
#define GCLADOS_DYNAMIC_ARRAY_H

#include <stdlib.h>

// Structure for saving dynamic array.
typedef struct {
    void **buffer;
    size_t capacity;
    size_t length;
} GcladosDynamicArray;

// Function that creates new dynamic array.
// Dynamic array should be disposed after using it by calling gcladosFreeDynamicArray.
GcladosDynamicArray *gcladosCreateDynamicArray();
// Function, that returns pointer to the value on specified index.
void *gcladosGet(GcladosDynamicArray *array, size_t index);
// Function, that adds new element to the dynamic array.
void gcladosPush(GcladosDynamicArray *array, void *element);
// Function, that sets element of dynamic array. Not changes dataBytes of dynamic array.
void gcladosSet(GcladosDynamicArray *array, size_t index, void *element);
// Function for utilizing dynamic array.
void gcladosFreeDynamicArray(GcladosDynamicArray *array);

#endif
