/**
 * chashmap
 *
 * @authors
 * Maksimas Jaroslavcevas
 *
 * @brief
 * This library provides simple API to create and interact with Hash tables.
 *
 * @example
 *  int main() {
        Hashmap hm;
        mapInit(&hm);

        mapInsert(&hm, "key1", "Hello world");
        mapInsert(&hm, "key2", "value2");

        char* helloWorld = mapGetValue(&hm, "key1");

        if(mapKeyExist(&hm, "key2"))
            printf("Key 'key2' exist \n");

        if(!mapKeyExist(&hm, "randomkey"))
            printf("Key randomkey does not exist \n");

        mapFree(&hm);
    }
 *
*/


#ifndef CHASHMAP_H
#define CHASHMAP_H

#define KEY_HASH_LENGTH 100

#include <stdlib.h>
#include <string.h>

/* Structure what contains a single entry of the hashmap */
typedef struct HashmapEntry {
    /* Key of the entry */
    char* key;
    
    /* Value of the entry */
    void* value;

    /* Pointer to next element */
    struct HashmapEntry* next;
} HashmapEntry;

typedef struct Hashmap {
    /* Array of linked lists */
    HashmapEntry** HashmapEntries;

    /* Amount of elements */
    size_t length;
} Hashmap;

// Core API

/**
 * Initializes empty hashmap at the given pointer
 * 
 * @param   map         Actual pointer to hashmap
*/
void mapInit(Hashmap* map);

/**
 * Inserts new value to the hashmap
 * 
 * @param   map         Pointer to hashmap
 * @param   key         Key where to insert the value
 * @param   value       Actual value to be inserted
 * @return  Pointer to new hashmap entry
*/
HashmapEntry* mapInsert(Hashmap* map, char* key, void* value);

/**
 * Returns pointer to value of entry located at this key.
 * 
 * @param   map         Pointer to hashmap
 * @param   key         Key where expected entry is located
 * @return  Pointer to value or NULL if entry with provided key failed to find
*/
char* mapGetValue(Hashmap* map, char* key);

/**
 * Checks if provided key occurs in provided hasmap
 * 
 * @param   map         Pointer to hashmap
 * @param   key         Key where expected entry is located
 * @return  Returns 1 if such key occurs in provided hashmap otherwise returns 0
*/
int mapKeyExist(Hashmap* map, char* key);

/**
 * Free dynamically allocated memory for hashmap
 * 
 * @param   node    Pointer to hashmap where to start free allocated memory
*/
void mapFree(Hashmap* map);

/**
 * Returns next entry of the hashmap,
 * Was conceived in order to iterate over all entries of the hashmap
 * 
 * @param   node    Pointer to hashmap
 * @return  Returns pointer to next entry of the hashmap
*/
HashmapEntry* getNextEntry(Hashmap* map);

#define FOREACH_ENTRY(MAP, ENTRY)                       \
    HashmapEntry* ENTRY;                                \
    while((ENTRY = getNextEntry(&hm)) && ENTRY != NULL) \

#endif
