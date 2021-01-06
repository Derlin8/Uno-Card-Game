//
// Created by Derek Lin on 12/12/19.
//


#include <Cards/NumberCard.h>
#include <Cards/ReverseCard.h>
#include <Cards/SkipCard.h>
#include "PlayCardMove.h"
#include "InvalidMove.h"

Uno::PlayCardMove::PlayCardMove(Uno::Player &maker, Uno::GameOfUno &gameState, Uno::MoveType moveType, Card *playedCard,
                                bool calledUno) :
        Move(maker, gameState), playedCard(playedCard), calledUno(calledUno), moveType(moveType) {
}
Uno::Move *Uno::Move::CreatePlayCardMove(const std::string &stringMove, Uno::Player &maker, Uno::GameOfUno &gameState) {
    std::stringstream parser(stringMove);
    std::string keyword, cardColor, uno;
    int cardValue;
    bool calledUno;
    parser >> keyword >> cardColor >> cardValue >> uno;
    calledUno = !uno.empty();
    Card* playedCard = Uno::Card::toCard(parser.str());

    if (playedCard == NULL) {
        return new InvalidMove(maker, gameState, MoveType::UNKNOWN);
    }

    return new PlayCardMove(maker, gameState, MoveType::PLAY_CARD, playedCard, calledUno);
}
void Uno::PlayCardMove::make() {
    if (maker.isHolding(playedCard)) {
        if (maker.canPlay(playedCard)) {
            maker.playCard(playedCard, calledUno);
            if (calledUno) {
                std::cout << maker.getName() << " shouted " << "UNO." << std::endl;
            }
            _endsTurn = true;
            if (maker.getNumCardsInHand() > 1 && calledUno) {
                std::cout << "You can't call UNO unless playing your second to last card." << std::endl;
                int penaltyCardsDrawn = maker.drawPenaltyCards(gameState.getRules().getBadUnoCalloutPenalty());
                if (penaltyCardsDrawn > 0) {
                    std::cout << "You had to draw " << penaltyCardsDrawn << " cards for calling UNO early."
                              << std::endl;
                }
            }
        } else {
            std::cout << "You can't play a " << maker.getCardInHand(playedCard)->printCard() << " right now."
                      << std::endl;
            std::cout << "Your card must match either the color or value of the top card on the discard pile which is "
                      <<
                      gameState.getCardOnTopOfDiscardPile()->printCard() << "." << std::endl;
        }
    } else {
        std::cout << "You can't play a " << playedCard->printCard() << " because you aren't holding one." << std::endl;
    }
}