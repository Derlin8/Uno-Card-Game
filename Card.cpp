//
// Created by mfbut on 10/26/2019.
//

#include <sstream>
#include <algorithm>
#include "Card.h"
#include "InputValidation.h"
#include "NumberCard.h"
#include "ReverseCard.h"
#include "WildCard.h"
#include "WildCardDrawNCard.h"
#include "DrawNCard.h"

Uno::Card *Uno::Card::toCard(const std::string &stringMove) {
    if (RepresentsNumberCard(stringMove)) {
        return getNumberCard(stringMove);
    } else if (RepresentsReverseCard(stringMove)) {
        return getReverseCard(stringMove);
    } else if (RepresentsSkipCard(stringMove)) {
        return getSkipCard(stringMove);
    } else if (RepresentsWildCard(stringMove)) {
        return getWildCard(stringMove);
    } else if (RepresentsWildCardDrawNCard(stringMove)) {
        return getWildCardDrawNCard(stringMove);
    } else if (RepresentsDrawNCard(stringMove)) {
        return getDrawNCard(stringMove);
    } else {
        return NULL;
    }

    return NULL;
}

 bool Uno::Card::RepresentsNumberCard(const std::string &line) {
     std::stringstream parser(line);
     std::string keyword;
     std::string color;
     int number;
     parser >> keyword;
     parser >> color;
     parser >> number;
     return InputValidation::StreamOnlyContainsWhiteSpace(parser);
}

 Uno::Card* Uno::Card::getNumberCard(const std::string &line) {
    std::stringstream parser(line);
    std::string keyword;
    std::string color;
    int number;
    parser >> keyword;
    parser >> color;
    parser >> number;
    return new NumberCard("NumberCard", color, number);
}

 bool Uno::Card::RepresentsReverseCard(const std::string &line) {
     const std::string neededKeyWord("reverse");
     std::stringstream parser(line);
     std::string keyword;
     std::string color;
     std::string reverse;
     parser >> keyword;
     parser >> color;
     parser >> reverse;
     return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(reverse, neededKeyWord);
}


Uno::Card* Uno::Card::getReverseCard(const std::string &line) {
    std::stringstream parser(line);
    std::string keyword;
    std::string color;
    std::string reverse;
    parser >> keyword;
    parser >> color;
    parser >> reverse;
    //TODO
    return new ReverseCard("ReverseCard", color, -1);
}


 bool Uno::Card::RepresentsSkipCard(const std::string &line) {
     const std::string neededKeyWord("skip");
     std::stringstream parser(line);
     std::string keyword;
     std::string color;
     std::string skip;
     parser >> keyword;
     parser >> color;
     parser >> skip;
     return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(skip, neededKeyWord);
}

Uno::Card* Uno::Card::getSkipCard(const std::string &line) {
    std::stringstream parser(line);
    std::string keyword;
    std::string color;
    std::string skip;
    parser >> keyword;
    parser >> color;
    parser >> skip;
    // TODO
    return new SkipCard("SkipCard", color, -1);
}



 bool Uno::Card::RepresentsWildCard(const std::string &line) {
     const std::string neededKeyWord("wild");
     std::stringstream parser(line);
     std::string keyword;
     std::string color;
     std::string wild;
     parser >> keyword;
     parser >> wild;
     parser >> color;
     return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(wild, neededKeyWord);
}

Uno::Card* Uno::Card::getWildCard(const std::string &line) {
    std::stringstream parser(line);
    std::string keyword;
    std::string color;
    std::string wild;
    parser >> keyword;
    parser >> wild;
    parser >> color;
    return new WildCard("WildCard", color,-1);
}

 bool Uno::Card::RepresentsWildCardDrawNCard(const std::string &line) {
     const std::string neededKeyWordWild("wild");
     const std::string neededKeyWordDraw("draw");
     std::stringstream parser(line);
     std::string keyword;
     std::string color;
     std::string wild;
     std::string draw;
     int number;
     parser >> keyword;
     parser >> wild;
     parser >> draw;
     parser >> number;
     parser >> color;
     return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(wild, neededKeyWordWild) && StringMethods::isPrefix(draw, neededKeyWordDraw);
}

Uno::Card* Uno::Card::getWildCardDrawNCard(const std::string &line) {
    std::stringstream parser(line);
    std::string keyword;
    std::string color;
    std::string wild;
    std::string draw;
    int number;
    parser >> keyword;
    parser >> wild;
    parser >> draw;
    parser >> number;
    parser >> color;
    return new WildDrawNCard("WildDrawNCard" , color, -1, number);
}


 bool Uno::Card::RepresentsDrawNCard(const std::string &line) {
     const std::string neededKeyWord("draw");
     std::stringstream parser(line);
     std::string keyword;
     std::string color;
     std::string draw;
     int number;
     parser >> keyword;
     parser >> color;
     parser >> draw;
     parser >> number;
     return InputValidation::StreamOnlyContainsWhiteSpace(parser) && StringMethods::isPrefix(draw, neededKeyWord);
}

Uno::Card* Uno::Card::getDrawNCard(const std::string &line) {
    std::stringstream parser(line);
    std::string keyword;
    std::string color;
    std::string draw;
    int number;
    parser >> keyword;
    parser >> color;
    parser >> draw;
    parser >> number;
    return new DrawNCard("DrawNCard", color, -1, number);
}
