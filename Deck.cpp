//
// Created by mfbut on 10/27/2019.
//

#include <memory>
#include <algorithm>
#include <fstream>
#include <Cards/NumberCard.h>
#include <Cards/SkipCard.h>
#include <Cards/ReverseCard.h>
#include <Cards/WildCardDrawNCard.h>
#include <Cards/WildCard.h>
#include <set>
#include <Cards/DrawNCard.h>
#include "Deck.h"
#include "boost/property_tree/exceptions.hpp"
#include "boost/property_tree/json_parser.hpp"

Uno::Deck Uno::Deck::loadDeckFromFile(const std::string& fileName) {
  Deck deck;
  std::ifstream deckFile(fileName);

  boost::property_tree::ptree propertyTree;
  boost::property_tree::read_json(fileName, propertyTree);

    for( auto& card : propertyTree.get_child("cards")){
        auto type = card.second.get<std::string>("class");

        if (type == "NumberCard") {
            int value = std::stoi(card.second.get<std::string>("value"));
            auto color = card.second.get<std::string>("color");
            NumberCard* current = new NumberCard(type, color, value);
            deck.cards.insert(deck.cards.end(), current);
        }

        if (type == "SkipCard") {
            int value = std::stoi(card.second.get<std::string>("value"));
            auto color = card.second.get<std::string>("color");
            SkipCard* current = new SkipCard(type, color, value);
            deck.cards.insert(deck.cards.end(), current);
        }

        if (type == "ReverseCard") {
            int value = std::stoi(card.second.get<std::string>("value"));
            auto color = card.second.get<std::string>("color");
            ReverseCard* current = new ReverseCard(type, color, value);
            deck.cards.insert(deck.cards.end(), current);
        }

        if (type == "DrawNCard") {
            int value = std::stoi(card.second.get<std::string>("value"));
            int draw = std::stoi(card.second.get<std::string>("draw"));
            auto color = card.second.get<std::string>("color");
            DrawNCard* current = new DrawNCard(type, color, value, draw);
            deck.cards.insert(deck.cards.end(), current);
        }

        if (type == "WildCard") {
            int value = std::stoi(card.second.get<std::string>("value"));
            WildCard* current = new WildCard(type, value);
            deck.cards.insert(deck.cards.end(), current);
        }

        if (type == "WildDrawNCard") {
            int value = std::stoi(card.second.get<std::string>("value"));
            int draw = std::stoi(card.second.get<std::string>("draw"));
            WildDrawNCard* current = new WildDrawNCard(type, value, draw);
            deck.cards.insert(deck.cards.end(), current);
        }

    }
  return deck;
}

std::vector<std::string> Uno::Deck::loadColors(const std::string& fileName) {
    Deck deck;
    std::ifstream deckFile(fileName);

    boost::property_tree::ptree propertyTree;
    boost::property_tree::read_json(fileName, propertyTree);

    std::set<std::string> set;
    for( auto& card : propertyTree.get_child("cards")){
        auto type = card.second.get<std::string>("class");
        if (type == "NumberCard" || type == "SkipCard" || type == "ReverseCard" || type == "DrawNCard") {
            auto color = card.second.get<std::string>("color");
            set.insert(color);
        }

    }
    std::vector<std::string> v( set.begin(), set.end() );
    return v;
}

Uno::Card* Uno::Deck::draw() {
  Card* drawn = cards.back();
  cards.pop_back();
  return drawn;
}

bool Uno::Deck::isEmpty() const {
  return cards.empty();
}

void Uno::Deck::shuffle(std::minstd_rand& rng) {
  std::shuffle(cards.begin(), cards.end(), rng);
}

void Uno::Deck::replaceWith(std::vector<Card*>&& newCards) {
  cards = std::move(newCards);
}

int Uno::Deck::getNumCardsLeft() const {
  return cards.size();
}


