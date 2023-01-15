/**
 * Yaml parser
 *
 * @authors
 * Maksimas Jaroslavcevas
 *
 * @brief
 * This library provides simple API to parse Yaml files
 *
 * @example
 *  int main() {
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

        return 0;
    }
 *
*/

#ifndef YAML_PARSER_H
#define YAML_PARSER_H

#define DEFUALT_AMOUNT_OF_SPACES_FOR_ONE_TAB 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "chashmap.h"

/* Structure what contains a single yaml token entry */
/* TODO: implement proper token typing */
typedef struct YamlToken {
    void* value;
} YamlToken;

/* Core API */

/**
 * Counts digits in an integer
 * 
 * @param   value       Integer that digits needed to be counted
 * @return  Amount of digits in provided integer
*/
int countDigits(int value);  

/**
 * Concatenates two strings, and stores in a new one
 * 
 * @param   a       First string to be concatenated
 * @param   b       Second string to be concatenated
 * @return  Pointer to new string
*/
char *yamlStrCat(char *a, char *b);

/**
 * Checks if given yaml string is an element of the array
 * 
 * @param   string       String to be checked
 * @return  Boolean value that determines if given string is an element of yaml array
*/
bool isArrayElement(char* string);

/**
 * Counts amount of tabs before first no space symbol
 * See DEFUALT_AMOUNT_OF_SPACES_FOR_ONE_TAB for default amount of spaces in a single tab
 * 
 * @param   string       The string in which is needed to count the number of tabs
 * @return  Boolean value that determines if given string is an element of yaml array
*/
int countTabs(char* string);

/**
 * Returns key from yaml string (string before ':' symbol).
 * 
 * @param   string       Input string
 * @return  Pointer to new string, that represents given yaml element key
*/
char* getKeyFromYamlString(char* string);

/**
 * Returns value from yaml string (string after ':' symbol).
 * 
 * @param   string       Input string
 * @return  Pointer to new string, that represents given yaml element value
*/
char* getValueFromYamlString(char* string);

/**
 * Returns value from yaml string, assumed that input string it is an array element
 * 
 * @param   string       Input string
 * @return  Pointer to new string, that represents given yaml array element value
*/
char* getValueFromYamlArrayStringElement(char* string);

/**
 * Splits single string by '\n', in to array of yaml strings, where one element is an 'key':'value'
 * 
 * @param   string       Input string
 * @param   lengthOut    Pointer to integer that will store length of the given splitted array
 * @return  Pointer to array of strings
*/
char** splitIntoYamlStrings(char* string, int* lengthOut);

/**
 * Function that used for finding all values yaml key and value in given array
 * 
 * @param   hashmap         Pointer to the hasmap that used for storing data
 * @param   prevKey         Pointer to the temporary string that represents previous element key
 * @param   currentIndex    Integer that represents current index
 * @param   prevIndex       Integer that represents previous index 
 * @param   array           Pointer to array of yaml strings
 * @param   arrayLength     Length of the input string array
*/
void findValues(Hashmap* hashmap, char* prevKey, int currentIndex, int prevIndex, char** array, int arrayLength);

/**
 * Actual function that used for parsing yaml file
 * 
 * @param   hashmap         Pointer to the hasmap that used for storing data
 * @param   string          Input yaml file as a single string
*/
void parseYaml(Hashmap *hm, char* string);

#endif
