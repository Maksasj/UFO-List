#include "card-info.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define FORMAT(S) "%" #S "s"
#define VARIABLE_LEN_STR(S) FORMAT(S)

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
    scanf(VARIABLE_LEN_STR(PERSON_NAME_LEN), cardInfo->name);

    while(1) {
        printf("Enter date (format: YYYY-MM-DD): ");
        scanf(VARIABLE_LEN_STR(DATE_LEN), cardInfo->date);

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

    printf("Enter address: ");
    scanf(VARIABLE_LEN_STR(ADDRESS_LEN), cardInfo->address);

    while (getchar() != '\n');

    do {
        printf("Do you have a picture of a person? (Y/N): ");
        scanf("%c", &userAnswer);
        
        while (getchar() != '\n');

        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            printf("Enter path to the picture: ");
            scanf(VARIABLE_LEN_STR(IMAGE_PATH_LEN), cardInfo->imagePath);

            while (getchar() != '\n');
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
            scanf(VARIABLE_LEN_STR(IDENTIFICATION_TRAIT_LEN), cardInfo->identificationTraits[cardInfo->identificationTraitsSize]);

            while (getchar() != '\n');

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
            scanf(VARIABLE_LEN_STR(CIRCUMSTANCES_LEN), cardInfo->circumstances[cardInfo->circumstancesSize]);

            while (getchar() != '\n');

            ++cardInfo->circumstancesSize;
        }
    } while(userAnswer != 'N');
}
