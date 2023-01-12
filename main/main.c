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

    //HTML

    Node *htmlNode = initDefaultHTMLNode();

    //Head
    Node *head = htmlNode->children[0];
    pushChildrenNode(head, "link", "rel=\"stylesheet\" href=\"styles.css\"");
    pushChildrenNode(head, "link", "rel=\"preconnect\" href=\"https://fonts.googleapis.com\"");
    pushChildrenNode(head, "link", "rel=\"preconnect\" href=\"https://fonts.gstatic.com\" crossorigin");
    pushChildrenNode(head, "link", "href=\"https://fonts.googleapis.com/css?family=Poppins\" rel=\"stylesheet\"");

    //Body
    Node *body = htmlNode->children[1];

    Node *h_pageContainer = pushChildrenNode(body, "div", "class=\"page-container\"");

    Node *h_mainTitle = pushChildrenNode(h_pageContainer, "div", "class=\"title-text main-title\"");
    pushStringLiteral(h_mainTitle, "UFO List - find\<br/\>your friends");

    Node *h_lostTitle = pushChildrenNode(h_pageContainer, "div", "class=\"title-text lost\"");
    pushStringLiteral(h_lostTitle, "Lost");

    Node *h_cardsContainer = pushChildrenNode(h_pageContainer, "div", "class=\"cards-container\"");

    Node *h_cards = pushChildrenNode(h_cardsContainer, "div", "class=\"cards\"");

    while(inputCards()==1) {
        CardInfo cardInfo = initCardInfo();
        getCardInfoFromUser(&cardInfo);

        Node *h_container = pushChildrenNode(h_cards, "div", "class=\"container\"");

        //Title
        Node *h_title = pushChildrenNode(h_container, "div", "class=\"title\"");

        char *photoPath0 = strcat("class=\"profile-photo\" src=\"", cardInfo.imagePath);
        char *photoPath1 = strcat(photoPath0, "alt=\"Profile photo\"");
        Node *h_image = pushChildrenNode(h_title, "img", photoPath1);

        //Person name
        Node *h_personName = pushChildrenNode(h_title, "span", "class=\"person-name\"");
        pushStringLiteral(h_personName, cardInfo.name);

        //Last time seen
        Node *h_lastSeen = pushChildrenNode(h_container, "div", "class=\"last-time-seen\"");

        Node *h_seenIcon = pushChildrenNode(h_lastSeen, "img", "class=\"icon\" src=\"./assets/time-outline.svg\" alt=\"time icon\"");
        Node *h_seenText1 = pushChildrenNode(h_lastSeen, "span", "class=\"bold-text\"");
        pushStringLiteral(h_seenText1, "Last time seen: ");
        Node *h_seenText2 = pushChildrenNode(h_lastSeen, "span", "class=\"normal-text\"");
        pushStringLiteral(h_seenText2, cardInfo.date);

        //Adress
        Node *h_adress = pushChildrenNode(h_container, "div", "class=\"adress\"");

        Node *h_adressIcon = pushChildrenNode(h_adress, "img", "class=\"icon\" src=\"./assets/location-outline.svg\" alt=\"Location icon\"");
        Node *h_adressText1 = pushChildrenNode(h_adress, "span", "class=\"bold-text\"");
        pushStringLiteral(h_adressText1, "Adress: ");
        Node *h_adressText2 = pushChildrenNode(h_adress, "span", "class=\"normal-text\"");
        pushStringLiteral(h_adressText2, cardInfo.address);

        //Identification traits
        Node *h_idTraits = pushChildrenNode(h_container, "div", "class=\"identification-traits\"");

        Node *h_traitsTrigger = pushChildrenNode(h_idTraits, "div", "class=\"contents-trigger\" id=\"traits-trigger\"");
        Node *h_traitsIcon = pushChildrenNode(h_traitsTrigger, "img", "class=\"icon\" src=\"./assets/chevron-forward-outline.svg\" alt=\"Chevron icon\"");
        Node *h_traitsText = pushChildrenNode(h_traitsTrigger, "span", "class=\"bold-text\"");
        pushStringLiteral(h_traitsText, "Identification traits");

        Node *h_idContent = pushChildrenNode(h_idTraits, "div", "class=\"id-content\" id=\"traits-content\"");
        Node *h_idList = pushChildrenNode(h_idContent, "ol", "class=\"normal-text\"");

        for(int i=0; i<cardInfo.identificationTraitsSize; ++i)
        {
            Node *h_idPoint = pushChildrenNode(h_idList, "li", "");
            pushStringLiteral(h_idPoint, cardInfo.identificationTraits[i]);
        }

        //Circumstances
        Node *h_circumstances = pushChildrenNode(h_container, "div", "class=\"situation\"");

        Node *h_circumTrigger = pushChildrenNode(h_circumstances, "div", "class=\"contents-trigger\" id=\"situation-trigger\"");
        Node *h_circumIcon = pushChildrenNode(h_circumTrigger, "img", "class=\"icon\" src=\"./assets/chevron-forward-outline.svg\" alt=\"Chevron icon\"");
        Node *h_circumText = pushChildrenNode(h_circumTrigger, "span", "class=\"bold-text\"");
        pushStringLiteral(h_circumText, "The circumstances of disappearance");

        Node *h_circumContent = pushChildrenNode(h_circumstances, "div", "class=\"sit-content\" id=\"situation-content\"");
        Node *h_circumList = pushChildrenNode(h_circumContent, "ol", "class=\"normal-text\"");

        for(int i=0; i<cardInfo.circumstancesSize; ++i)
        {
            Node *h_circumPoint = pushChildrenNode(h_circumList, "li", "");
            pushStringLiteral(h_circumPoint, cardInfo.circumstances[i]);
        }

        Node *h_gradient = pushChildrenNode(h_pageContainer, "div", "id=\"gradient\"");

        Node *h_script = pushChildrenNode(body, "script", "src=\"./index.js\"");
        
    }

    writeHTMLFile(htmlNode, outputDir);

    //CSS
    CSS css;
    initCSS(&css);

    Style bodyStyles;
    initStyle(&bodyStyles, "body");
    addCSSProperty(&bodyStyles, "margin", "0");
    addCSSProperty(&bodyStyles, "background-image", "linear-gradient(to right, rgb(0,0,0), rgb(0,0,0))");
    addCSSProperty(&bodyStyles, "display", "flex");
    addCSSProperty(&bodyStyles, "justify-content", "center");
    pushStyle(&css, &bodyStyles);

    Style pageContainer;
    initStyle(&pageContainer, "page-container");
    addCSSProperty(&pageContainer, "box-shadow", "0px 0px 80px 75px rgba(14, 20, 34)");
    addCSSProperty(&pageContainer, "width", "1728px");
    addCSSProperty(&pageContainer, "height", "2200px");
    addCSSProperty(&pageContainer, "background-image", "url(assets/Background.png)");
    addCSSProperty(&pageContainer, "background-position", "top");
    addCSSProperty(&pageContainer, "background-repeat", "no-repeat");
    addCSSProperty(&pageContainer, "position", "relative");
    pushStyle(&css, &pageContainer);

    Style titleText;
    initStyle(&titleText, "title-text");
    addCSSProperty(&titleText, "color", "white");
    addCSSProperty(&titleText, "font-family", "\"Poppins\", sans-serif");
    addCSSProperty(&titleText, "font-size", "72px");
    addCSSProperty(&titleText, "font-weight", "bold");
    pushStyle(&css, &titleText);

    Style mainTitle;
    initStyle(&mainTitle, "main-title");
    addCSSProperty(&mainTitle, "margin-top", "500px");
    addCSSProperty(&mainTitle, "margin-left", "150px");
    pushStyle(&css, &mainTitle);

    Style lost;
    initStyle(&lost, "lost");
    addCSSProperty(&lost, "margin-top", "500px");
    addCSSProperty(&lost, "margin-left", "150px");
    pushStyle(&css, &lost);

    Style gradient;
    initStyle(&gradient, "gradient");
    addCSSProperty(&gradient, "height", "1000px");
    addCSSProperty(&gradient, "width", "100%");
    addCSSProperty(&gradient, "position", "absolute");
    addCSSProperty(&gradient, "top", "2200px");
    addCSSProperty(&gradient, "z-index", "-1");
    addCSSProperty(&gradient, "background-image", "linear-gradient(rgb(0, 0, 25), black)");
    pushStyle(&css, &gradient);

    Style profilePhoto;
    initStyle(&profilePhoto, "profile-photo");
    addCSSProperty(&profilePhoto, "width", "48px");
    addCSSProperty(&profilePhoto, "height", "48px");
    pushStyle(&css, &profilePhoto);

    Style title;
    initStyle(&title, "title");
    addCSSProperty(&title, "align-items", "center");
    addCSSProperty(&title, "display", "flex");
    addCSSProperty(&title, "justify-content", "space-between");
    addCSSProperty(&title, "padding", "3px");
    pushStyle(&css, &title);

    Style cardsContainer;
    initStyle(&cardsContainer, "cards-container");
    addCSSProperty(&cardsContainer, "display", "flex");
    addCSSProperty(&cardsContainer, "justify-content", "center");
    addCSSProperty(&cardsContainer, "margin-left", "150px");
    addCSSProperty(&cardsContainer, "margin-right", "150px");
    pushStyle(&css, &cardsContainer);

    Style cards;
    initStyle(&cards, "cards");
    addCSSProperty(&cards, "display", "flex");
    addCSSProperty(&cards, "gap", "50px");
    addCSSProperty(&cards, "flex-wrap", "wrap");
    pushStyle(&css, &cards);

    Style container;
    initStyle(&container, "container");
    addCSSProperty(&container, "width", "250px");
    addCSSProperty(&container, "flex-direction", "column");
    addCSSProperty(&container, "display", "flex");
    addCSSProperty(&container, "color", "white");
    addCSSProperty(&container, "padding-top", "16px");
    addCSSProperty(&container, "padding-bottom", "16px");
    addCSSProperty(&container, "padding-left", "24px");
    addCSSProperty(&container, "padding-right", "24px");
    addCSSProperty(&container, "background", "rgb(0 0 0 / 30%)");
    addCSSProperty(&container, "border-style", "solid");
    addCSSProperty(&container, "border-radius", "25px");
    addCSSProperty(&container, "border-width", "1px");
    addCSSProperty(&container, "border-color", "rgb(255, 255, 255, 0.3)");
    pushStyle(&css, &container);

    Style icon;
    initStyle(&icon, "icon");
    addCSSProperty(&icon, "width", "16px");
    addCSSProperty(&icon, "height", "16px");
    addCSSProperty(&icon, "padding", "2px");
    pushStyle(&css, &icon);

    Style personName;
    initStyle(&personName, "person-name");
    addCSSProperty(&personName, "font-family", "Poppins");
    addCSSProperty(&personName, "font-weight", "bold");
    pushStyle(&css, &personName);

    Style boldText;
    initStyle(&boldText, "bold-text");
    addCSSProperty(&boldText, "font-size", "15px");
    addCSSProperty(&boldText, "font-family", "Poppins");
    addCSSProperty(&boldText, "font-weight", "bold");
    addCSSProperty(&boldText, "padding-left", "5px");
    pushStyle(&css, &boldText);

    Style normalText;
    initStyle(&normalText, "bold-text");
    addCSSProperty(&normalText, "font-size", "15px");
    addCSSProperty(&normalText, "font-family", "Poppins");
    addCSSProperty(&normalText, "font-weight", "normal");
    addCSSProperty(&normalText, "padding-left", "5px");
    pushStyle(&css, &normalText);

    Style lastTimeSeen;
    initStyle(&lastTimeSeen, "last-time-seen");
    addCSSProperty(&lastTimeSeen, "align-items", "center");
    addCSSProperty(&lastTimeSeen, "display", "flex");
    addCSSProperty(&lastTimeSeen, "justify-content", "left");
    pushStyle(&css, &lastTimeSeen);

    Style adress;
    initStyle(&adress, "adress");
    addCSSProperty(&adress, "align-items", "center");
    addCSSProperty(&adress, "display", "flex");
    addCSSProperty(&adress, "justify-content", "left");
    pushStyle(&css, &adress);

    Style identificationTraits;
    initStyle(&identificationTraits, "identification-traits");
    addCSSProperty(&identificationTraits, "flex-direction", "column");
    addCSSProperty(&identificationTraits, "display", "flex");
    addCSSProperty(&identificationTraits, "justify-content", "left");
    pushStyle(&css, &identificationTraits);

    Style situation;
    initStyle(&situation, "situation");
    addCSSProperty(&situation, "flex-direction", "column");
    addCSSProperty(&situation, "display", "flex");
    addCSSProperty(&situation, "justify-content", "left");
    pushStyle(&css, &situation);

    Style idContent;
    initStyle(&idContent, "id-content");
    addCSSProperty(&idContent, "display", "none");
    pushStyle(&css, &idContent);

    Style contentsTrigger;
    initStyle(&contentsTrigger, "contents-trigger");
    addCSSProperty(&contentsTrigger, "width", "100%");
    addCSSProperty(&contentsTrigger, "display", "flex");
    addCSSProperty(&contentsTrigger, "align-items", "center");
    addCSSProperty(&contentsTrigger, "cursor", "pointer");
    pushStyle(&css, &contentsTrigger);

    Style sitContent;
    initStyle(&sitContent, "sit-content");
    addCSSProperty(&sitContent, "display", "none");
    pushStyle(&css, &sitContent);

    Style show;
    initStyle(&show, "show");
    addCSSProperty(&show, "display", "block");
    addCSSProperty(&show, "padding-left", "24px");
    pushStyle(&css, &show);


    writeCSSFile(&css, outputDir);

    return 0;
}
