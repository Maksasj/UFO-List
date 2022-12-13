#include "html-generator.h"
#include <stdlib.h>

void freeNode(Node *node) {
    for (int i = 0; i < node->childrenSize; ++i) {
        freeNode(&node->children[i]);
    }

    free(node->attributes);
    free(node);
}
