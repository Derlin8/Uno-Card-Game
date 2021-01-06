//
// Created by mfbut on 10/28/2019.
//
#include <iostream>
#include <fstream>
#include <limits>
#include "Rules.h"
#include "StringMethods.h"

Uno::Rules Uno::Rules::loadRulesFromFile(const std::string& fileName) {
  std::ifstream rulesFile(fileName);
  std::string line, option, separator, value;
  Rules rules;
  while((rulesFile >> option >> separator >> value)){
    if(option == "StartingHandSize"){
      rules.startingHandSize = std::stoi(value);
    }else if(option == "UnoCalloutPenalty"){
      rules.unoCalloutPenalty = std::stoi(value);
    }else if(option == "BadUnoCalloutPenalty"){
      rules.badUnoCalloutPenalty = std::stoi(value);
    }else if(option == "DrawLimit"){
      if(value == "None"){
        rules.maxDrawsPerTurn = std::numeric_limits<int>::max();
      }else{
        rules.maxDrawsPerTurn = std::stoi(value);
      }
    }else if(option == "Reneging"){
      if(value == "Any"){
        rules.renegingOption = RenegingOption::Any;
      }else if(value == "LastDrawn"){
        rules.renegingOption = RenegingOption::LastDrawn;
      }else{
        std::cout << "Error parsing rules file " << fileName << std::endl;
        std::cout << "Unknown Reneging Option: " << value << std::endl;
      }
    }else if(option == "MustPlayCardEachTurn"){
      value = StringMethods::tolower(value);
      if(value == "true"){
        rules._mustPlayCardEachTurn = true;
      }else if(value == "false"){
        rules._mustPlayCardEachTurn = false;
      }else{
        std::cout << "Bad value for MustPlayCardEachTurn: " << value << std::endl;
      };
    }
    else{
      std::cout << "Error parsing rules file " << fileName << std::endl;
      std::cout << "Could not parse " << option << separator << value << std::endl;
    }
  }
  return rules;
}

Uno::Rules::Rules(int startingHandSize,
                  int drawLimit,
                  int unoCalloutPenalty,
                  int badUnoCalloutPenalty,
                  Uno::RenegingOption renegingOption,
                  bool mustPlayCardEachTurn)
    : startingHandSize(startingHandSize),
      maxDrawsPerTurn(drawLimit),
      unoCalloutPenalty(unoCalloutPenalty),
      badUnoCalloutPenalty(badUnoCalloutPenalty),
      renegingOption(renegingOption),
      _mustPlayCardEachTurn(mustPlayCardEachTurn){}

Uno::Rules::Rules() : Rules(7, 1, 4, 0, RenegingOption::LastDrawn, false){}

int Uno::Rules::getStartingHandSize() const {
  return startingHandSize;
}

int Uno::Rules::getMaxDrawsPerTurn() const {
  return maxDrawsPerTurn;
}

int Uno::Rules::getUnoCalloutPenalty() const {
  return unoCalloutPenalty;
}

int Uno::Rules::getBadUnoCalloutPenalty() const {
  return badUnoCalloutPenalty;
}

Uno::RenegingOption Uno::Rules::getRenegingOption() const {
  return renegingOption;
}

bool Uno::Rules::mustPlayCardEachTurn() const {
  return _mustPlayCardEachTurn;
}

bool Uno::Rules::hasDrawLimit() const {
  return maxDrawsPerTurn == std::numeric_limits<int>::max();
}


