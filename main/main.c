#include <stdio.h>
#include "chashmap.h"

int main() {
    Hashmap hm;
    mapInit(&hm);

    mapInsert(&hm, "pooggers", "value1");
    mapInsert(&hm, "pooggers", "value5");

    mapInsert(&hm, "key1", "hello world");

    char* value = mapGetValue(&hm, "pooggers");
    char* helloWorld = mapGetValue(&hm, "key1");

    // >value5
    printf("%s \n", value);

    // >hello world
    printf("%s \n", helloWorld);

    if(mapKeyExist(&hm, "pooggers"))
        printf("Key pooggers exist \n");

    if(!mapKeyExist(&hm, "pooogers"))
        printf("Key pooogers does not exist \n");

    return 0;
}
