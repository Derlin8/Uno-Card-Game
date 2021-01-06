//
// Created by Derek Lin on 12/12/19.
//

#include "SkipCard.h"
#include "NumberCard.h"
#include "ReverseCard.h"

// Skip Card

Uno::SkipCard::SkipCard(std::string type, const std::string &color, int value)
        : Card(type), color(color), value(value) {
}

void Uno::SkipCard::play(Uno::GameOfUno* gameState) {
    gameState->addCardToDiscard(this);
    gameState->advanceTurn();
}

void Uno::SkipCard::onInitialFlip(GameOfUno* gameState) {
    gameState->discard.placeOnTop(this);
    gameState->advanceTurn();
}

std::string Uno::SkipCard::getColor() {
    return color;
}

bool Uno::SkipCard::aboutEqual( Card* rhs)  {

    if (type.compare(rhs->type) != 0)  {
        return false;
    }

    SkipCard* numberCard = dynamic_cast<SkipCard*>(rhs);

    return StringMethods::isPrefix(color, numberCard->color);

}

bool Uno::SkipCard::operator<(const Card &rhs) {

    if (rhs.type == "NumberCard") {
        return false;
    }

    if (type != rhs.type) {
        return true;
    }

    const SkipCard& skipCard = dynamic_cast<const SkipCard&>(rhs);
    if (color == skipCard.color) {
        return value < skipCard.value;
    } else {
        return color < skipCard.color;
    }
}

bool Uno::SkipCard::canBePlayedOnTopOf(Uno::Card* card) {

    if(card->type == "SkipCard") {
        return true;
    }

    if (card->type == "WildCard") {
        return true;
    }

    if (card->type == "NumberCard") {
        Uno::NumberCard numberCard = *dynamic_cast<Uno::NumberCard*>(card);
        return color == numberCard.getColor();
    }

    if (card->type == "ReverseCard") {
        Uno::ReverseCard reverseCard = *dynamic_cast<Uno::ReverseCard*>(card);
        return color == reverseCard.color;
    }

    return false;
}


std::string Uno::SkipCard::printCard() {
    return color + " Skip";
}

int Uno::SkipCard::getValue() const {
    return value;
}

bool Uno::SkipCard::operator==(const Uno::Card &rhs) const {

    if (type.compare(rhs.type) != 0)  {
        return false;
    }

    const Uno::SkipCard& skipCard = dynamic_cast<const Uno::SkipCard&>(rhs);

    return color == skipCard.color && value == skipCard.value;
}
