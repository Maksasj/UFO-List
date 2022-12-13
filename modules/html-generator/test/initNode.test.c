#include "gclados.h"
#include "html-generator.h"
#include "testUtils.h"
#include <assert.h>
#include <string.h>

// Should return Node pointer with correct values
TEST(init_node_1) {
    char tag[] = "div";
    char attrs[] = "class=\"container\"";
    Node *node = initNode(tag, attrs);

    ensure(node->children, gclados.toEqualInt(0));
    ensure(node->childrenSize, gclados.toEqualUnsignedLong(0));
    ensure(node->nodeType, gclados.toEqualInt(HTML_TAG));

    ensureStringEquality(node->tag, "div");
    ensureStringEquality(node->attributes, "class=\"container\"");

    freeNode(node);
}
