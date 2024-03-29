#include "card-info.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORMAT(S) "%" #S "[^\n]"
#define VARIABLE_LEN_STR(S) FORMAT(S)

void skipCharacters() {
    scanf("%*[^\n]"); // skip other characters
    scanf("%*c");     // skip end of line
}

bool validateDate(int year, int month, int day) {
    if (year >= 1000) {
        if (month >= 1 && month <= 12) {
            if ((day >= 1 && day <= 31) &&
                (month == 1 || month == 3 || month == 5 || month == 7 ||
                 month == 8 || month == 10 || month == 12))
                return true;
            else if ((day >= 1 && day <= 30) &&
                     (month == 4 || month == 6 || month == 9 || month == 11))
                return true;
            else if ((day >= 1 && day <= 28) && (month == 2))
                return true;
            else if (day == 29 && month == 2 &&
                     (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
                return true;
        }
    }

    return false;
}

CardInfo initCardInfo() {
    CardInfo cardInfo;
    cardInfo.identificationTraitsSize = 0;
    cardInfo.circumstancesSize = 0;

    cardInfo.circumstances = NULL;
    cardInfo.identificationTraits = NULL;

    return cardInfo;
}

bool inputCards() {
    char userAnswer = ' ';

    while (userAnswer != 'N') {
        printf("Add another person? (Y/N): ");
        scanf("%c", &userAnswer);

        skipCharacters();

        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            return true;
        }
    }

    return false;
}

void getCardInfoFromUser(CardInfo *cardInfo) {
    char userAnswer = ' ';
    int year;
    int month;
    int day;

    printf("Enter person's name: ");
    cardInfo->name = malloc(PERSON_NAME_LEN + 1);
    scanf(VARIABLE_LEN_STR(PERSON_NAME_LEN), cardInfo->name);

    skipCharacters();

    cardInfo->date = malloc(DATE_LEN + 1);
    while (1) {
        printf(
            "Enter the date the person was last seen (format: YYYY-MM-DD): ");
        scanf(VARIABLE_LEN_STR(DATE_LEN), cardInfo->date);

        skipCharacters();

        if (sscanf(cardInfo->date, "%4d-%2d-%2d", &year, &month, &day) == 3) {
            bool dateIsValid = validateDate(year, month, day);

            if (dateIsValid) {
                break;
            }

            printf("Date format is invalid. Please try again\n");
        } else {
            printf("Date format is invalid. Please try again\n");
        }
    }

    printf("Enter person's address: ");
    cardInfo->address = malloc(ADDRESS_LEN + 1);
    scanf(VARIABLE_LEN_STR(ADDRESS_LEN), cardInfo->address);

    skipCharacters();

    do {
        printf("Do you have a picture of a person? (Y/N): ");
        scanf("%c", &userAnswer);

        skipCharacters();

        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            printf("Enter name of the picture file and copy it in "
                   "./docs/assets folder: ");
            cardInfo->imageFileName = malloc(IMAGE_PATH_LEN + 1);
            scanf(VARIABLE_LEN_STR(IMAGE_PATH_LEN), cardInfo->imageFileName);

            skipCharacters();
            break;
        } else {
            cardInfo->imageFileName = NULL;
        }
    } while (userAnswer != 'N');

    do {
        printf("Add identification trait? (Y/N): ");
        scanf("%c", &userAnswer);

        skipCharacters();

        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            printf("Enter identification trait: ");

            cardInfo->identificationTraits = realloc(
                cardInfo->identificationTraits,
                (cardInfo->identificationTraitsSize + 1) * sizeof(char *));

            cardInfo->identificationTraits[cardInfo->identificationTraitsSize] =
                (char *)malloc(IDENTIFICATION_TRAIT_LEN * sizeof(char));
            scanf(
                VARIABLE_LEN_STR(IDENTIFICATION_TRAIT_LEN),
                cardInfo
                    ->identificationTraits[cardInfo->identificationTraitsSize]);

            skipCharacters();

            ++cardInfo->identificationTraitsSize;
        }
    } while (userAnswer != 'N');

    do {
        printf("Add circumstance of disappearance? (Y/N): ");
        scanf("%c", &userAnswer);

        skipCharacters();

        userAnswer = toupper(userAnswer);

        if (userAnswer == 'Y') {
            printf("Enter circumstance: ");

            cardInfo->circumstances =
                realloc(cardInfo->circumstances,
                        (cardInfo->circumstancesSize + 1) * sizeof(char *));

            cardInfo->circumstances[cardInfo->circumstancesSize] =
                (char *)malloc(CIRCUMSTANCES_LEN * sizeof(char));
            scanf(VARIABLE_LEN_STR(CIRCUMSTANCES_LEN),
                  cardInfo->circumstances[cardInfo->circumstancesSize]);

            skipCharacters();

            ++cardInfo->circumstancesSize;
        }
    } while (userAnswer != 'N');
}
