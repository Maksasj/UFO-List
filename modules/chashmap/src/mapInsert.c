#include "chashmap.h"

void* mapInsert(Hashmap* map, char* key, char* value) {
    unsigned int hash = chashmapHash(key) % map->segment_length;

    if(map->HashmapEntries[hash] == NULL) {
        HashmapEntry* entry = malloc(sizeof(HashmapEntry));

        entry->next = NULL;

        entry->key = malloc(sizeof(char) * strlen(key));
        strcpy(entry->key, key);

        entry->value = malloc(sizeof(char) * strlen(value));
        strcpy(entry->value, value);

        map->HashmapEntries[hash] = entry;
        return entry;
    }

    HashmapEntry* prev = map->HashmapEntries[hash];

    while (1) {
        if(strcmp(prev->key, key) == 0) {
            HashmapEntry* entry = prev;

            entry->key = malloc(sizeof(char) * strlen(key));
            strcpy(entry->key, key);

            entry->value = malloc(sizeof(char) * strlen(value));
            strcpy(entry->value, value);

            return entry;
        }

        if(prev->next == NULL) {
            prev->next = malloc(sizeof(HashmapEntry));
            HashmapEntry* entry = prev->next;

            entry->next = NULL;

            entry->key = malloc(sizeof(char) * strlen(key));
            strcpy(entry->key, key);

            entry->value = malloc(sizeof(char) * strlen(value));
            strcpy(entry->value, value);

            return entry;
        }

        prev = prev->next;
    }    
    return NULL;
}
