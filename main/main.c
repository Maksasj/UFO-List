#include <stdio.h>
#include "chashmap.h"
#include "yaml-parser.h"

void wtf() {
    char *destination = "Hello ";
    char source = 'p';

    printf("%s\n", properConcat(destination, &source));
}

int main() {
    char *destination = "Hello ";
    char source = 'p';

    printf("%s\n", properConcat(destination, &source));

    wtf();

    /*
    splitIntoYamlStrings(
    "foo: bar\n"
    "    pleh: help\n"
    "    stuff:\n"
    "        foo: bar\n"
    "        bar: foo"
    );
    */
    
    return 0;
}
