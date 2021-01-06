//
// Created by Derek Lin on 12/12/19.
//

#include "DrawCardMove.h"
Uno::DrawCardMove::DrawCardMove(Uno::Player &maker, Uno::GameOfUno &gameState, Uno::MoveType moveType) :
        Move(maker, gameState), moveType(moveType) {
}

Uno::Move *Uno::Move::CreateDraw(Uno::Player &maker, Uno::GameOfUno &gameState) {
    return new DrawCardMove(maker, gameState, MoveType::DRAW);
}

void Uno::DrawCardMove::make() {
    if (maker.getNumCardsDrawnThisTurn() < gameState.getRules().getMaxDrawsPerTurn()) {
        if (gameState.canDrawCard()) {
            maker.drawCard();
            _endsTurn = !(maker.canDrawMoreCardsThisTurn() || maker.isHoldingPlayableCard());
        } else {
            std::cout << "There are no cards left to draw. Please play a card." << std::endl;
        }
    } else {
        std::cout << "You have already drawn the maximum number of cards this round." << std::endl;
    }
}