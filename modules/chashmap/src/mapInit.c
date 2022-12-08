#include "chashmap.h"

void mapInit(Hashmap* map) {
    map->length = 0;
    map->size = 0;

    map->segment_length = DEFAULT_SEGMENT_LENGTH;

    map->HashmapEntries = malloc(sizeof(HashmapEntry*) * map->segment_length);
}
