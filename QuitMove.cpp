//
// Created by Derek Lin on 12/12/19.
//

#include "QuitMove.h"
Uno::QuitMove::QuitMove(Uno::Player &maker, Uno::GameOfUno &gameState, Uno::MoveType moveType) :
        Move(maker, gameState), moveType(moveType) {
}
Uno::Move *Uno::Move::CreateQuit(Uno::Player &maker, Uno::GameOfUno &gameState) {
    return new QuitMove(maker, gameState, MoveType::QUIT);
}
void Uno::QuitMove::make() {
    _endsTurn = true;
    gameState.terminateGame();
}