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

// Structure which holds personal information
typedef struct {
    // for person's image rendering
    char imagePath[IMAGE_PATH_LEN];
    // person's name
    char name[PERSON_NAME_LEN];
    // date of disappearance 
    char date[DATE_LEN];
    // last seen address
    char address[ADDRESS_LEN];

    // identification traits
    int identificationTraitsSize;
    char **identificationTraits;

    // circumstances of disappearance
    int circumstancesSize;
    char **circumstances;
} CardInfo;

/**
 * Initializes empty CardInfo structure
 * 
 * @return empty CardInfo structure
*/
CardInfo initCardInfo();

/**
 * Getting information from console such as name, date, address, imagePath, identificationTraits, circumstances 
 * 
 * @param cardInfo existing CardInfo structure
*/
void getCardInfoFromUser(CardInfo *cardInfo);

/**
 * Asks if user wants to add another card
 * 
 * @return true or false
*/
int inputCards();

#endif
