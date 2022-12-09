#include "chashmap.h"
#include <stdio.h>

HashmapEntry* getNextEntry(Hashmap* map) {
    static HashmapEntry* lastEntry = NULL;
    static Hashmap* lastMap = NULL;
    static size_t lastSegement = 0;

    if(lastMap == NULL) { 
        lastMap = map;

        for(int i = 0; i < lastMap->segment_length; ++i) {
            if(lastMap->HashmapEntries[i] != NULL) {
                lastSegement = i + 1;
                lastEntry = lastMap->HashmapEntries[i]; 
                return lastMap->HashmapEntries[i];
            }
        }
    }

    if(lastEntry->next != NULL) {
        lastEntry = lastEntry->next;
        return lastEntry;
    }

    for(int i = lastSegement; i < lastMap->segment_length; ++i) {
        if(lastMap->HashmapEntries[i] != NULL) {
            lastSegement = i + 1;
            lastEntry = lastMap->HashmapEntries[i]; 
            return lastMap->HashmapEntries[i];
        }
    }

    return NULL;
}
