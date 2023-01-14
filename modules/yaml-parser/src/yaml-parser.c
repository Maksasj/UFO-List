#include "yaml-parser.h"

char** splitIntoYamlStrings(char* string, int* length_out) {
    int arra = 0;

    (*length_out) = 1;
    char** array = malloc(sizeof(char*));
    
    int tmp_string_length = 1;
    char* tmp_string = malloc(sizeof(char));
    
    for(int i = 0; i <= strlen(string); ++i) {
        char character = string[i];

        if(character == '\n' || character == '\0') {
            tmp_string[tmp_string_length - 1] = '\0';

            array[(*length_out) - 1] = malloc(sizeof(char)*(strlen(tmp_string) + 1));
            strcpy(array[(*length_out) - 1], tmp_string);
            ++(*length_out);

            array = realloc(array, sizeof(char*)*(*length_out));

            free(tmp_string);
            tmp_string_length = 1;
            tmp_string = malloc(sizeof(char)*tmp_string_length);
        } else {
            tmp_string[tmp_string_length - 1] = character;
            tmp_string = realloc(tmp_string, sizeof(char)*(tmp_string_length + 1));
            ++tmp_string_length;
        }
    }

    --(*length_out);
    return array;
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

    int tmp_spaces = 0;
    for(int i = 0; i < len; ++i) {
        char character = string[i];

        if(character != '\t' && character != ' ')
            break;

        if(character == '\t')
            tabs++;

        if(character == ' ')
            ++tmp_spaces;
    }

    tabs += tmp_spaces / DEFUALT_AMOUNT_OF_SPACES_FOR_ONE_TAB;

    return tabs;
}

char *yamlStrCat(char *a, char *b) {
  char *p, *q, *rtn;
  rtn = q = malloc(strlen(a) + strlen(b) + 1);
  for (p = a; (*q = *p) != '\0'; ++p, ++q) {}
  for (p = b; (*q = *p) != '\0'; ++p, ++q) {}
  return rtn;
}

char* getKeyFromYamlString(char* string) {
    char* out = malloc(sizeof(char));
    int out_size = 0;

    for(int i = 0; strlen(string); ++i) {
        if(string[i] == ':' || string[i] == '\0') break;
        if(string[i] == ' ' || string[i] == '\t') continue;

        out[out_size] = string[i];
        out = realloc(out, out_size);
        ++out_size;
    }

    out[out_size] = '\0';

    return out;
}

char* getValueFromYamlString(char* string) {
    char* out = malloc(sizeof(char));
    int out_size = 0;
    
    int start_index = 0;
    for(int i = 0; i < strlen(string); ++i) {
        ++start_index;
        if(string[i] == ':') break;
    }

    for(int i = start_index; i < strlen(string); ++i) {
        if(string[i] != ' ') break;
        ++start_index;
    }

    for(int i = start_index; i < strlen(string); ++i) {
        out[out_size] = string[i];
        out = realloc(out, out_size);
        ++out_size;
    }

    out[out_size] = '\0';

    return out;
}


char* getValueFromYamlArrayStringElement(char* string) {
    char* out = malloc(sizeof(char));
    int out_size = 0;
    
    int start_index = 0;
    for(int i = 0; i < strlen(string); ++i) {
        if(string[i] != ' ' && string[i] != '-' && string[i] != '\t') break;
        ++start_index;
    }

    for(int i = start_index; i < strlen(string); ++i) {
        out[out_size] = string[i];
        out = realloc(out, out_size);
        ++out_size;
    }

    out[out_size] = '\0';

    return out;
}

int countDigits(int n) {  
    int counter = 0;

    while(n != 0) {  
        n = n / 10;  
        counter++;  
    }
    
    return counter;  
}  

void findValues(Hashmap* hashmap, char* prev_key, int current_index, int prev_index, char** array, int array_length) {
    int last_flag = 0;

    for(int i = current_index; i < array_length - 1; ++i) {
        int current_level = countTabs(array[current_index]);
        int next_level = countTabs(array[i + 1]);

        if(next_level == current_level && current_level == (countTabs(array[current_index + 1]))) {
            char* current_key = getKeyFromYamlString(array[current_index]);
            char* value = NULL;

            if(isArrayElement(current_key)) {
                free(current_key);

                int array_element_index = current_index - prev_index - 1;
                current_key = malloc(sizeof(char) * (countDigits(array_element_index)));
                sprintf(current_key, "[%d]", array_element_index);

                value = getValueFromYamlArrayStringElement(array[current_index]);
            } else {
                value = getValueFromYamlString(array[current_index]);
            }
            
            char* new_key = yamlStrCat(prev_key, current_key);

            YamlToken* token = malloc(sizeof(YamlToken));
            token->type = STRING;
            token->value = value;
            
            mapInsert(hashmap, new_key, token);
            return;
        }

        if(next_level == current_level + 1) {
            char* current_key = getKeyFromYamlString(array[current_index]);
            char* new_key = yamlStrCat(prev_key, current_key);

            findValues(hashmap, new_key, i + 1, current_index, array, array_length);
            last_flag = 1;
        }
    }

    if(!last_flag) {
        char* current_key = getKeyFromYamlString(array[current_index]);
        char* value = NULL;

        if(isArrayElement(current_key)) {
            free(current_key);

            int array_element_index = current_index - prev_index - 1;
            current_key = malloc(sizeof(char) * (countDigits(array_element_index)));
            sprintf(current_key, "[%d]", array_element_index);

            value = getValueFromYamlArrayStringElement(array[current_index]);
        } else {
            value = getValueFromYamlString(array[current_index]);
        }
        
        char* new_key = yamlStrCat(prev_key, current_key);

        YamlToken* token = malloc(sizeof(YamlToken));
        token->type = STRING;
        token->value = value;
        
        mapInsert(hashmap, new_key, token);
    }
}

void parseYaml(Hashmap *hm, char* string) {
    int length = 0;
    char** array = splitIntoYamlStrings(string, &length);

    findValues(hm, "", 0, 0, array, length);
}
