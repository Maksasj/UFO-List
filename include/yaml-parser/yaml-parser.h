#ifndef YAML_PARSER_H
#define YAML_PARSER_H

#define DEFUALT_AMOUNT_OF_SPACES_FOR_ONE_TAB 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum YamlTokenValueType {
    DICTIONARY,
    ARRAY,
    STRING,
    INTEGER
} YamlTokenValueType;

typedef struct YamlToken {
    YamlTokenValueType type;

    void* value;
} YamlToken;

YamlToken* tokenizeYamlString(char* string);

void splitIntoYamlStrings(char* string);

void yamlTest();

//void wtf();

char* properConcat(char *destination, char *source);

#endif
