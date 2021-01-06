//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_PLAYCARDMOVE_H
#define UNO_PLAYCARDMOVE_H

#include <sstream>
#include "GameOfUno.h"
namespace Uno {
    class PlayCardMove : public Move {
    public:
        void make() override;

        PlayCardMove(Player &maker, GameOfUno &gameState, MoveType moveType, Card *playedCard, bool calledUno);

        Card *playedCard;
        bool calledUno;
        MoveType moveType;
    };
}
#endif //UNO_PLAYCARDMOVE_H
