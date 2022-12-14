#include "html-generator.h"
#include <stdlib.h>

void freeNode(Node *node) {
    for (int i = 0; i < node->childrenSize; ++i) {
        freeNode(node->children[i]);
    }

    if (node->nodeType == STRING_LITERAL) {
        free(node->attributes);
    }

    free(node);
}
