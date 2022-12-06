#ifndef HTML_GENERATOR_H
#define HTML_GENERATOR_H

#include <stdlib.h>

typedef struct {
    struct Node *children;
    size_t childrenSize;
    char *tag;
    char *attributes;
    // char *(*renderToString)(Node);
} Node;

// Core API
Node *initNode(char *tag, char *attributes);
Node *pushChildrenNode(Node *node, char *tag, char *attributes);
char *renderToString(Node *node);

void freeNode(Node *node);

// Helper functions
Node *initDefaultHTMLNode();

void test();

// Example usage:
// int main() {
//     Node *htmlNode = initNode("hmtl", "");
//     Node *bodyNode = pushChildrenNode(htmlNode, "body", "");
//     Node *container = pushChildrenNode(bodyNode, "div",
//     "class=\"container\"");

//     FILE *file = fopen("hello.txt", "w");
//     if (file != NULL) {
//         fprintf(file, "%s", renderToString(htmlNode));
//     }
// }

#endif
