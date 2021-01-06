//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_INVALIDMOVE_H
#define UNO_INVALIDMOVE_H

#include <Moves/Move.h>

namespace Uno {
    class InvalidMove : public Move {
    public:
        void make() override;
        InvalidMove(Player &maker, GameOfUno &gameState,  MoveType moveType);
        MoveType moveType;
    };
}
#endif //UNO_INVALIDMOVE_H
