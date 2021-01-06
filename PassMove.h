//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_PASSMOVE_H
#define UNO_PASSMOVE_H
#include "GameOfUno.h"
namespace Uno {
class PassMove : public Move {
public:
    void make() override;

    PassMove(Player &maker, GameOfUno &gameState, MoveType moveType);

    MoveType moveType;
};

}

#endif //UNO_PASSMOVE_H
