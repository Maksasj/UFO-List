#include "chashmap.h"
#include <string.h>

int mapKeyExist(Hashmap* map, char* key) {
    unsigned int hash = chashmapHash(key) % KEY_HASH_LENGTH;

    HashmapEntry* prev = map->HashmapEntries[hash];

    while (1) {
        if(prev == NULL)
            return 0;

        if(strcmp(prev->key, key) == 0)
            return 1;

        prev = prev->next;
    }
    
    return 0;
}
