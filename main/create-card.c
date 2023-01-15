#include "card-info.h"
#include "create-card.h"
#include "css-generator.h"
#include "html-generator.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushImageNode(CardInfo *cardInfo, Node *title) {
    char initialAttributes[] = "class=\"profile-photo\" alt=\"Profile photo\"";

    if (cardInfo->imageFileName == NULL) {
        char defaultPhoto[] = "default-person.png";
        cardInfo->imageFileName = malloc(sizeof(defaultPhoto));
        strcpy(cardInfo->imageFileName, defaultPhoto);
    }

    int imageAttributesSize = strlen(initialAttributes) +
                              strlen(cardInfo->imageFileName) +
                              strlen("assets/") + strlen(" src=\"\"") + 1;

    char *imageAttributes = malloc(imageAttributesSize);

    if (imageAttributes == NULL) {
        throwAllocationFailure();
    }

    strcpy(imageAttributes, initialAttributes);

    imageAttributes[strlen(initialAttributes)] = ' ';
    strcpy(imageAttributes + sizeof(initialAttributes), "src=\"");

    strcpy(imageAttributes + sizeof(initialAttributes) + 5, "assets/");

    strcpy(imageAttributes + sizeof(initialAttributes) + 12,
           cardInfo->imageFileName);

    imageAttributes[imageAttributesSize - 2] = '"';
    imageAttributes[imageAttributesSize - 1] = '\0';

    pushChildrenNode(title, "img", imageAttributes);
}

void createCard(Node *cards) {
    CardInfo cardInfo = initCardInfo();
    getCardInfoFromUser(&cardInfo);

    Node *container = pushChildrenNode(cards, "div", "class=\"container\"");

    // Title
    Node *title = pushChildrenNode(container, "div", "class=\"title\"");

    pushImageNode(&cardInfo, title);

    // Person name
    Node *personName = pushChildrenNode(title, "span", "class=\"person-name\"");
    pushStringLiteral(personName, cardInfo.name);

    // Last time seen
    Node *lastSeen =
        pushChildrenNode(container, "div", "class=\"last-time-seen\"");

    Node *seenIcon = pushChildrenNode(
        lastSeen, "img",
        "class=\"icon\" src=\"./assets/time-outline.svg\" alt=\"time icon\"");
    Node *seenText1 = pushChildrenNode(lastSeen, "span", "class=\"bold-text\"");
    pushStringLiteral(seenText1, "Last time seen: ");
    Node *seenText2 =
        pushChildrenNode(lastSeen, "span", "class=\"normal-text\"");
    pushStringLiteral(seenText2, cardInfo.date);

    // Adress
    Node *adress = pushChildrenNode(container, "div", "class=\"adress\"");

    Node *adressIcon =
        pushChildrenNode(adress, "img",
                         "class=\"icon\" src=\"./assets/location-outline.svg\" "
                         "alt=\"Location icon\"");
    Node *adressText1 = pushChildrenNode(adress, "span", "class=\"bold-text\"");
    pushStringLiteral(adressText1, "Adress: ");
    Node *adressText2 =
        pushChildrenNode(adress, "span", "class=\"normal-text\"");
    pushStringLiteral(adressText2, cardInfo.address);

    // Identification traits
    Node *idTraits =
        pushChildrenNode(container, "div", "class=\"identification-traits\"");

    Node *traitsTrigger = pushChildrenNode(
        idTraits, "div", "class=\"contents-trigger\" id=\"traits-trigger\"");
    Node *traitsIcon = pushChildrenNode(
        traitsTrigger, "img",
        "class=\"icon\" src=\"./assets/chevron-forward-outline.svg\" "
        "alt=\"Chevron icon\"");
    Node *traitsText =
        pushChildrenNode(traitsTrigger, "span", "class=\"bold-text\"");
    pushStringLiteral(traitsText, "Identification traits");

    Node *idContent = pushChildrenNode(
        idTraits, "div", "class=\"id-content\" id=\"traits-content\"");
    Node *idList = pushChildrenNode(idContent, "ol", "class=\"normal-text\"");

    for (int i = 0; i < cardInfo.identificationTraitsSize; ++i) {
        Node *idPoint = pushChildrenNode(idList, "li", "class=\"list-item\"");
        pushStringLiteral(idPoint, cardInfo.identificationTraits[i]);
    }

    // Circumstances
    Node *circumstances =
        pushChildrenNode(container, "div", "class=\"situation\"");

    Node *circumTrigger =
        pushChildrenNode(circumstances, "div",
                         "class=\"contents-trigger\" id=\"situation-trigger\"");
    Node *circumIcon = pushChildrenNode(
        circumTrigger, "img",
        "class=\"icon\" src=\"./assets/chevron-forward-outline.svg\" "
        "alt=\"Chevron icon\"");
    Node *circumText =
        pushChildrenNode(circumTrigger, "span", "class=\"bold-text\"");
    pushStringLiteral(circumText, "The circumstances of disappearance");

    Node *circumContent = pushChildrenNode(
        circumstances, "div", "class=\"sit-content\" id=\"situation-content\"");
    Node *circumList =
        pushChildrenNode(circumContent, "ol", "class=\"normal-text\"");

    for (int i = 0; i < cardInfo.circumstancesSize; ++i) {
        Node *circumPoint =
            pushChildrenNode(circumList, "li", "class=\"list-item\"");
        pushStringLiteral(circumPoint, cardInfo.circumstances[i]);
    }
}