//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_SKIPCARD_H
#define UNO_SKIPCARD_H
#include <StringMethods.h>
#include "Card.h"
#include "GameOfUno.h"
namespace Uno {
    class SkipCard : public Card {
    public:
        SkipCard(std::string type, const std::string &color, int value);

        void play(GameOfUno *gameState);

        void onInitialFlip(GameOfUno *gameState);

        bool aboutEqual(Card *rhs);

        bool canBePlayedOnTopOf(Card *card);

        std::string printCard();

        int getValue() const;

        bool operator==(const Card &rhs) const;

        bool operator<(const Card &rhs);
        std::string getColor();
        std::string color;
        int value;
    };
}
#endif //UNO_SKIPCARD_H
