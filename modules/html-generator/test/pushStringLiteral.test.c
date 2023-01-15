#include "gclados.h"
#include "html-generator.h"
#include "testUtils.h"
#include <assert.h>

// Should set str in attributes
TEST(string_literal_1) {
    char tag[] = "div";
    char attrs[] = "class=\"container\"";
    Node *node = initNode(tag, attrs);
    char literal[] = "Hello world";
    pushStringLiteral(node, literal);

    ensure(node->children[0]->nodeType, gclados.toEqualInt(STRING_LITERAL));
    ensureStringEquality(node->children[0]->attributes, "Hello world");

    freeNode(node);
}

// Should do nothing if one of the arguments is NULL
TEST(string_literal_2) {
    Node *container = initNode("div", "");

    pushStringLiteral(container, NULL);

    ensure(container->childrenSize, gclados.toEqualInt(0));

    freeNode(container);
}

// Should do nothing if trying to push string literal node in string literal
TEST(string_literal_3) {
    Node *container = initNode("div", "");

    pushStringLiteral(container, "hello");
    pushStringLiteral(container->children[0], "bye");

    ensure(container->children[0]->children, gclados.toEqualInt(0));

    freeNode(container);
}
