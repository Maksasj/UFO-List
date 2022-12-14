#include "html-generator.h"
#include <stdlib.h>
#include <string.h>

Node *pushChildrenNode(Node *node, char *tag, char *attributes) {
    if (node == NULL || tag == NULL || attributes == NULL ||
        node->nodeType == STRING_LITERAL) {
        return NULL;
    }

    Node *child_node = initNode(tag, attributes);
    if (node->childrenSize == node->childrenCapacity) {
        node->children = realloc(node->children,
                                 sizeof(Node) * node->childrenSize +
                                     ALLOCATED_MEMORY_INCREMENT * sizeof(Node));
        node->childrenCapacity += ALLOCATED_MEMORY_INCREMENT;
    }
    node->children[node->childrenSize] = child_node;
    node->childrenSize += 1;
    return child_node;
}