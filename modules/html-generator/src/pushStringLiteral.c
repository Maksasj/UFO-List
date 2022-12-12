#include "html-generator.h"
#include <stdlib.h>
#include <string.h>

void pushStringLiteral(Node *node, char *str){
    node->nodeType=STRING_LITERAL;
    node->value=str;
}