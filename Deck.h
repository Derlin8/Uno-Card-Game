//
// Created by mfbut on 10/27/2019.
//

#ifndef ECS_36B_HOMEWORK_DECK_H
#define ECS_36B_HOMEWORK_DECK_H
#include <vector>
#include <random>
#include <string>
#include "Cards/Card.h"
namespace Uno {
  class DiscardPile;
  class Deck {
   public:

    static Deck loadDeckFromFile(const std::string& fileName);
  static std::vector<std::string> loadColors(const std::string& fileName);
    Card* draw();
    bool isEmpty() const;
    int getNumCardsLeft() const;
    void shuffle(std::minstd_rand& rng);
    void replaceWith(std::vector<Card*>&& newCards);
    std::vector<Card*> cards;
  };
}

#endif //ECS_36B_HOMEWORK_DECK_H
