//
// Created by mfbut on 10/26/2019.
//
#include <iostream>
#include <algorithm>
#include <functional>
#include "Hand.h"

bool Uno::Hand::isEmpty() const {
  return cards.empty();
}

void Uno::Hand::display() const {

  for (auto itr = cards.begin(); itr < cards.end() - 1; ++itr) {
    std::cout << (*itr)->printCard() << ", ";
  }
  std::cout << cards.back()->printCard();
}

int Uno::Hand::size() const {
  return cards.size();
}

bool Uno::Hand::exactContains(Card* card) const {
  return std::find(cards.begin(), cards.end(), card) != cards.end();
}

bool Uno::Hand::contains(Card* card) {
  return findCardInHand(card) != cards.end();
}

Uno::Hand::CardRef Uno::Hand:: findCardInHand(Uno::Card* card) {
    CardRef ref = this->cards.begin();
    for (; ref != this->cards.end(); ref++) {
        if (card->aboutEqual(*ref)) {
            break;
        }
    }
    return ref;
//  auto aboutEqual = std::bind(&Card::aboutEqual, card, std::placeholders::_1);
//  return std::find_if(cards.begin(), cards.end(), aboutEqual);
}

Uno::Hand::ConstCardRef Uno::Hand::findCardInHand(Card* card) const {
    std::cout << card->type << std::endl;
    ConstCardRef ref = this->cards.begin();
    for (; ref != this->cards.end(); ref++) {
        if (card->aboutEqual(*ref)) {
            break;
        }
    }
    return ref;
//  auto aboutEqual = std::bind(&Card::aboutEqual, card, std::placeholders::_1);
//  return std::find_if(cards.begin(), cards.end(), aboutEqual);
}

void Uno::Hand::remove(const Uno::Hand::ConstCardRef& cardRef) {
  if(cardRef == lastCardDrawnThisTurn){
    lastCardDrawnThisTurn = cards.end();
  }
  cards.erase(cardRef);
}

//int getValue(Uno::Card* card) {
//    if (card->type == "NumberCard") {
//        return 0;
//    }
//
//    if (card->type == "SkipCard") {
//        return 1;
//    }
//
//    if (card->type == "ReverseCard") {
//        return 2;
//    }
//
//    if (card->type == "DrawNCard") {
//        return 3;
//    }
//
//    if (card->type == "WildDrawNCard") {
//        return 4;
//    }
//}

bool lessThan(Uno::Card* left, Uno::Card* right) {
    return *left < *right;
}


void Uno::Hand::addCard(Card* card) {
  //add the cards in sorted order
  //too bad there is no binary search
  CardRef ref = findCardInHand(card);
  lastCardDrawnThisTurn = cards.insert(ref, card);

  std::sort(cards.begin(), cards.end(), lessThan);

}

Uno::Card * Uno::Hand::getLastCardDrawnThisTurn() const {
  return *lastCardDrawnThisTurn;
}

Uno::Hand::ConstCardRef Uno::Hand::begin() const {
  return cards.begin();
}

Uno::Hand::CardRef Uno::Hand::begin() {
  return cards.begin();
}

Uno::Hand::ConstCardRef Uno::Hand::end() const {
  return cards.end();
}

Uno::Hand::CardRef Uno::Hand::end() {
  return cards.end();
}

int Uno::Hand::getScore() const{
  int total = 0;
  for (const auto& card : cards) {
      total += card->getValue();
  }
  return total;
}
