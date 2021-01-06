//
// Created by mfbut on 10/26/2019.
//

#ifndef ECS_36B_HOMEWORK_CARD_H
#define ECS_36B_HOMEWORK_CARD_H

#include <iostream>
#include <string>
//#include "NumberCard.h"

namespace Uno {
    class GameOfUno;
    class Card {

    public:
        Card();

        Card(std::string type);

        virtual void play(GameOfUno *gameState) = 0;

        virtual void onInitialFlip(GameOfUno *gameState) = 0;

        virtual bool aboutEqual(Card *rhs) = 0;

        virtual int getValue() const = 0;
        virtual std::string getColor() = 0;

        virtual bool canBePlayedOnTopOf(Card *card) = 0;

        virtual std::string printCard() = 0;

        virtual bool operator==(const Card &rhs) const = 0;

        virtual bool operator<(const Card &rhs) = 0;

        std::string type;

        static bool RepresentsNumberCard(const std::string &line);

        static bool RepresentsReverseCard(const std::string &line);

        static bool RepresentsSkipCard(const std::string &line);

        static bool RepresentsWildCard(const std::string &line);

        static bool RepresentsWildCardDrawNCard(const std::string &line);

        static bool RepresentsDrawNCard(const std::string &line);

        static Card* getNumberCard(const std::string &line);

        static Card* getReverseCard(const std::string &line);

        static Card* getSkipCard(const std::string &line);

        static Card* getWildCard(const std::string &line);

        static Card* getWildCardDrawNCard(const std::string &line);

        static Card* getDrawNCard(const std::string &line);

        static Uno::Card* toCard(const std::string &stringMove);

    };

//    std::ostream &operator<<(std::ostream &out, const NumberCard &card);
//
//    std::istream &operator>>(std::istream &in, NumberCard &card);



}

#endif //ECS_36B_HOMEWORK_CARD_H
