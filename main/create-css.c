#include "create-css.h"
#include "css-generator.h"
#include "html-generator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createCSS(CSS *css) {
    Style *bodyStyles = malloc(sizeof(Style));
    initStyle(bodyStyles, "body");
    addCSSProperty(bodyStyles, "margin", "0");
    addCSSProperty(bodyStyles, "background-image",
                   "linear-gradient(to right, rgb(0,0,0), rgb(0,0,0))");
    addCSSProperty(bodyStyles, "display", "flex");
    addCSSProperty(bodyStyles, "justify-content", "center");
    pushStyle(css, bodyStyles);

    Style *pageContainer = malloc(sizeof(Style));
    initStyle(pageContainer, "page-container");
    addCSSProperty(pageContainer, "box-shadow",
                   "0px 0px 80px 75px rgba(14, 20, 34)");
    addCSSProperty(pageContainer, "width", "1728px");
    addCSSProperty(pageContainer, "height", "2200px");
    addCSSProperty(pageContainer, "background-image",
                   "url(assets/Background.png)");
    addCSSProperty(pageContainer, "background-position", "top");
    addCSSProperty(pageContainer, "background-repeat", "no-repeat");
    addCSSProperty(pageContainer, "position", "relative");
    pushStyle(css, pageContainer);

    Style *titleText = malloc(sizeof(Style));
    initStyle(titleText, "title-text");
    addCSSProperty(titleText, "color", "white");
    addCSSProperty(titleText, "font-family", "\"Poppins\", sans-serif");
    addCSSProperty(titleText, "font-size", "72px");
    addCSSProperty(titleText, "font-weight", "bold");
    pushStyle(css, titleText);

    Style *mainTitle = malloc(sizeof(Style));
    initStyle(mainTitle, "main-title");
    addCSSProperty(mainTitle, "margin-top", "500px");
    addCSSProperty(mainTitle, "margin-left", "150px");
    pushStyle(css, mainTitle);

    Style *lost = malloc(sizeof(Style));
    initStyle(lost, "lost");
    addCSSProperty(lost, "margin-top", "500px");
    addCSSProperty(lost, "margin-left", "150px");
    pushStyle(css, lost);

    Style *gradient = malloc(sizeof(Style));
    initStyle(gradient, "gradient");
    addCSSProperty(gradient, "height", "1000px");
    addCSSProperty(gradient, "width", "100%");
    addCSSProperty(gradient, "position", "absolute");
    addCSSProperty(gradient, "top", "2200px");
    addCSSProperty(gradient, "z-index", "-1");
    addCSSProperty(gradient, "background-image",
                   "linear-gradient(rgb(0, 0, 25), black)");
    pushStyle(css, gradient);

    Style *profilePhoto = malloc(sizeof(Style));
    initStyle(profilePhoto, "profile-photo");
    addCSSProperty(profilePhoto, "width", "48px");
    addCSSProperty(profilePhoto, "height", "48px");
    pushStyle(css, profilePhoto);

    Style *title = malloc(sizeof(Style));
    initStyle(title, "title");
    addCSSProperty(title, "align-items", "center");
    addCSSProperty(title, "display", "flex");
    addCSSProperty(title, "justify-content", "space-between");
    addCSSProperty(title, "padding", "3px");
    pushStyle(css, title);

    Style *cardsContainer = malloc(sizeof(Style));
    initStyle(cardsContainer, "cards-container");
    addCSSProperty(cardsContainer, "display", "flex");
    addCSSProperty(cardsContainer, "justify-content", "center");
    addCSSProperty(cardsContainer, "margin-left", "150px");
    addCSSProperty(cardsContainer, "margin-right", "150px");
    pushStyle(css, cardsContainer);

    Style *cards = malloc(sizeof(Style));
    initStyle(cards, "cards");
    addCSSProperty(cards, "display", "flex");
    addCSSProperty(cards, "gap", "50px");
    addCSSProperty(cards, "flex-wrap", "wrap");
    pushStyle(css, cards);

    Style *container = malloc(sizeof(Style));
    initStyle(container, "container");
    addCSSProperty(container, "width", "250px");
    addCSSProperty(container, "flex-direction", "column");
    addCSSProperty(container, "display", "flex");
    addCSSProperty(container, "color", "white");
    addCSSProperty(container, "padding-top", "16px");
    addCSSProperty(container, "padding-bottom", "16px");
    addCSSProperty(container, "padding-left", "24px");
    addCSSProperty(container, "padding-right", "24px");
    addCSSProperty(container, "background", "rgb(0 0 0 / 30%)");
    addCSSProperty(container, "border-style", "solid");
    addCSSProperty(container, "border-radius", "25px");
    addCSSProperty(container, "border-width", "1px");
    addCSSProperty(container, "border-color", "rgb(255, 255, 255, 0.3)");
    pushStyle(css, container);

    Style *icon = malloc(sizeof(Style));
    initStyle(icon, "icon");
    addCSSProperty(icon, "width", "16px");
    addCSSProperty(icon, "height", "16px");
    addCSSProperty(icon, "padding", "2px");
    pushStyle(css, icon);

    Style *personName = malloc(sizeof(Style));
    initStyle(personName, "person-name");
    addCSSProperty(personName, "font-family", "Poppins");
    addCSSProperty(personName, "font-weight", "bold");
    pushStyle(css, personName);

    Style *boldText = malloc(sizeof(Style));
    initStyle(boldText, "bold-text");
    addCSSProperty(boldText, "font-size", "15px");
    addCSSProperty(boldText, "font-family", "Poppins");
    addCSSProperty(boldText, "font-weight", "bold");
    addCSSProperty(boldText, "padding-left", "5px");
    pushStyle(css, boldText);

    Style *normalText = malloc(sizeof(Style));
    initStyle(normalText, "bold-text");
    addCSSProperty(normalText, "font-size", "15px");
    addCSSProperty(normalText, "font-family", "Poppins");
    addCSSProperty(normalText, "font-weight", "normal");
    addCSSProperty(normalText, "padding-left", "5px");
    pushStyle(css, normalText);

    Style *lastTimeSeen = malloc(sizeof(Style));
    initStyle(lastTimeSeen, "last-time-seen");
    addCSSProperty(lastTimeSeen, "align-items", "center");
    addCSSProperty(lastTimeSeen, "display", "flex");
    addCSSProperty(lastTimeSeen, "justify-content", "left");
    pushStyle(css, lastTimeSeen);

    Style *adress = malloc(sizeof(Style));
    initStyle(adress, "adress");
    addCSSProperty(adress, "align-items", "center");
    addCSSProperty(adress, "display", "flex");
    addCSSProperty(adress, "justify-content", "left");
    pushStyle(css, adress);

    Style *identificationTraits = malloc(sizeof(Style));
    initStyle(identificationTraits, "identification-traits");
    addCSSProperty(identificationTraits, "flex-direction", "column");
    addCSSProperty(identificationTraits, "display", "flex");
    addCSSProperty(identificationTraits, "justify-content", "left");
    pushStyle(css, identificationTraits);

    Style *situation = malloc(sizeof(Style));
    initStyle(situation, "situation");
    addCSSProperty(situation, "flex-direction", "column");
    addCSSProperty(situation, "display", "flex");
    addCSSProperty(situation, "justify-content", "left");
    pushStyle(css, situation);

    Style *idContent = malloc(sizeof(Style));
    initStyle(idContent, "id-content");
    addCSSProperty(idContent, "display", "none");
    pushStyle(css, idContent);

    Style *contentsTrigger = malloc(sizeof(Style));
    initStyle(contentsTrigger, "contents-trigger");
    addCSSProperty(contentsTrigger, "width", "100%");
    addCSSProperty(contentsTrigger, "display", "flex");
    addCSSProperty(contentsTrigger, "align-items", "center");
    addCSSProperty(contentsTrigger, "cursor", "pointer");
    pushStyle(css, contentsTrigger);

    Style *sitContent = malloc(sizeof(Style));
    initStyle(sitContent, "sit-content");
    addCSSProperty(sitContent, "display", "none");
    pushStyle(css, sitContent);

    Style *show = malloc(sizeof(Style));
    initStyle(show, "show");
    addCSSProperty(show, "display", "block");
    addCSSProperty(show, "padding-left", "24px");
    pushStyle(css, show);
}