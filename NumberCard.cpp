//
// Created by Derek Lin on 12/12/19.
//

#include "NumberCard.h"
#include "WildCard.h"
#include "WildCardDrawNCard.h"

const std::string Uno::NumberCard::unknownColor("Unknown Color");
const int Uno::NumberCard::unknownValue(-3974);

Uno::Card::Card(std::string type) : type(type) {}

Uno::NumberCard::NumberCard(std::string type, const std::string &color, int value)
        : Card(type), color(color), value(value) {
}

Uno::NumberCard::NumberCard() : NumberCard("NumberCard" , unknownColor, unknownValue) {

}

const std::string &Uno::NumberCard::getColor() const {
    return color;
}

int Uno::NumberCard::getValue() const {
    return value;
}

bool Uno::NumberCard::aboutEqual( Card* rhs)  {

    if (type.compare(rhs->type) != 0)  {
        return false;
    }

    NumberCard* numberCard = dynamic_cast<NumberCard*>(rhs);

    return getValue() == numberCard->getValue() && StringMethods::isPrefix(getColor(), numberCard->getColor());

}

void Uno::NumberCard::play(Uno::GameOfUno* gameState) {
    gameState->addCardToDiscard(this);
}

bool Uno::NumberCard::operator<(const Card &rhs) {
    if (type != rhs.type) {
        return true;
    }

    const NumberCard& numberCard = dynamic_cast<const NumberCard&>(rhs);
    if (color == numberCard.color) {
        return value < numberCard.value;
    } else {
        return color < numberCard.color;
    }
}

void Uno::NumberCard::onInitialFlip(GameOfUno* gameState) {
    gameState->discard.placeOnTop(this);
}

bool Uno::NumberCard::operator==(const Uno::Card &rhs) const {

    if (type.compare(rhs.type) != 0)  {
        return false;
    }

    const Uno::NumberCard& numberCard = dynamic_cast<const Uno::NumberCard&>(rhs);

    return color == numberCard.color && value == numberCard.value;
}

bool Uno::NumberCard::operator!=(const Uno::NumberCard &rhs) const {
    return !(rhs == *this);
}

std::string Uno::NumberCard::getName() const {
    std::stringstream name;
    name << getColor() << ' ' << getValue();
    return name.str();
}

Uno::NumberCard &Uno::NumberCard::operator=(const Uno::NumberCard &rhs) {
    color = rhs.getColor();
    value = rhs.getValue();
    return *this;
}

bool Uno::NumberCard::operator<(const Uno::NumberCard &rhs) const {
    if (getColor() == rhs.getColor()) {
        return getValue() < rhs.getValue();
    } else {
        return StringMethods::tolower(getColor()) <
               StringMethods::tolower(rhs.getColor());
    }
}
std::string Uno::NumberCard::getColor() {
    return color;
}
bool Uno::NumberCard::canBePlayedOnTopOf(Uno::Card* card) {

    if (card->type != type) {
        return getColor() == card->getColor();
    }

    Uno::NumberCard numberCard = *dynamic_cast<Uno::NumberCard*>(card);
    return getColor() == numberCard.getColor() || getValue() == numberCard.getValue();
}

std::string  Uno::NumberCard::printCard() {
    return this->getName();
}