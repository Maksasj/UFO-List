#include "css-generator.h"
#include "html-generator.h"
#include "card-info.h"
#include "create-card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createCard(Node *h_cards)
{
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
}