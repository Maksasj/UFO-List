#ifndef CHASHMAP_H
#define CHASHMAP_H

#define DEFAULT_SEGMENT_LENGTH 100

#include <stdlib.h>
#include <string.h>

typedef struct HashmapEntry {
    char* key;
    char* value;

    /* Pointer to next element */
    void* next;
} HashmapEntry;

typedef struct Hashmap {
    /* Amount of elements in HashmapEntry*/
    long segment_length;

    /* Actual array of hashmap entries */
    void** HashmapEntries;

    /* Byte size */
    size_t size;

    /* Amount of elements */
    size_t length;
} Hashmap;

void mapInit(Hashmap* map);

void* mapInsert(Hashmap* map, char* key, char* value);

void* mapGetValue(Hashmap* map, char* key);

int mapKeyExist(Hashmap* map, char* key);

void mapFree(Hashmap* map);

unsigned int chashmapHash(const char* key);

HashmapEntry* getNextEntry(Hashmap* map);

#define FOREACH_ENTRY(MAP, ENTRY)                       \
    HashmapEntry* ENTRY;                                \
    while((ENTRY = getNextEntry(&hm)) && ENTRY != NULL) \

/*  USAGE EXAMPLE

    Hashmap hm;
    mapInit(&hm);

    mapInsert(&hm, "key1", "value1");
    mapInsert(&hm, "key2", "value2");
    mapInsert(&hm, "key3", "value3");
    mapInsert(&hm, "key4", "value4");
    mapInsert(&hm, "key5", "value5");
    mapInsert(&hm, "key6", "value6");
    mapInsert(&hm, "key7", "value7");
    mapInsert(&hm, "key8", "value8");
    mapInsert(&hm, "key9", "value9");
    mapInsert(&hm, "key10", "value10");
    mapInsert(&hm, "key11", "value11");
    mapInsert(&hm, "key12", "value12");

    char* value = mapGetValue(&hm, "pooggers");
    char* helloWorld = mapGetValue(&hm, "key1");

    FOREACH_ENTRY(hm, entry) {
        printf("%s \n", entry->key);
    }

    if(mapKeyExist(&hm, "pooggers"))
        printf("Key pooggers exist \n");

    if(!mapKeyExist(&hm, "pooogers"))
        printf("Key pooogers does not exist \n");

*/

#endif
