#include "chashmap.h"

void mapEntryFree(HashmapEntry* entry) {
    free(entry->key);
    free(entry->value);

    if(entry->next != NULL) {
        mapEntryFree(entry->next);
        free(entry->next);
    }

    free(entry);
}

void mapFree(Hashmap* map) {
    for(int i = 0; i < DEFAULT_SEGMENT_LENGTH; ++i) {
        HashmapEntry* entry = map->HashmapEntries[i];
        if(entry != NULL) {
            mapEntryFree(entry);   
        }

        free(map->HashmapEntries[i]);
    }

    free(map->HashmapEntries);
    free(map);
}
