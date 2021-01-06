//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_DRAWNCARD_H
#define UNO_DRAWNCARD_H
#include <sstream>
#include "Card.h"
#include "SkipCard.h"
#include "GameOfUno.h"
namespace Uno {
    class DrawNCard : public Card {
    public:
        DrawNCard(std::string type, const std::string &color, int value, int draw);

        void play(GameOfUno *gameState);

        void onInitialFlip(GameOfUno *gameState);

        bool aboutEqual(Card *rhs);
        std::string getColor();

        bool canBePlayedOnTopOf(Card *card);

        std::string printCard();

        bool operator<(const Card &rhs);

        int getValue() const;

        bool operator==(const Card &rhs) const;

        std::string color;
        int value;
        int draw;
    };
}
#endif //UNO_DRAWNCARD_H
