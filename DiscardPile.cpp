//
// Created by mfbut on 10/27/2019.
//

#include <memory>
#include "DiscardPile.h"
#include "Deck.h"

void Uno::DiscardPile::placeOnTop(Card* card) {
  pile.push_back(card);
  top = card;
}

bool Uno::DiscardPile::isEmpty() const {
  return pile.empty();
}

void Uno::DiscardPile::shuffleInto(Deck& deck, std::minstd_rand rng) {
  deck.replaceWith(std::move(pile));
  deck.shuffle(rng);
}

Uno::Card* Uno::DiscardPile::getTopCard() {
  return top;
}


