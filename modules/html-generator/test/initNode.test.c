#include "gclados.h"
#include "html-generator.h"
#include <assert.h>
#include <string.h>

void ensureStringEquality(char *str1, char *str2) {
    assert(strlen(str1) == strlen(str2));
    int i = 0;

    while (str1[i] != '\0') {
        ensure(str1[i], gclados.toEqualChar(str2[i]));
        ++i;
    }
}

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
