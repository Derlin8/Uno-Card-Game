//
// Created by mfbut on 10/26/2019.
//

#include <string>
#include <sstream>
#include <iostream>
#include "Move.h"
#include "Player.h"
#include "InputValidation.h"
#include "StringMethods.h"
#include "Cards/Card.h"
#include "GameOfUno.h"

Uno::Move *Uno::Move::GetMoveFromUser(Player &maker, GameOfUno &gameState) {
    std::string line;
    DisplayPrompt(maker);
    std::getline(std::cin, line);
    return toMove(line, maker, gameState);
}

Uno::Move::Move(Uno::Player &maker, Uno::GameOfUno &gameState) : maker(maker), gameState(gameState), _endsTurn(false) {}

void Uno::Move::DisplayPrompt(const Uno::Player &maker) {
    std::cout << maker.getName() << " enter your move or h for help: ";
}

bool Uno::Move::RepresentsValidMove(const std::string &line) {
    return RepresentsHelpRequest(line) ||
           RepresentsPlayCard(line) ||
           RepresentsCallOut(line) ||
           RepresentsQuit(line);
}

bool Uno::Move::RepresentsHelpRequest(const std::string &line) {
    const std::string neededKeyWord("help");
    std::stringstream parser(line);
    std::string keyword;
    parser >> keyword;
    return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(keyword, neededKeyWord);
}

bool Uno::Move::RepresentsPlayCard(const std::string &line) {
    const std::string neededKeyWord("play");
    std::stringstream parser(line);
    std::string command;
    parser >> command;
    return StringMethods::isPrefix(command, neededKeyWord);
//    std::string command, cardColor, uno;
//    int cardValue;
//    parser >> command >> cardColor >> cardValue;
//
//    if (parser) { //if we read everything that was required
//        parser >> uno; //try to read in uno
//        if (parser) { //if we got something
//            return InputValidation::StreamOnlyContainsWhiteSpace(parser) &&
//                   StringMethods::isPrefix(command, neededKeyWord) &&
//                   StringMethods::isPrefix(uno, optionalUno);
//        } else { //keyword must match and there can't be anything else
//            return StringMethods::isPrefix(command, neededKeyWord) && uno.empty();
//        }
//    } else {
//        return false;
//    }
}

bool Uno::Move::RepresentsCallOut(const std::string &line) {
    const std::string neededKeyWord("uno");
    std::stringstream parser(line);
    std::string keyword, playerName;
    parser >> keyword >> playerName; //TODO: allow player names to contain whitespace
    return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(keyword, neededKeyWord);
}

bool Uno::Move::RepresentsQuit(const std::string &line) {
    const std::string neededKeyWord("quit");
    std::stringstream parser(line);
    std::string keyword;
    parser >> keyword;
    return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(keyword, neededKeyWord);
}

bool Uno::Move::RepresentsDraw(const std::string &line) {
    const std::string neededKeyWord("draw");
    std::stringstream parser(line);
    std::string keyword;
    parser >> keyword;
    return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(keyword, neededKeyWord);
}

bool Uno::Move::RepresentsPass(const std::string &line) {
    const std::string neededKeyWord("skip");
    std::stringstream parser(line);
    std::string keyword;
    parser >> keyword;
    return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(keyword, neededKeyWord);

}

Uno::Move *Uno::Move::toMove(const std::string &stringMove, Uno::Player &maker, GameOfUno &gameState) {
    if (RepresentsPlayCard(stringMove)) {
        return CreatePlayCardMove(stringMove, maker, gameState);
    } else if (RepresentsCallOut(stringMove)) {
        return CreateCallOutMove(stringMove, maker, gameState);
    } else if (RepresentsQuit(stringMove)) {
        return CreateQuit(maker, gameState);
    } else if (RepresentsHelpRequest(stringMove)) {
        return CreateHelpRequest(maker, gameState);
    } else if (RepresentsDraw(stringMove)) {
        return CreateDraw(maker, gameState);
    } else if (RepresentsPass(stringMove)) {
        return CreatePass(maker, gameState);
    } else {
        return CreateUnknownMove(maker, gameState);
    }
}

//void Uno::Move::make() {
//  if (moveType == MoveType::PLAY_CARD) {
//    playCard();
//  } else if (moveType == MoveType::DRAW) {
//    draw();
//  } else if (moveType == MoveType::CALLOUT) {
//    callout();
//  } else if (moveType == MoveType::QUIT) {
//    quitGame();
//  } else if (moveType == MoveType::PASS) {
//    pass();
//  } else if (moveType == MoveType::HELP_REQUEST) {
//    provideHelpRequest();
//  } else {
//    stateUnknownCommand();
//  }
//}

bool Uno::Move::endsTurn() const {
    return _endsTurn;
}





















