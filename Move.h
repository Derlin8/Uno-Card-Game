//
// Created by mfbut on 10/26/2019.
//

#ifndef ECS_36B_HOMEWORK_MOVE_H
#define ECS_36B_HOMEWORK_MOVE_H

#include <string>
#include "Cards/Card.h"

namespace Uno {
    class Player;

    class GameOfUno;

    enum class MoveType {
        PLAY_CARD, DRAW, HELP_REQUEST, CALLOUT, QUIT, PASS, UNKNOWN
    };

    class Move {
    public:

        virtual void make() = 0;
        Move(Player &maker, GameOfUno &gameState);
        static Move* GetMoveFromUser(Player &maker, GameOfUno &gameState);

        bool endsTurn() const;

    private:
        static void DisplayPrompt(const Player &maker);

        //does the string represent this type of move?
        static bool RepresentsValidMove(const std::string &line);

        static bool RepresentsHelpRequest(const std::string &line);

        static bool RepresentsQuit(const std::string &line);

        static bool RepresentsPlayCard(const std::string &line);

        static bool RepresentsCallOut(const std::string &line);

        static bool RepresentsDraw(const std::string &line);

        static bool RepresentsPass(const std::string &line);

        //change a string representing a move into a Move object
        static Move* toMove(const std::string &stringMove, Uno::Player &maker, GameOfUno &gameState);

        static Move* CreatePlayCardMove(const std::string &stringMove, Player &maker, GameOfUno &gameState);

        static Move* CreateCallOutMove(const std::string &stringMove, Player &maker, GameOfUno &gameState);

        static Move* CreateUnknownMove(Player &maker, GameOfUno &gameState);

        static Move* CreateQuit(Player &maker, GameOfUno &gameState);

        static Move* CreateHelpRequest(Player &maker, GameOfUno &gameState);

        static Move* CreateDraw(Player &maker, GameOfUno &gameState);

        static Move* CreatePass(Player &maker, GameOfUno &gameState);


    protected:
        Player &maker;
        GameOfUno &gameState;
        bool _endsTurn;
    };
}

#endif //ECS_36B_HOMEWORK_MOVE_H
