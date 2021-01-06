//
// Created by Derek Lin on 12/12/19.
//

#include "WildCardDrawNCard.h"
// Wild Card Draw N
Uno::WildDrawNCard::WildDrawNCard(std::string type, int value, int draw)
        : Card(type),  value(value), draw(draw), color("") {
}

Uno::WildDrawNCard::WildDrawNCard(std::string type, std::string color, int value, int draw)
        : Card(type),  value(value), draw(draw), color(color) {
}

void Uno::WildDrawNCard::play(Uno::GameOfUno* gameState) {
    gameState->advanceTurn();
    gameState->addCardToDiscard(this);
    for (int i = 0; i < draw; i++) {
        gameState->getCurPlayer().drawCard();
    }
}

void Uno::WildDrawNCard::onInitialFlip(GameOfUno* gameState) {
    std::cout << gameState->getCurPlayer().getName() + " enter a color for the wild card: ";
    std::string c;
    std::getline(std::cin, c);
    color = gameState->getCurPlayer().getPossibleColorMatching(c);
    gameState->addCardToDiscard(this);
    for (int i = 0; i < draw; i++) {
        gameState->getCurPlayer().drawCard();
    }
}

std::string Uno::WildDrawNCard::getColor() {
    return color;
}

bool Uno::WildDrawNCard::aboutEqual( Card* rhs)  {

    if (type.compare(rhs->type) != 0)  {
        return false;
    }

    WildDrawNCard* wildCard = dynamic_cast<WildDrawNCard*>(rhs);

    return draw == wildCard->draw;

}

bool Uno::WildDrawNCard::operator<(const Card &rhs) {

    if (rhs.type != type) {
        return false;
    }
    const WildDrawNCard& drawNCard = dynamic_cast<const WildDrawNCard&>(rhs);
    return draw < drawNCard.draw;
}

bool Uno::WildDrawNCard::canBePlayedOnTopOf(Uno::Card* card) {
    return card != nullptr;
}


std::string Uno::WildDrawNCard::printCard() {
    if (color == "") {
        return "Wild Draw " + std::to_string(draw);
    }

    return "Wild Draw " + std::to_string(draw) + " set to " + color;
}

int Uno::WildDrawNCard::getValue() const {
    return value;
}

bool Uno::WildDrawNCard::operator==(const Uno::Card &rhs) const {

    if (type.compare(rhs.type) != 0)  {
        return false;
    }

    const Uno::WildDrawNCard& wildCard = dynamic_cast<const Uno::WildDrawNCard&>(rhs);

    return draw == wildCard.draw && color == wildCard.color;
}