#include <stdio.h>
#include "chashmap.h"
#include "html-generator.h"

int main() {
    printf("Hello world !");
    Node *htmlNode = initDefaultHTMLNode();
    FILE *file = fopen("test.txt", "w");

    if (file != NULL) {
        renderToStream(htmlNode, file);
    }

    fclose(file);
    return 0;
}
