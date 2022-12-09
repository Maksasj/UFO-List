#include <stdio.h>
#include "chashmap.h"

int main() {
    Hashmap hm;
    mapInit(&hm);

    mapInsert(&hm, "key1", "value1");
    mapInsert(&hm, "key2", "value2");
    mapInsert(&hm, "key3", "value3");
    mapInsert(&hm, "key4", "value4");
    mapInsert(&hm, "key5", "value5");
    mapInsert(&hm, "key6", "value6");

    char* value = mapGetValue(&hm, "pooggers");
    char* helloWorld = mapGetValue(&hm, "key1");

    FOREACH_ENTRY(hm, entry) {
        printf("%s \n", entry->key);
    }

    if(mapKeyExist(&hm, "pooggers"))
        printf("Key pooggers exist \n");

    if(!mapKeyExist(&hm, "pooogers"))
        printf("Key pooogers does not exist \n");


    return 0;
}
