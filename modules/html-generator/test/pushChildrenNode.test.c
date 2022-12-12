#include "gclados.h"
#include "html-generator.h"

void ensureStringEquality(char *str1, char *str2) {
    assert(strlen(str1) == strlen(str2));
    int i = 0;

    while (str1[i] != '\0') {
        ensure(str1[i], gclados.toEqualChar(str2[i]));
        ++i;
    }
}

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
}