/**
 * card-info
 *
 * @authors
 * Oskaras Vištorskis
 *
 * @brief
 * Card Info structure, that could store personal information
 *
 * @example
 *  int main() {
        CardInfo cardInfo = initCardInfo();
        getCardInfoFromUser(&cardInfo);
    }
 *
*/

#ifndef CARD_INFO_H
#define CARD_INFO_H

#define IMAGE_PATH_LEN 128
#define PERSON_NAME_LEN 64
#define DATE_LEN 10
#define ADDRESS_LEN 128
#define IDENTIFICATION_TRAIT_LEN 128
#define CIRCUMSTANCES_LEN 128

typedef struct {
    char imagePath[IMAGE_PATH_LEN];
    char name[PERSON_NAME_LEN];
    char date[DATE_LEN];
    char address[ADDRESS_LEN];

    int identificationTraitsSize;
    char *identificationTraits[IDENTIFICATION_TRAIT_LEN];

    int circumstancesSize;
    char *circumstances[CIRCUMSTANCES_LEN];
} CardInfo;

CardInfo initCardInfo();

void getCardInfoFromUser(CardInfo *cardInfo);

#endif
