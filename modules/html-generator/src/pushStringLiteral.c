#include "html-generator.h"
#include <stdlib.h>
#include <string.h>

void pushStringLiteral(Node *node, char *str) {
    node->nodeType = STRING_LITERAL;

    char stringLiteralKey[] = "value=";
    char *parsedString = malloc(strlen(str) + strlen(stringLiteralKey));
    strcpy(parsedString, stringLiteralKey);
    strcat(parsedString, str);

    node->attributes = parsedString;
}