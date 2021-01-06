//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_DRAWCARDMOVE_H
#define UNO_DRAWCARDMOVE_H

#endif //UNO_DRAWCARDMOVE_H
#include "Move.h"
#include "GameOfUno.h"
namespace Uno {
    class DrawCardMove : public Move {
    public:
        void make() override;

        MoveType moveType;

        DrawCardMove(Player &maker, GameOfUno &gameState, MoveType type);
    };
}