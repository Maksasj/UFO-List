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
    int year;
    int month;
    int day;

    printf("Enter person's name: ");
    fgets(cardInfo->name, PERSON_NAME_LEN, stdin);
    cardInfo->name[strcspn(cardInfo->name, "\n")] = 0;

    while(1) {
        printf("Enter date (format: YYYY-MM-DD): ");
        fgets(cardInfo->date, DATE_LEN, stdin);
        cardInfo->date[strcspn(cardInfo->date, "\n")] = 0;

        if (sscanf(cardInfo->date, "%4d-%2d-%2d", &year, &month, &day) == 3) {
            if (year >= 1000) {
                if (month >= 1 && month <= 12) {
                    if((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
                        break;
                    else if((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
                        break;
                    else if((day >= 1 && day <= 28) && (month == 2))
                        break;
                    else if(day == 29 && month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
                        break;
                }
            }
        }
    }

    while (getchar() != '\n');

    printf("Enter address: ");
    fgets(cardInfo->address, ADDRESS_LEN, stdin);
    cardInfo->address[strcspn(cardInfo->address, "\n")] = 0;

    do {
        printf("Do you have a picture of a person? (Y/N): ");
        scanf("%c", &userAnswer);
        
        while (getchar() != '\n');

        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            printf("Enter path to the picture: ");
            fgets(cardInfo->imagePath, IMAGE_PATH_LEN, stdin);
            cardInfo->imagePath[strcspn(cardInfo->imagePath, "\n")] = 0;
            break;
        }
    } while(userAnswer != 'N');

    do {
        printf("Add identification trait? (Y/N): ");
        scanf("%c", &userAnswer);

        while (getchar() != '\n');

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
        scanf("%c", &userAnswer);

        while (getchar() != '\n');

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
