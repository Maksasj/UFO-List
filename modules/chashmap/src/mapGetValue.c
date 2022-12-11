#include "chashmap.h"
#include <string.h>

void* mapGetValue(Hashmap* map, char* key) {
    unsigned int hash = chashmapHash(key) % KEY_HASH_LENGTH;

    HashmapEntry* prev = map->HashmapEntries[hash];

    while (1) {
        if(prev == NULL)
            return NULL;

        if(strcmp(prev->key, key) == 0)
            return prev->value;

        prev = prev->next;
    }
    
    return NULL;
}