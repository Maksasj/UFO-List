#ifndef HTML_GENERATOR_H
#define HTML_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>

typedef enum { HTML_TAG, STRING_LITERAL } NodeType;

typedef struct {
    struct Node *children;
    size_t childrenSize;

    NodeType nodeType;
    char *tag;
    /*
        TODO: use Map structure for attributes

        If nodeType is STRING_LITERAL then save string literal
        in attributes, like "value=string"
    */
    char *attributes;
} Node;

// Core API
Node *initNode(char *tag, char *attributes);

Node *pushChildrenNode(Node *node, char *tag, char *attributes);
void pushStringLiteral(Node *node, char *str);

void renderToStream(Node *node, FILE *stream);

void freeNode(Node *node);

// Helper functions
Node *initDefaultHTMLNode();

// Example usage:
// int main() {
//     Node *html = initNode("html", "");
//     Node *head = pushChildrenNode(html, "head", "");
//     Node *body = pushChildrenNode(html, "body", "");

//     Node *container = pushChildrenNode(body, "div",
//     "class=\"page-container\"");

//     // push contents in container
//     pushStringLiteral(container, "hello world");

//     // TODO: What if user pushes node in string literal?
//     // pushChildrenNode(container->children[0], "div", "");

//     Node *script = pushChildrenNode(body, "script", "src=\"./index.js\"");

//     FILE *file = fopen("hello.txt", "w");
//     if (file != NULL) {
//         renderToStream(html, file);
//     }
// }

#endif
