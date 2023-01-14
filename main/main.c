#include <stdio.h>
#include "chashmap.h"
#include "yaml-parser.h"

int main() {
    char *buffer = 0;
    long length;
    FILE *f = fopen("test.yaml", "rb");

    fseek (f, 0, SEEK_END);
    length = ftell (f);
    fseek (f, 0, SEEK_SET);
    buffer = malloc (length);
    fread (buffer, 1, length, f);
    fclose (f);

    Hashmap hm;
    mapInit(&hm);
    parseYaml(&hm, buffer);

    FOREACH_ENTRY(hm, entry) {
        printf("'%s'-> '%s'\n", entry->key, ((YamlToken*) entry->value)->value);
    }

    /* Output:

    'dictionary1dictionary2key1'-> 'value1
    'dictionary1dictionary2key2'-> 'value2 
    'dictionary1dictionary2key3'-> 'value3
    'dictionary1dictionary2key4'-> 'value4
    'dictionary1dictionary2dictionary3array[0]'-> 'element1
    'dictionary1key1'-> 'value1
    'dictionary1key2'-> 'value2
    'dictionary1key3'-> 'value3
    'dictionary1dictionary2dictionary3array[1]'-> 'element2
    'dictionary1dictionary2dictionary3key1'-> 'value1
    'dictionary1dictionary2dictionary3key2'-> 'value2
    'dictionary1dictionary2dictionary3key3'-> 'value3
    'dictionary1dictionary2dictionary3array[2]'-> 'element3
    
    */

    return 0;
}
