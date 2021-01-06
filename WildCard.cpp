//
// Created by Derek Lin on 12/12/19.
//

#include <StringMethods.h>
#include "WildCard.h"
// Wild Card
Uno::WildCard::WildCard(std::string type, int value)
        : Card(type),  value(value), color("") {
}

Uno::WildCard::WildCard(std::string type, std::string color, int value)
        : Card(type),  value(value), color(color) {
}

void Uno::WildCard::play(Uno::GameOfUno* gameState) {
    gameState->addCardToDiscard(this);
}

void Uno::WildCard::onInitialFlip(GameOfUno* gameState) {
    std::cout << gameState->getCurPlayer().getName() + " enter a color for the wild card: ";
    std::string c;
    std::getline(std::cin, c);
    color = gameState->getCurPlayer().getPossibleColorMatching(c);
    gameState->addCardToDiscard(this);
}

bool Uno::WildCard::aboutEqual( Card* rhs)  {

    return type.compare(rhs->type) == 0;

}

std::string Uno::WildCard::getColor() {
    return color;
}

bool Uno::WildCard::canBePlayedOnTopOf(Uno::Card* card) {
    return card != nullptr;
}

bool Uno::WildCard::operator<(const Card &rhs) {

    if (rhs.type == "NumberCard" || rhs.type == "SkipCard" || rhs.type == "ReverseCard" || rhs.type == "DrawNCard") {
        return false;
    }

    if (rhs.type == type) {
        return value < rhs.getValue();
    } else {
        return true;
    }
}

std::string Uno::WildCard::printCard() {
    if (color == "") {
        return "Wild";
    }

    return "Wild set to " + color;
}

int Uno::WildCard::getValue() const {
    return value;
}

bool Uno::WildCard::operator==(const Uno::Card &rhs) const {

    if (type.compare(rhs.type) != 0)  {
        return false;
    }

    const Uno::WildCard& wildCard = dynamic_cast<const Uno::WildCard&>(rhs);

    return color == wildCard.color;
}