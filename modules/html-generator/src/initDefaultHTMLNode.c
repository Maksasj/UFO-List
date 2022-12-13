#include "html-generator.h"

Node *initDefaultHTMLNode() {
    Node *node = initNode("html", "");
    pushChildrenNode(node, "head", "");
    pushChildrenNode(node, "body", "");

    return node;
}
