#include <stdio.h>
#include "chashmap.h"

int main() {
    Hashmap hm;
    mapInit(&hm);
    mapInsert(&hm, "pooggers", "value1");
    mapInsert(&hm, "pooggers", "value2");
    mapInsert(&hm, "pooggers", "value3");
    for(int i = 0; i < hm.segment_length; ++i) {
        HashmapEntry* child = hm.HashmapEntries[i];
        
        printf("%p ", child);

        if(child != NULL) {
            HashmapEntry* child1 = child->next;

            printf("%p ", child1);

            if(child1 != NULL) {

                HashmapEntry* child2 = child1->next;
                printf("%p ", child2);

                if(child2 != NULL) {

                    HashmapEntry* child3 = child1->next;
                    printf("%p ", child3);
                }
            }
        }


        printf("\n");
    }


    //printf(((HashmapEntry*) hm.HashmapEntries[7])->key);
    //printf(((HashmapEntry*) hm.HashmapEntries[7])->value);

    printf("hello world!");

    return 0;
}
