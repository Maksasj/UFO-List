#include "yaml-parser.h"

int countDigits(int value) {  
    int counter = 0;

    while(value != 0) {  
        value = value / 10;  
        counter++;  
    }
    
    return counter;  
}

char *yamlStrCat(char *a, char *b) {
  char *p, *q, *rtn;
  rtn = q = malloc(strlen(a) + strlen(b) + 1);
  for (p = a; (*q = *p) != '\0'; ++p, ++q) {}
  for (p = b; (*q = *p) != '\0'; ++p, ++q) {}
  return rtn;
}

bool isArrayElement(char* string) {
    for(int i = 0; i < strlen(string); ++i) {
        char character = string[i];

        if(character == '-') return true;   
        if(character != ' ') break;
    }

    return false;
}

int countTabs(char* string) {
    int len = strlen(string);

    int tabs = 0;

    int tmpSpaces = 0;
    for(int i = 0; i < len; ++i) {
        char character = string[i];

        if(character != '\t' && character != ' ')
            break;

        if(character == '\t')
            tabs++;

        if(character == ' ')
            ++tmpSpaces;
    }

    tabs += tmpSpaces / DEFUALT_AMOUNT_OF_SPACES_FOR_ONE_TAB;

    return tabs;
}

char* getKeyFromYamlString(char* string) {
    char* out = malloc(sizeof(char));
    int outSize = 0;

    for(int i = 0; strlen(string); ++i) {
        if(string[i] == ':' || string[i] == '\0') break;
        if(string[i] == ' ' || string[i] == '\t') continue;

        out[outSize] = string[i];
        out = realloc(out, outSize);
        ++outSize;
    }

    out[outSize] = '\0';

    return out;
}

char* getValueFromYamlString(char* string) {
    char* out = malloc(sizeof(char));
    int outSize = 0;
    
    int startIndex = 0;
    for(int i = 0; i < strlen(string); ++i) {
        ++startIndex;
        if(string[i] == ':') break;
    }

    for(int i = startIndex; i < strlen(string); ++i) {
        if(string[i] != ' ') break;
        ++startIndex;
    }

    for(int i = startIndex; i < strlen(string); ++i) {
        out[outSize] = string[i];
        out = realloc(out, outSize);
        ++outSize;
    }

    out[outSize] = '\0';

    return out;
}


char* getValueFromYamlArrayStringElement(char* string) {
    char* out = malloc(sizeof(char));
    int outSize = 0;
    
    int startIndex = 0;
    for(int i = 0; i < strlen(string); ++i) {
        if(string[i] != ' ' && string[i] != '-' && string[i] != '\t') break;
        ++startIndex;
    }

    for(int i = startIndex; i < strlen(string); ++i) {
        out[outSize] = string[i];
        out = realloc(out, outSize);
        ++outSize;
    }

    out[outSize] = '\0';

    return out;
}

char** splitIntoYamlStrings(char* string, int* lengthOut) {
    int arra = 0;

    (*lengthOut) = 1;
    char** array = malloc(sizeof(char*));
    
    int tmp_string_length = 1;
    char* tmp_string = malloc(sizeof(char));
    
    for(int i = 0; i <= strlen(string); ++i) {
        char character = string[i];

        if(character == '\n' || character == '\0') {
            tmp_string[tmp_string_length - 1] = '\0';

            array[(*lengthOut) - 1] = malloc(sizeof(char)*(strlen(tmp_string) + 1));
            strcpy(array[(*lengthOut) - 1], tmp_string);
            ++(*lengthOut);

            array = realloc(array, sizeof(char*)*(*lengthOut));

            free(tmp_string);
            tmp_string_length = 1;
            tmp_string = malloc(sizeof(char)*tmp_string_length);
        } else {
            tmp_string[tmp_string_length - 1] = character;
            tmp_string = realloc(tmp_string, sizeof(char)*(tmp_string_length + 1));
            ++tmp_string_length;
        }
    }

    --(*lengthOut);
    return array;
}

void findValues(Hashmap* hashmap, char* prevKey, int currentIndex, int prevIndex, char** array, int arrayLength) {
    int lastFlag = 0;

    for(int i = currentIndex; i < arrayLength - 1; ++i) {
        int currentLevel = countTabs(array[currentIndex]);
        int nextLevel = countTabs(array[i + 1]);

        if(nextLevel == currentLevel && currentLevel == (countTabs(array[currentIndex + 1]))) {
            char* currentKey = getKeyFromYamlString(array[currentIndex]);
            char* value = NULL;

            if(isArrayElement(currentKey)) {
                free(currentKey);

                int arrayElementIndex = currentIndex - prevIndex - 1;
                currentKey = malloc(sizeof(char) * (countDigits(arrayElementIndex)));
                sprintf(currentKey, "[%d]", arrayElementIndex);

                value = getValueFromYamlArrayStringElement(array[currentIndex]);
            } else {
                value = getValueFromYamlString(array[currentIndex]);
            }
            
            char* newKey = yamlStrCat(prevKey, currentKey);

            YamlToken* token = malloc(sizeof(YamlToken));
            token->value = value;
            
            mapInsert(hashmap, newKey, token);
            return;
        }

        if(nextLevel == currentLevel + 1) {
            char* currentKey = getKeyFromYamlString(array[currentIndex]);
            char* newKey = yamlStrCat(prevKey, currentKey);

            findValues(hashmap, newKey, i + 1, currentIndex, array, arrayLength);
            lastFlag = 1;
        }
    }

    if(!lastFlag) {
        char* currentKey = getKeyFromYamlString(array[currentIndex]);
        char* value = NULL;

        if(isArrayElement(currentKey)) {
            free(currentKey);

            int arrayElementIndex = currentIndex - prevIndex - 1;
            currentKey = malloc(sizeof(char) * (countDigits(arrayElementIndex)));
            sprintf(currentKey, "[%d]", arrayElementIndex);

            value = getValueFromYamlArrayStringElement(array[currentIndex]);
        } else {
            value = getValueFromYamlString(array[currentIndex]);
        }
        
        char* newKey = yamlStrCat(prevKey, currentKey);

        YamlToken* token = malloc(sizeof(YamlToken));
        token->value = value;
        
        mapInsert(hashmap, newKey, token);
    }
}

void parseYaml(Hashmap *hm, char* string) {
    int length = 0;
    char** array = splitIntoYamlStrings(string, &length);

    findValues(hm, "", 0, 0, array, length);
}
