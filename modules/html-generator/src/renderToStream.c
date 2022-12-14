#include "html-generator.h"
#include <string.h>

void renderToStreamRecursive(Node *node, FILE *stream, int tabCount) {
    for (int index = 0; index < tabCount; ++index) {
        fprintf(stream, "\t");
    }

    if (node->nodeType == HTML_TAG) {
        fprintf(stream, "<%s", node->tag);

        if (node->attributes[0] != '\0') {
            fprintf(stream, " %s", node->attributes);
        }

        fprintf(stream, ">");
    }

    if (node->childrenSize > 0) {
        fprintf(stream, "\n");
    }
    
    if (node->nodeType == STRING_LITERAL) {
        if (strstr(node->attributes, "value=") != NULL) {
            node->attributes += sizeof("value=") - 1;
        }

        fprintf(stream, "%s\n", node->attributes);
    }

    for (int index = 0; index < node->childrenSize; ++index) {
        renderToStreamRecursive(node->children[index], stream, tabCount + 1);
    }

    if (node->nodeType == HTML_TAG) {
        if (node->childrenSize > 0) {
            for (int index = 0; index < tabCount; ++index) {
                fprintf(stream, "\t");
            }
        }

        fprintf(stream, "</%s>\n", node->tag);
    }
}

void renderToStream(Node *node, FILE *stream) {
    fprintf(stream, "<!DOCTYPE html>\n");
    renderToStreamRecursive(node, stream, 0);
}
