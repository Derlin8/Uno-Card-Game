//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_QUITMOVE_H
#define UNO_QUITMOVE_H
#include "GameOfUno.h"
namespace Uno {
    class QuitMove : public Move {
    public:
        void make() override;

        QuitMove(Player &maker, GameOfUno &gameState, MoveType moveType);

        MoveType moveType;
    };
} 
#endif //UNO_QUITMOVE_H
