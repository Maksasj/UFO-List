#include "chashmap.h"

static inline HashmapEntry* initEntry(char* key, char* value) {
    HashmapEntry* entry = malloc(sizeof(HashmapEntry));

    entry->next = NULL;

    entry->key = malloc(sizeof(char) * strlen(key));
    strcpy(entry->key, key);

    entry->value = malloc(sizeof(char) * strlen(value));
    strcpy(entry->value, value);

    return entry;
}

static inline void initEntryTo(HashmapEntry* to, char* key, char* value) {
    HashmapEntry* entry = to;

    entry->key = malloc(sizeof(char) * strlen(key));
    strcpy(entry->key, key);

    entry->value = malloc(sizeof(char) * strlen(value));
    strcpy(entry->value, value);
}

HashmapEntry* mapInsert(Hashmap* map, char* key, char* value) {
    unsigned int hash = chashmapHash(key) % KEY_HASH_LENGTH;
    ++map->length;

    if(map->HashmapEntries[hash] == NULL) {
        HashmapEntry* entry = initEntry(key, value);
        map->HashmapEntries[hash] = entry;
        return entry;
    }

    HashmapEntry* prev = map->HashmapEntries[hash];

    while (1) {
        if(strcmp(prev->key, key) == 0) {
            initEntryTo(prev, key, value);
            return prev;
        }

        if(prev->next == NULL) {
            prev->next = malloc(sizeof(HashmapEntry));
            initEntryTo(prev->next, key, value);
            return prev->next;
        }

        prev = prev->next;
    }
    return NULL;
}
