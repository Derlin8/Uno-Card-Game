//
// Created by mfbut on 10/20/2019.
//

#include <algorithm>
#include <functional>
#include <memory>
#include <iostream>
#include "GameOfUno.h"
#include "Moves/Move.h"
#include "Cards/Card.h"
#include "InputValidation.h"

Uno::GameOfUno Uno::GameOfUno::createGame(const std::string &deckFileName, const std::string &rulesFileName, int seed) {
    Deck deck(Deck::loadDeckFromFile(deckFileName));
    std::vector<std::string> possibleColors = Deck::loadColors(deckFileName);
    Rules rules(Rules::loadRulesFromFile(rulesFileName));
    GameOfUno game(deck, possibleColors, rules, seed);

    int numPlayers = InputValidation::getIntAtLeast("Enter the number of players in the game: ", 2);
    game.addHumanPlayers(numPlayers);
    game.dealStartingHands();
    return game;
}

Uno::GameOfUno::GameOfUno(const Uno::Deck &deck, std::vector<std::string> colors,  const Uno::Rules &rules, int seed) :
        deck(deck),
        discard(),
        players(),
        rules(rules),

        gameTerminated(false),
        rng(seed),
        currentPlayersTurn(0),
        colors(colors) {
    this->deck.shuffle(rng);
}

void Uno::GameOfUno::play() {
    while (!isGameOver()) {
        doCurrentPlayersTurn();
        advanceTurn();
    }
    displayEndGameResults();
}

bool Uno::GameOfUno::isGameOver() const {
    if (gameTerminated) {
        return true;
    }
    return std::any_of(players.begin(), players.end(), std::mem_fn(&Player::handIsEmpty));

}

void Uno::GameOfUno::displayGameState() {
    const Player &curPlayer = getCurPlayer();
    std::cout << std::endl;
    displayNonactivePlayersHands();
    std::cout << "Top of discard pile: " << getCardOnTopOfDiscardPile()->printCard() << std::endl;
    curPlayer.displayHand("Your hand");
    std::cout << std::endl;
}

void Uno::GameOfUno::doCurrentPlayersTurn() {
    Player &curPlayer = getCurPlayer();
    curPlayer.turnStart();
    Move *move;
    do {
        displayGameState();
        move = curPlayer.getMove();
        move->make();
    } while (!move->endsTurn());
}

void Uno::GameOfUno::advanceTurn() {
    if (reversed) {
        if (currentPlayersTurn == 0) {
            currentPlayersTurn = numPlayers();
        }
        currentPlayersTurn--;


        return;
    }
    currentPlayersTurn = (currentPlayersTurn + 1) % numPlayers();
}

void Uno::GameOfUno::displayNonactivePlayersHands() const {
    const Player &curPlayer = getCurPlayer();
    for (const auto &player : players) {
        if (player != curPlayer) {
            player.displayHiddenHand();
            std::cout << std::endl;
        }
    }
}

int Uno::GameOfUno::numPlayers() const {
    return players.size();
}

Uno::Player &Uno::GameOfUno::getCurPlayer() {
    return players.at(currentPlayersTurn);
}

const Uno::Player &Uno::GameOfUno::getCurPlayer() const {
    return players.at(currentPlayersTurn);
}

bool Uno::GameOfUno::isPlayer(const Uno::Player &player) const {
    return getPlayerItr(player.getName()) != players.end();
}

bool Uno::GameOfUno::isPlayer(const std::string &playerName) const {
    return getPlayerItr(playerName) != players.end();
}

Uno::Player &Uno::GameOfUno::getPlayer(const std::string &playerName) {
    return *getPlayerItr(playerName);
}

const Uno::Player &Uno::GameOfUno::getPlayer(const std::string &playerName) const {
    return *getPlayerItr(playerName);
}

void Uno::GameOfUno::terminateGame() {
    gameTerminated = true;
}

void Uno::GameOfUno::addCardToDiscard(Uno::Card *card) {
    discard.placeOnTop(card);
}

bool Uno::GameOfUno::canDrawCard() const {
    return !(deck.isEmpty() && discard.isEmpty());
}

Uno::Card *Uno::GameOfUno::drawCard() {
    if (deck.isEmpty()) {
        discard.shuffleInto(deck, rng);
    }
    return deck.draw();
}

Uno::Card *Uno::GameOfUno::getCardOnTopOfDiscardPile() {
    return discard.getTopCard();
}

const Uno::Rules &Uno::GameOfUno::getRules() const {
    return rules;
}

void Uno::GameOfUno::displayEndGameResults() {
    auto orderByScore = [](const Player &p1, const Player &p2) {
        auto p1Score = p1.getScore(), p2Score = p2.getScore();
        if (p1Score == p2Score) {
            if (p1.getNumCardsInHand() == p2.getNumCardsInHand()) {
                return p1.getName() < p2.getName();
            } else {
                return p1.getNumCardsInHand() < p2.getNumCardsInHand();
            }
        } else {
            return p1Score < p2Score;
        }
    };
    //sort the players by points
    std::sort(players.begin(), players.end(), orderByScore);

    std::cout << players.front().getName() << " won the game\n" << std::endl;
    std::cout << "==== Leader Board ====" << std::endl;
    for (unsigned int i = 0; i < players.size(); ++i) {
        const Player &player = players.at(i);
        std::cout << i << ".) " << player.getName() << " : " << player.getScore() << std::endl;
    }

}

void Uno::GameOfUno::addHumanPlayers(int numPlayers) {
    for (int player = 1; player <= numPlayers; ++player) {
        addHumanPlayer(player);
    }
}

void Uno::GameOfUno::addHumanPlayer(int id) {
    const std::string prompt = "Player " + std::to_string(id) + " enter your name: ";
    std::string name;

    do {
        name = InputValidation::getWord(prompt);
    } while (isPlayer(name));

    players.emplace_back(name, *this);
}

void Uno::GameOfUno::dealStartingHands() {
    for (int i = 0; i < rules.getStartingHandSize(); ++i) {
        for (auto &player : players) {
            if (deck.getNumCardsLeft() > 1) {
                player.drawCard();
            }
        }
    }
    //put the top card of the deck onto the discard pile
//  discard.placeOnTop(deck.draw());
    Card* top = deck.draw();
    top->onInitialFlip(this);
}

Uno::GameOfUno::PlayerItr Uno::GameOfUno::getPlayerItr(const std::string &playerName) {
    return std::find(players.begin(), players.end(), playerName);
}

Uno::GameOfUno::ConstPlayItr Uno::GameOfUno::getPlayerItr(const std::string &playerName) const {
    return std::find(players.begin(), players.end(), playerName);
}








