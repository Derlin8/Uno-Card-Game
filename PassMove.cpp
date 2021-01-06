//
// Created by Derek Lin on 12/12/19.
//

#include "PassMove.h"
Uno::PassMove::PassMove(Uno::Player &maker, Uno::GameOfUno &gameState, Uno::MoveType moveType) :
        Move(maker, gameState), moveType(moveType) {
}
Uno::Move *Uno::Move::CreatePass(Player &maker, GameOfUno &gameState) {
    return new PassMove(maker, gameState, MoveType::PASS);
}
void Uno::PassMove::make() {
    if (!(maker.isHoldingPlayableCard() || maker.canDrawMoreCardsThisTurn())) {
        //player has no plays they can make
        _endsTurn = true;
    } else if (gameState.getRules().mustPlayCardEachTurn()) {
        std::cout << "You cannot pass. You must play a card this turn." << std::endl;
    } else if (maker.canDrawMoreCardsThisTurn()) {
        int cardsLeftToDraw = gameState.getRules().getMaxDrawsPerTurn() - maker.getNumCardsDrawnThisTurn();
        std::cout << "You cannot pass until you either play a card or draw at least "
                  << cardsLeftToDraw << " more cards." << std::endl;
    } else {
        _endsTurn = true;
    }
}