//
// Created by Derek Lin on 12/12/19.
//

#include "CalloutMove.h"
Uno::CalloutMove::CalloutMove(Uno::Player &maker, Uno::GameOfUno &gameState, const std::string &calledOutPlayersName,
                              MoveType moveType) :
        Move(maker, gameState), calledOutPlayersName(calledOutPlayersName), moveType(moveType) {
}
Uno::Move *Uno::Move::CreateCallOutMove(const std::string &stringMove, Uno::Player &maker, Uno::GameOfUno &gameState) {
    std::stringstream parser(stringMove);
    std::string keyword, playerName;
    parser >> keyword >> playerName; //TODO: allow player names to contain whitespace

    return new CalloutMove(maker, gameState, playerName, MoveType::CALLOUT);

}
void Uno::CalloutMove::make() {
    if (gameState.isPlayer(calledOutPlayersName)) {
        const Rules &rules = gameState.getRules();
        int penaltyCardsDrawn = 0;
        Player &calledOutPlayer = gameState.getPlayer(calledOutPlayersName);
        if (calledOutPlayer == maker) {
            std::cout << "You can't call UNO on yourself." << std::endl;
        } else if (calledOutPlayer.getNumCardsInHand() == 1) {
            if (calledOutPlayer.calledUno()) {
                std::cout << calledOutPlayer.getName() << " DID call UNO." << std::endl;
                penaltyCardsDrawn = maker.drawPenaltyCards(rules.getBadUnoCalloutPenalty());
                if (penaltyCardsDrawn > 0) {
                    std::cout << "You had to draw " << penaltyCardsDrawn << " cards for a bad UNO call." << std::endl;
                }
            } else {
                std::cout << "You called out " << calledOutPlayer.getName() << " for not saying UNO." << std::endl;
                penaltyCardsDrawn = calledOutPlayer.drawPenaltyCards(rules.getUnoCalloutPenalty());
                if (penaltyCardsDrawn > 0) {
                    std::cout << calledOutPlayer.getName() << " had to draw " << penaltyCardsDrawn
                              << " cards for forgetting to call UNO." << std::endl;
                }
            }
        } else {
            std::cout << "You can't call UNO on " << calledOutPlayer.getName() <<
                      " because they have more than 1 card in their hand " << std::endl;
            penaltyCardsDrawn = maker.drawPenaltyCards(rules.getBadUnoCalloutPenalty());
            if (penaltyCardsDrawn > 0) {
                std::cout << "You had to draw " << penaltyCardsDrawn << " cards for a bad UNO call." << std::endl;
            }
        }
    } else {
        std::cout << calledOutPlayersName << " is not in this game." << std::endl;
    }
}
