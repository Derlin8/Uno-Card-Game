//
// Created by Derek Lin on 12/12/19.
//

#include "InvalidMove.h"

Uno::InvalidMove::InvalidMove(Uno::Player &maker, Uno::GameOfUno &gameState, Uno::MoveType moveType) :
        Move(maker, gameState), moveType(moveType) {
}
Uno::Move* Uno::Move::CreateUnknownMove(Uno::Player &maker, Uno::GameOfUno &gameState) {
    return new InvalidMove(maker, gameState, MoveType::UNKNOWN);
}
void Uno::InvalidMove::make() {
    std::cout << "Unknown command entered." << std::endl;
    std::cout << "\t- play card_color card_value [uno]" << std::endl;
    std::cout << "\t- draw" << std::endl;
    std::cout << "\t- uno player_name" << std::endl;
    std::cout << "\t- skip" << std::endl;
    std::cout << "\t- quit" << std::endl;
    std::cout << "\t- help" << std::endl;
}