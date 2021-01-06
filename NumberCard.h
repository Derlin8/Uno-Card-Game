//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_NUMBERCARD_H
#define UNO_NUMBERCARD_H
#include <sstream>
#include <StringMethods.h>
#include "Card.h"
#include "GameOfUno.h"
namespace Uno {
    class NumberCard : public Card {
        //friend std::istream &operator>>(std::istream &in, NumberCard &card);

    public:
        NumberCard(std::string type, const std::string &color, int value);

        NumberCard();

        NumberCard &operator=(const NumberCard &rhs);

        bool operator<(const NumberCard &rhs) const;

        const std::string &getColor() const;

        int getValue() const;

        std::string getName() const;

        bool operator==(const Card &rhs) const;

        bool operator!=(const NumberCard &rhs) const;

        bool aboutEqual(Card *rhs);

        void play(GameOfUno *gameState);

        void onInitialFlip(GameOfUno *gameState);

        bool canBePlayedOnTopOf(Card *card);
        std::string getColor();
        std::string printCard();

        bool operator<(const Card &rhs) ;

        std::string color;
        int value;

        // TODO UNO

    private: //static members
        static const std::string unknownColor;
        static const std::string unknownType;
        static const int unknownValue;
    };
}
#endif //UNO_NUMBERCARD_H
