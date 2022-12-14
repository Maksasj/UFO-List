#include "gclados.h"
#include "testUtils.h"
#include "html-generator.h"
#include <stdio.h>
#include <string.h>

// Should renter <!DOCTYPE html> on top of file
TEST(render_to_stream_1) {
    Node *node = initNode("div", "class=\"container\"");

    FILE *file = fopen("test.html", "w");

    if (file != NULL) {
        renderToStream(node, file);

        fclose(file);
    }

    file = freopen("test.html", "r+", file);

    if (file != NULL) {
        char doctype[16];
        doctype[15] = '\0';

        fread(doctype, 15, 1, file);

        ensureStringEquality(doctype, "<!DOCTYPE html>");

        fclose(file);
    }

    freeNode(node);
}

// Should render string literal in div
TEST(render_to_stream_2) {
    Node *node = initNode("div", "class=\"container\"");
    pushStringLiteral(node, "Hello world!");

    FILE *file = fopen("test.html", "w");

    if (file != NULL) {
        renderToStream(node, file);

        fclose(file);
    }

    file = freopen("test.html", "r+", file);

    if (file != NULL) {
        fseek(file, 16, SEEK_SET);

        char expectedHTML[] = "<div class=\"container\">\n\tHello world!\n</div>";
        int size = strlen(expectedHTML);

        char contents[size + 1];
        contents[size] = '\0';
        fread(contents, size, 1, file);

        ensureStringEquality(contents, expectedHTML);

        fclose(file);
    }

    freeNode(node);
}

// Should render nested nodes
TEST(render_to_stream_3) {
    Node *node = initNode("div", "class=\"container\"");
    Node *node1 = pushChildrenNode(node, "section", "");
    Node *node2 = pushChildrenNode(node1, "a", "");
    pushStringLiteral(node1, "Hello!");
    pushStringLiteral(node2, "Bye!");

    FILE *file = fopen("test.html", "w");

    if (file != NULL) {
        renderToStream(node, file);

        fclose(file);
    }

    file = freopen("test.html", "r+", file);

    if (file != NULL) {
        fseek(file, 16, SEEK_SET);

        char expectedHTML[] = "<div class=\"container\">\n\t<section>\n\t\t<a>\n\t\t\tBye!\n\t\t</a>\n\t\tHello!\n\t</section>\n</div>";
        int size = strlen(expectedHTML);

        char contents[size + 1];
        contents[size] = '\0';
        fread(contents, size, 1, file);

        ensureStringEquality(contents, expectedHTML);

        fclose(file);
    }

    freeNode(node);
}
