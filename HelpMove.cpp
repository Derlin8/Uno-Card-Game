//
// Created by Derek Lin on 12/12/19.
//

#include "HelpMove.h"

Uno::Move *Uno::Move::CreateHelpRequest(Uno::Player &maker, Uno::GameOfUno &gameState) {
    return new HelpMove(maker, gameState, MoveType::HELP_REQUEST);
}

Uno::HelpMove::HelpMove(Uno::Player &maker, Uno::GameOfUno &gameState, Uno::MoveType moveType) :
        Move(maker, gameState), moveType(moveType) {
}

void Uno::HelpMove::make() {
    std::cout << "\t- play card_color card_value [uno]" << std::endl;
    std::cout << "\t- draw" << std::endl;
    std::cout << "\t- uno player_name" << std::endl;
    std::cout << "\t- skip" << std::endl;
    std::cout << "\t- quit" << std::endl;
    std::cout << "\t- help" << std::endl;
}