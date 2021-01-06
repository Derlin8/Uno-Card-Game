//
// Created by Derek Lin on 12/12/19.
//

#ifndef UNO_CALLOUTMOVE_H
#define UNO_CALLOUTMOVE_H

#include "GameOfUno.h"
#include <sstream>
namespace Uno {
    class CalloutMove : public Move {
    public:
        void make() override;
        CalloutMove(Player &maker, GameOfUno &gameState, const std::string &calledOutPlayersName, MoveType moveType);
        std::string calledOutPlayersName;
        MoveType moveType;
    };
}
#endif //UNO_CALLOUTMOVE_H
