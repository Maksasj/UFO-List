#include "card-info.h"
#include "create-card.h"
#include "create-css.h"
#include "css-generator.h"
#include "html-generator.h"
#include "outputFiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *outputDir = NULL;

    if (argc > 1) {
        outputDir = argv[1];
    }

    // HTML

    Node *htmlNode = initDefaultHTMLNode();

    // Head
    Node *head = htmlNode->children[0];
    pushChildrenNode(head, "link", "rel=\"stylesheet\" href=\"styles.css\"");
    pushChildrenNode(
        head, "link",
        "rel=\"preconnect\" href=\"https://fonts.googleapis.com\"");
    pushChildrenNode(
        head, "link",
        "rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin");
    pushChildrenNode(head, "link",
                     "href=\"https://fonts.googleapis.com/css?family=Poppins\" "
                     "rel=\"stylesheet\"");

    // Body
    Node *body = htmlNode->children[1];

    Node *h_pageContainer =
        pushChildrenNode(body, "div", "class=\"page-container\"");

    Node *h_mainTitle = pushChildrenNode(h_pageContainer, "div",
                                         "class=\"title-text main-title\"");
    pushStringLiteral(h_mainTitle, "UFO List - find<br/>your friends");

    Node *h_lostTitle =
        pushChildrenNode(h_pageContainer, "div", "class=\"title-text lost\"");
    pushStringLiteral(h_lostTitle, "Lost");

    Node *h_cardsContainer =
        pushChildrenNode(h_pageContainer, "div", "class=\"cards-container\"");

    Node *h_cards =
        pushChildrenNode(h_cardsContainer, "div", "class=\"cards\"");

    while (inputCards()) {
        createCard(h_cards);
    }

    Node *h_gradient =
        pushChildrenNode(h_pageContainer, "div", "id=\"gradient\"");

    Node *h_script = pushChildrenNode(body, "script", "src=\"./index.js\"");

    writeHTMLFile(htmlNode, outputDir);

    // CSS
    CSS css;
    initCSS(&css);

    createCSS(&css);

    writeCSSFile(&css, outputDir);

    writeJSFile(outputDir);

    return 0;
}
