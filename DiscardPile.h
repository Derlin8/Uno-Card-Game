//
// Created by mfbut on 10/27/2019.
//

#ifndef ECS_36B_HOMEWORK_DISCARDPILE_H
#define ECS_36B_HOMEWORK_DISCARDPILE_H
#include <vector>
#include <random>
#include "Cards/Card.h"

namespace Uno {
  class Deck;
  class DiscardPile {
   public:
    DiscardPile() = default;

    void placeOnTop(Card* card);
    bool isEmpty() const;
    void shuffleInto(Deck& deck, std::minstd_rand rng);
    Card* getTopCard();
   private:
    std::vector<Card*> pile;
    Card* top;
  };
}

#endif //ECS_36B_HOMEWORK_DISCARDPILE_H
