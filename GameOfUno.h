//
// Created by mfbut on 10/20/2019.
//

#ifndef ECS_36B_HOMEWORK_GAMEOFUNO_H
#define ECS_36B_HOMEWORK_GAMEOFUNO_H

#include <vector>
#include <string>
#include <random>
#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "Rules.h"
#include "Cards/Card.h"

namespace Uno {
    class GameOfUno {
    public:
        using PlayerItr = std::vector<Player>::iterator;
        using ConstPlayItr = std::vector<Player>::const_iterator;

        static GameOfUno createGame(const std::string &deckFileName, const std::string &rulesFileName, int seed);

        GameOfUno(const Uno::Deck &deck, std::vector<std::string> colors, const Uno::Rules &rules, int seed);

        void play();

        bool isPlayer(const Player &player) const;

        bool isPlayer(const std::string &playerName) const;

        Player &getPlayer(const std::string &playerName);

        const Player &getPlayer(const std::string &playerName) const;

        void terminateGame();

        void addCardToDiscard(Card *card);

        bool canDrawCard() const;

        Card *drawCard();

        Card *getCardOnTopOfDiscardPile();

        const Rules &getRules() const;

        void addHumanPlayers(int numPlayers);

        void addHumanPlayer(int id);

        PlayerItr getPlayerItr(const std::string &playerName);

        ConstPlayItr getPlayerItr(const std::string &playerName) const;

        Deck deck;
        DiscardPile discard;
        std::vector<Player> players;
        Rules rules;
        bool gameTerminated;
        std::minstd_rand rng;
        int currentPlayersTurn;
        std::vector<std::string> colors;
        bool reversed = false;
        bool isGameOver() const;

        void displayGameState();

        void displayNonactivePlayersHands() const;

        int numPlayers() const;

        Player &getCurPlayer();

        const Player &getCurPlayer() const;

        void advanceTurn();

        void doCurrentPlayersTurn();

        void displayEndGameResults();

        void dealStartingHands();

    };


}

#endif //ECS_36B_HOMEWORK_GAMEOFUNO_H
