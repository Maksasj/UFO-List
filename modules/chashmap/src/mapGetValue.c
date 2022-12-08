#include "chashmap.h"
#include <string.h>

void* mapGetValue(Hashmap* map, char* key) {
    unsigned int hash = chashmapHash(key) % map->segment_length;

    HashmapEntry* prev = map->HashmapEntries[hash];

    while (1) {
        if(strcmp(prev->key, key) == 0)
            return prev->value;

        if(prev->next == NULL)
            return NULL;

        prev = prev->next;
    }
    
    return NULL;
}