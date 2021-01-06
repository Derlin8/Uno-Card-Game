//
// Created by Derek Lin on 12/12/19.
//

#include "ReverseCard.h"
#include "NumberCard.h"

// Reverse Card
Uno::ReverseCard::ReverseCard(std::string type, const std::string &color, int value)
        : Card(type), color(color), value(value) {
}

void Uno::ReverseCard::play(Uno::GameOfUno* gameState) {
//    reverse(gameState->players.begin(), gameState->players.end());
    gameState->addCardToDiscard(this);
    gameState->reversed = !gameState->reversed;
//    gameState->currentPlayersTurn = gameState->players.size() - gameState->currentPlayersTurn;
}

void Uno::ReverseCard::onInitialFlip(GameOfUno* gameState) {
    gameState->discard.placeOnTop(this);
    gameState->reversed = !gameState->reversed;
    gameState->advanceTurn();
}

bool Uno::ReverseCard::aboutEqual( Card* rhs)  {

    if (type.compare(rhs->type) != 0)  {
        return false;
    }

    ReverseCard* reverseCard = dynamic_cast<ReverseCard*>(rhs);

    return StringMethods::isPrefix(color, reverseCard->color);

}

bool Uno::ReverseCard::operator<(const Card &rhs) {

    if (rhs.type == "NumberCard" || rhs.type == "SkipCard") {
        return false;
    }

    if (type != rhs.type) {
        return true;
    }

    const ReverseCard& reverseCard = dynamic_cast<const ReverseCard&>(rhs);
    if (color == reverseCard.color) {
        return value < reverseCard.value;
    } else {
        return color < reverseCard.color;
    }
}

std::string Uno::ReverseCard::getColor() {
    return color;
}

bool Uno::ReverseCard::canBePlayedOnTopOf(Uno::Card* card) {

    if(card->type == "ReverseCard") {
        return true;
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


std::string Uno::ReverseCard::printCard() {
    return color + " Reverse";
}

int Uno::ReverseCard::getValue() const {
    return value;
}

bool Uno::ReverseCard::operator==(const Uno::Card &rhs) const {

    if (type.compare(rhs.type) != 0)  {
        return false;
    }

    const Uno::ReverseCard& reverseCard = dynamic_cast<const Uno::ReverseCard&>(rhs);

    return color == reverseCard.color && value == reverseCard.value;
}