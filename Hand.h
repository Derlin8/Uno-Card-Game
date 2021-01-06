//
// Created by mfbut on 10/26/2019.
//

#ifndef ECS_36B_HOMEWORK_HAND_H
#define ECS_36B_HOMEWORK_HAND_H
#include <vector>
#include "Cards/Card.h"
namespace Uno {
  class Hand {
   public:
    using CardRef = std::vector<Card*>::iterator;
    using ConstCardRef = std::vector<Card*>::const_iterator;
    bool isEmpty() const;
    void display() const;
    int size() const;
    bool exactContains(Card* card) const;
    bool contains(Card* card);
    CardRef findCardInHand(Card* card);
    ConstCardRef findCardInHand(Card* card) const;
    void remove(const ConstCardRef& cardRef);
    void addCard(Card* card);
    Card * getLastCardDrawnThisTurn() const;

    ConstCardRef begin() const;
    CardRef begin() ;
    ConstCardRef end() const;
    CardRef end();

    int getScore() const;
   private:
    std::vector<Card*> cards;
    CardRef lastCardDrawnThisTurn;
  };
}

#endif //ECS_36B_HOMEWORK_HAND_H
