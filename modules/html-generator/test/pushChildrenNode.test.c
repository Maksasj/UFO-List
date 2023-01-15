#include "gclados.h"
#include "html-generator.h"
#include "testUtils.h"
#include <assert.h>

// Should push children node in parent correctly
TEST(push_children_1) {
    char tag[] = "div";
    char attrs[] = "class=\"container\"";
    Node *node = initNode(tag, attrs);
    char chtag[] = "div";
    char chattrs[] = "class=\"title\"";
    Node *child = pushChildrenNode(node, chtag, chattrs);

    ensure(node->childrenSize, gclados.toEqualUnsignedLong(1));
    ensure(node->childrenCapacity,
           gclados.toEqualUnsignedLong(ALLOCATED_MEMORY_INCREMENT));

    ensure(child->children, gclados.toEqualInt(0));
    ensure(child->childrenSize, gclados.toEqualUnsignedLong(0));
    ensure(child->nodeType, gclados.toEqualInt(HTML_TAG));

    ensureStringEquality(child->tag, "div");
    ensureStringEquality(child->attributes, "class=\"title\"");

    freeNode(node);
}

// Should return NULL if one of the arguments is NULL
TEST(push_children_2) {
    Node *node;
    Node *child1 = pushChildrenNode(node, NULL, NULL);
    Node *child2 = pushChildrenNode(node, "asdf", NULL);
    Node *child3 = pushChildrenNode(node, NULL, "asdf");
    Node *child4 = pushChildrenNode(NULL, NULL, NULL);

    ensure(child1, gclados.toEqualInt(0));
    ensure(child2, gclados.toEqualInt(0));
    ensure(child3, gclados.toEqualInt(0));
    ensure(child4, gclados.toEqualInt(0));
}

// Should return NULL if parentNode of type STRING_LITERAL
TEST(push_children_3) {
    Node *node = initNode("div", "");
    pushStringLiteral(node, "asdf");

    Node *child = pushChildrenNode(node->children[0], "", "");

    ensure(child, gclados.toEqualInt(0));

    freeNode(node);
}
