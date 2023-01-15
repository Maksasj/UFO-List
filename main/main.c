#include "card-info.h"
#include "create-card.h"
#include "create-css.h"
#include "css-generator.h"
#include "html-generator.h"
#include "outputFiles.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
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

    Node *pageContainer =
        pushChildrenNode(body, "div", "class=\"page-container\"");

    Node *mainTitle = pushChildrenNode(pageContainer, "div",
                                       "class=\"title-text main-title\"");
    pushStringLiteral(mainTitle, "UFO List - find<br/>your friends");

    Node *lostTitle =
        pushChildrenNode(pageContainer, "div", "class=\"title-text lost\"");
    pushStringLiteral(lostTitle, "Lost");

    Node *cardsContainer =
        pushChildrenNode(pageContainer, "div", "class=\"cards-container\"");

    Node *cards = pushChildrenNode(cardsContainer, "div", "class=\"cards\"");

    while (inputCards()) {
        createCard(cards);
    }

    pushChildrenNode(pageContainer, "div", "id=\"gradient\"");

    pushChildrenNode(body, "script", "src=\"./index.js\"");

    writeHTMLFile(htmlNode);

    // CSS
    CSS css;
    initCSS(&css);

    createCSS(&css);

    writeCSSFile(&css);

    writeJSFile();

    return 0;
}
