#include "gclados.h"
#include "html-generator.h"
#include "testUtils.h"
#include <assert.h>

TEST(string_literal_1) {
    char tag[] = "div";
    char attrs[] = "class=\"container\"";
    Node *node = initNode(tag, attrs);
    char literal[] = "Hello world";
    pushStringLiteral(node, literal);

    ensure(node->children[0].nodeType, gclados.toEqualInt(STRING_LITERAL));
    ensureStringEquality(node->children[0].attributes, "value=Hello world");

    freeNode(node);
}