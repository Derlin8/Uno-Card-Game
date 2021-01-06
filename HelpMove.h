//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_HELPMOVE_H
#define UNO_HELPMOVE_H

#include "Move.h"
#include "GameOfUno.h"
namespace Uno {
    class HelpMove : public Move {
    public:
        void make() override;

        HelpMove(Player &maker, GameOfUno &gameState, MoveType moveType);

        MoveType moveType;
    };
}
#endif //UNO_HELPMOVE_H
