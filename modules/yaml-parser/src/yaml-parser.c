#include "yaml-parser.h"

char* properConcat(char *destination, char *source) {
    char* tmp = (char*)malloc( sizeof(char)*(strlen(source)+strlen(destination)));
    tmp[0] = '\0';
    strcat(tmp, destination);
    strcat(tmp, source);
    return tmp;
}
/*
void wtf() {
    char *destination = "Hello ";
    char source = 'p';

    printf("%s\n", properConcat(destination, &source));
}
*/
void splitIntoYamlStrings(char* string) {
    //char** output = malloc(sizeof(char*));
    //unsigned int stringCount = 0;
//
    //unsigned int index = 0;

    char *destination = "Hello ";
    char source = 'p';

    printf("%s\n", properConcat(destination, &source));

    //while(string[index] != '\0') {
    //    //char currentChar = string[index];
//
    //    //if(currentChar == '\n') {
    //    //    printf("Break \n");
    //    //}
//
//
    //    index++;
    //}
}

YamlToken* tokenizeYamlString(char* string) {
    unsigned int index = 0;

    while(string[index] != '\0') {
        char currentChar = string[index];


        if(currentChar == '\n') {
            printf("Break \n");
        }
        
        index++;
    }

    printf("poggers");
}

void yamlTest() {
    printf("Yaml Test\n");
}