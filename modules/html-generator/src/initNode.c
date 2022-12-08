#include "html-generator.h"
#include <stdlib.h>
#include <string.h>

Node *initNode(char *tag, char *attributes) {
    Node *node = malloc(sizeof(Node));

    node->children = NULL;
    node->childrenSize = 0;

    node->nodeType = HTML_TAG;

    node->tag = tag;
    node->attributes = attributes;

    return node;
};
