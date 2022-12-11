#include "chashmap.h"

void mapInit(Hashmap* map) {
    map->length = 0;

    map->HashmapEntries = malloc(sizeof(HashmapEntry*) * DEFAULT_SEGMENT_LENGTH);

    for(int i = 0; i < DEFAULT_SEGMENT_LENGTH; ++i) {
        map->HashmapEntries[i] = NULL;
    }
}
