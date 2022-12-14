#include "chashmap.h"
#include "chashmapPrivate.h"

unsigned int chashmapHash(const char* key) {
    long int value = 0;
    size_t keyLen = strlen(key);

    for(size_t i = 0; i < keyLen; ++i) {
        value = value * 38 + key[i];
    }

    return value;
}
