#include "card-info.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

CardInfo initCardInfo() {
    CardInfo cardInfo;
    cardInfo.identificationTraitsSize = 0;
    cardInfo.circumstancesSize = 0;

    return cardInfo;
}

void getCardInfoFromUser(CardInfo *cardInfo) {
    char userAnswer = ' ';

    printf("Enter person's name: ");
    fgets(cardInfo->name, PERSON_NAME_LEN, stdin);
    cardInfo->name[strcspn(cardInfo->name, "\n")] = 0;

    printf("Enter date: ");
    fgets(cardInfo->date, DATE_LEN, stdin);
    cardInfo->date[strcspn(cardInfo->date, "\n")] = 0;

    printf("Enter address: ");
    fgets(cardInfo->address, ADDRESS_LEN, stdin);
    cardInfo->address[strcspn(cardInfo->address, "\n")] = 0;

    do {
        printf("Add identification trait? (Y/N): ");
        scanf("%c%*c", &userAnswer);
        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            printf("Enter identification trait: ");
            cardInfo->identificationTraits[cardInfo->identificationTraitsSize] = (char*)malloc(IDENTIFICATION_TRAIT_LEN * sizeof(char));
            fgets(cardInfo->identificationTraits[cardInfo->identificationTraitsSize], IDENTIFICATION_TRAIT_LEN, stdin);

            cardInfo->identificationTraits[cardInfo->identificationTraitsSize][strcspn(cardInfo->identificationTraits[cardInfo->identificationTraitsSize], "\n")] = 0;

            ++cardInfo->identificationTraitsSize;
        }
    } while(userAnswer != 'N');

    do {
        printf("Add circumstance? (Y/N): ");
        scanf("%c%*c", &userAnswer);
        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            printf("Enter circumstance: ");
            cardInfo->circumstances[cardInfo->circumstancesSize] = (char*)malloc(CIRCUMSTANCES_LEN * sizeof(char));
            fgets(cardInfo->circumstances[cardInfo->circumstancesSize], CIRCUMSTANCES_LEN, stdin);

            cardInfo->circumstances[cardInfo->circumstancesSize][strcspn(cardInfo->circumstances[cardInfo->circumstancesSize], "\n")] = 0;

            ++cardInfo->circumstancesSize;
        }
    } while(userAnswer != 'N');
}
