//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_REVERSECARD_H
#define UNO_REVERSECARD_H
#include <StringMethods.h>
#include "Card.h"
#include "SkipCard.h"
#include "GameOfUno.h"
namespace Uno {
    class ReverseCard : public Card {
    public:
        ReverseCard(std::string type, const std::string &color, int value);

        void play(GameOfUno *gameState);

        void onInitialFlip(GameOfUno *gameState);

        bool aboutEqual(Card *rhs);

        bool canBePlayedOnTopOf(Card *card);

        bool operator<(const Card &rhs);

        std::string printCard();

        int getValue() const;

        bool operator==(const Card &rhs) const;
        std::string getColor();
        std::string color;
        int value;
    };
}
#endif //UNO_REVERSECARD_H
