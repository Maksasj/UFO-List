/**
 * html-generator
 *
 * @authors
 * Aleksandras Sukelovic, Maksimas Jaroslavcevas, Oskaras Vistorskis, Kamile
 Balzekaite
 *
 * @brief
 * This library provides API to create HTML nodes tree and render it in a
 provided stream.
 *
 * @example
 *  int main() {
        Node *html = initDefaultHTMLNode();
        Node *body = html->children[1];

        Node *container = pushChildrenNode(body, "div",
        "class=\"page-container\"");

        pushStringLiteral(container, "hello world");

        Node *script = pushChildrenNode(body, "script", "src=\"./index.js\"");

        FILE *file = fopen("hello.txt", "w");
        if (file != NULL) {
            renderToStream(html, file);

            fclose(file);
        }

        freeNode(html);
    }
 *
*/

#ifndef HTML_GENERATOR_H
#define HTML_GENERATOR_H

#include <stdio.h>
#include <stdlib.h>

#define ALLOCATED_MEMORY_INCREMENT 5

/* Node type is used to determine STRING_LITERAL node */
typedef enum { HTML_TAG, STRING_LITERAL } NodeType;

typedef struct Node {
    /* Array of children nodes */
    size_t childrenSize;
    size_t childrenCapacity;

    NodeType nodeType;
    /* Tag of html node. In case of STRING_LITERAL, it is empty. */
    char *tag;
    /* Html node attributes. In case of STRING_LITERAL, this is value of string. */
    char *attributes;
} Node;

// Core API

/**
 * Initializes node with given tag and attributes
 * 
 * @param   tag         Tag to be rendered for this node
 * @param   attributes  Attributes to be rendered for this node
 * @return  Pointer to new initialized node
*/
Node *initNode(char *tag, char *attributes);

/**
 * Pushed new node (with given tag and attributes) in given node.
 * 
 * @param   node        Parent node where to push new node
 * @param   tag         Tag of new children node
 * @param   attributes  Attributes of new children node
 * @return  Pointer to new created node
*/
Node *pushChildrenNode(Node *node, char *tag, char *attributes);

/**
 * Pushes given string literal str in given node.
 * 
 * @param   node    Parent node where to push string literal
 * @param   str     String literal value
*/
void pushStringLiteral(Node *node, char *str);

/**
 * Writes HTML code in a given stream
 * 
 * @param   node    Root node of HTML tree
 * @param   stream  Stream where to write HTML code
*/
void renderToStream(Node *node, FILE *stream);

/**
 * Free dynamically allocated memory for html node tree
 * 
 * @param   node    Root node of HTML tree where to start free allocated memory
*/
void freeNode(Node *node);

// Helper functions

/**
 * Initialized default HTML node:
    <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Document</title>
    </head>
    <body>
        
    </body>
    </html>

    @return Pointer to root html node
*/
Node *initDefaultHTMLNode();

#endif
