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

TEST(string_literal_1) {
    char tag[] = "div";
    char attrs[] = "class=\"container\"";
    Node *node = initNode(tag, attrs);
    char literal[] = "Hello world";
    pushStringLiteral(node, literal);

    ensure(node->nodeType, gclados.toEqualInt(STRING_LITERAL));
    ensureStringEquality(node->value, "Hello world");
}