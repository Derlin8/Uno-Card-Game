//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_WILDCARDDRAWNCARD_H
#define UNO_WILDCARDDRAWNCARD_H
#include <sstream>
#include "Card.h"
#include "GameOfUno.h"
namespace Uno {
    class WildDrawNCard : public Card {
    public:
        WildDrawNCard(std::string type, int value, int draw);
        WildDrawNCard(std::string type, std::string color, int value, int draw);

        void play(GameOfUno *gameState);

        void onInitialFlip(GameOfUno *gameState);

        bool aboutEqual(Card *rhs);

        bool canBePlayedOnTopOf(Card *card);

        std::string printCard();

        int getValue() const;

        bool operator<(const Card &rhs);
        std::string getColor();
        bool operator==(const Card &rhs) const;

        int value;
        int draw;
        std::string color;
    };
}
#endif //UNO_WILDCARDDRAWNCARD_H
