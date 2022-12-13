#include "gclados.h"
#include "html-generator.h"
#include "testUtils.h"
#include <assert.h>

TEST(push_children_1) {
    char tag[] = "div";
    char attrs[] = "class=\"container\"";
    Node *node = initNode(tag, attrs);
    char chtag[] = "div";
    char chattrs[] = "class=\"title\"";
    Node *child = pushChildrenNode(node, chtag, chattrs);

    ensure(node->childrenSize, gclados.toEqualUnsignedLong(1));
    ensure(node->childrenCapacity, gclados.toEqualUnsignedLong(5));

    ensure(child->children, gclados.toEqualInt(0));
    ensure(child->childrenSize, gclados.toEqualUnsignedLong(0));
    ensure(child->nodeType, gclados.toEqualInt(HTML_TAG));

    ensureStringEquality(child->tag, "div");
    ensureStringEquality(child->attributes, "class=\"title\"");

    freeNode(node);
}