#include "html-generator.h"
#include <stdlib.h>
#include <string.h>

void pushStringLiteral(Node *parentNode, char *str) {
    if (parentNode == NULL || str == NULL ||
        parentNode->nodeType == STRING_LITERAL) {
        return;
    }

    if (parentNode->childrenSize == parentNode->childrenCapacity) {
        parentNode->children =
            realloc(parentNode->children,
                    sizeof(Node) * parentNode->childrenSize +
                        ALLOCATED_MEMORY_INCREMENT * sizeof(Node));
        parentNode->childrenCapacity += ALLOCATED_MEMORY_INCREMENT;
    }

    Node *children = malloc(sizeof(Node));
    *children = (Node){.attributes = str,
                       .children = NULL,
                       .childrenSize = 0,
                       .childrenCapacity = 0,
                       .nodeType = STRING_LITERAL,
                       .tag = NULL};

    parentNode->children[parentNode->childrenSize] = children;
    ++parentNode->childrenSize;
}