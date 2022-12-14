#include "html-generator.h"

Node *initDefaultHTMLNode() {
    Node *node = initNode("html", "");
    Node *headNode = pushChildrenNode(node, "head", "");
    pushChildrenNode(node, "body", "");

    pushChildrenNode(headNode, "meta", "charset=\"UTF-8\"");
    pushChildrenNode(headNode, "meta", "http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"");
    pushChildrenNode(headNode, "meta", "name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"");
    
    Node *documentTitle = pushChildrenNode(headNode, "title", "");
    pushStringLiteral(documentTitle, "Document");

    return node;
}
