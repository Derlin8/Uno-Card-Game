//
// Created by Derek Lin on 12/12/19.
//

#include "DrawNCard.h"
#include "NumberCard.h"

// DRAW N
Uno::DrawNCard::DrawNCard(std::string type, const std::string &color, int value, int draw)
        : Card(type), color(color), value(value), draw(draw) {
}

void Uno::DrawNCard::play(Uno::GameOfUno* gameState) {
    gameState->discard.placeOnTop(this);
    gameState->advanceTurn();
    for (int i = 0; i < draw; i++) {
        gameState->getCurPlayer().drawCard();
    }
    //gameState->addCardToDiscard(this);
}

bool Uno::DrawNCard::operator<(const Card &rhs) {

    if (rhs.type == "NumberCard" || rhs.type == "SkipCard" || rhs.type == "ReverseCard") {
        return false;
    }

    if (type != rhs.type) {
        return true;
    }

    const DrawNCard& drawNCard = dynamic_cast<const DrawNCard&>(rhs);
    if (color == drawNCard.color) {
        return draw < drawNCard.draw;
    } else {
        return color < drawNCard.color;
    }
}

void Uno::DrawNCard::onInitialFlip(GameOfUno* gameState) {
    gameState->discard.placeOnTop(this);
    for (int i = 0; i < draw; i++) {
        gameState->getCurPlayer().drawCard();
    }
}

std::string Uno::DrawNCard::getColor() {
    return color;
}

bool Uno::DrawNCard::aboutEqual( Card* rhs)  {

    if (type.compare(rhs->type) != 0)  {
        return false;
    }

    DrawNCard* drawNCard = dynamic_cast<DrawNCard*>(rhs);

    return draw == drawNCard->draw && StringMethods::isPrefix(color, drawNCard->color);

}

bool Uno::DrawNCard::canBePlayedOnTopOf(Uno::Card* card) {

    if(card->type == "DrawNCard") {
        Uno::DrawNCard numberCard = *dynamic_cast<Uno::DrawNCard*>(card);
        return card->getColor() == color || numberCard.draw == draw;
    }

    if (card->type == "WildCard") {
        return true;
    }

    if (card->type == "NumberCard") {
        Uno::NumberCard numberCard = *dynamic_cast<Uno::NumberCard*>(card);
        return color == numberCard.getColor();
    }

    if (card->type == "SkipCard") {
        Uno::SkipCard skipCard = *dynamic_cast<Uno::SkipCard*>(card);
        return color == skipCard.color;
    }
    return false;
}


std::string Uno::DrawNCard::printCard() {
    return color + " Draw " + std::to_string(draw);
}

int Uno::DrawNCard::getValue() const {
    return value;
}

bool Uno::DrawNCard::operator==(const Uno::Card &rhs) const {

    if (type.compare(rhs.type) != 0)  {
        return false;
    }

    const Uno::DrawNCard& drawNCard = dynamic_cast<const Uno::DrawNCard&>(rhs);

    return color == drawNCard.color && draw == drawNCard.draw;
}
