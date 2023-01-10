#include "css-generator.h"
#include "html-generator.h"
#include "outputFiles.h"
#include "card-info.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *outputDir = NULL;

    if (argc > 1) {
        outputDir = argv[1];
    }

    CardInfo cardInfo = initCardInfo();
    getCardInfoFromUser(&cardInfo);
    printf("%s\n", cardInfo.identificationTraits[0]);
    printf("%s", cardInfo.circumstances[0]);

    Node *htmlNode = initDefaultHTMLNode();

    Node *head = htmlNode->children[0];
    pushChildrenNode(head, "link", "rel=\"stylesheet\" href=\"styles.css\"");

    writeHTMLFile(htmlNode, outputDir);

    CSS css;
    initCSS(&css);

    Style bodyStyles;
    initStyle(&bodyStyles, "body");

    addCSSProperty(&bodyStyles, "width", "100%");
    addCSSProperty(&bodyStyles, "height", "100%");

    pushStyle(&css, &bodyStyles);

    writeCSSFile(&css, outputDir);

    return 0;
}
