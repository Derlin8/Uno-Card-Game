//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_WILDCARD_H
#define UNO_WILDCARD_H
#include <sstream>
#include "Card.h"
#include "GameOfUno.h"
namespace Uno {
    class WildCard : public Card {
    public:
        WildCard(std::string type, int value);
        WildCard(std::string type, std::string color, int value);
        void play(GameOfUno *gameState);

        void onInitialFlip(GameOfUno *gameState);

        bool aboutEqual(Card *rhs);

        bool canBePlayedOnTopOf(Card *card);

        std::string printCard();

        bool operator<(const Card &rhs);

        int getValue() const;
        std::string getColor();
        bool operator==(const Card &rhs) const;
        int value;
        std::string color;
    };
}

#endif //UNO_WILDCARD_H
