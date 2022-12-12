#include "html-generator.h"
#include <stdlib.h>
#include <string.h>

Node *pushChildrenNode(Node *node, char *tag, char *attributes) {
    Node *child_node = initNode(tag, attributes);
    if (node->childrenSize == node->childrenCapacity) {
        node->children =
            realloc(node->children,
                    sizeof(Node) * node->childrenSize + 5 * sizeof(Node));
        node->childrenCapacity += 5;
    }
    node->children[node->childrenSize] = *child_node;
    node->childrenSize += 1;
    return child_node;
}