#ifndef CHASHMAP_H
#define CHASHMAP_H

#include <stdlib.h>
#include <string.h>

typedef struct HashmapEntry {
    char* key;
    void* value;

    /* Pointer to next element */
    void* next;
} HashmapEntry;

typedef struct Hashmap {
    /* Amount of elements in HashmapEntry*/
    const long segment_length;

    /* Actual array of hashmap entries */
    void* HashmapEntry;

    /* Byte size */
    size_t size;

    /* Amount of elements */
    size_t length;
} Hashmap;

void mapInit(Hashmap* map);

void* mapInsert(Hashmap* map, char* key, char* value);

void mapGetValue(Hashmap* map, char* key);

int mapKeyExist(Hashmap* map, char* key);

void mapFree(Hashmap* map);

unsigned int chashmapHash(const char* key);

/*
Hashmap hm;
mapInit(&hm);
    mapInsert(&hm, "key1", "value1");
    mapInsert(&hm, "key2", "value2");
    mapInsert(&hm, "key3", "value3");
mapFree()

char* value = mapGet(&hm, "key1");

mapKeyExist(&hm, "key2");

*/

#endif
