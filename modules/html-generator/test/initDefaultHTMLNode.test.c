#include "gclados.h"
#include "html-generator.h"
#include "testUtils.h"

// Should init html node correctly
TEST(init_default_html_node1) {
    Node *node = initDefaultHTMLNode();
    Node *headNode = node->children[0];
    Node *bodyNode = node->children[1];

    ensureStringEquality(node->tag, "html");
    ensureStringEquality(headNode->tag, "head");
    ensureStringEquality(bodyNode->tag, "body");

    ensure(headNode->childrenSize, gclados.toEqualInt(4));
    ensure(bodyNode->childrenSize, gclados.toEqualInt(0));
}