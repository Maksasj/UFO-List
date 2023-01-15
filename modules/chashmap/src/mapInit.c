#include "chashmap.h"

void mapInit(Hashmap *map) {
    map->length = 0;

    map->HashmapEntries = malloc(sizeof(HashmapEntry *) * KEY_HASH_LENGTH);

    for (int i = 0; i < KEY_HASH_LENGTH; ++i) {
        map->HashmapEntries[i] = NULL;
    }
}
