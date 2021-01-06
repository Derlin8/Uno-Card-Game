//
// Created by mfbut on 10/28/2019.
//

#ifndef ECS_36B_HOMEWORK_RULES_H
#define ECS_36B_HOMEWORK_RULES_H
#include <string>
namespace Uno {
  enum class RenegingOption { Any, LastDrawn };
  class Rules {
   public:
    static Rules loadRulesFromFile(const std::string& fileName);
    Rules(int startingHandSize,
          int drawLimit,
          int unoCalloutPenalty,
          int badUnoCalloutPenalty,
          RenegingOption renegingOption,
          bool mustPlayCardEachTurn);
    Rules();

    int getStartingHandSize() const;
    int getMaxDrawsPerTurn() const;
    int getUnoCalloutPenalty() const;
    int getBadUnoCalloutPenalty() const;
    RenegingOption getRenegingOption() const;
    bool mustPlayCardEachTurn() const;
    bool hasDrawLimit() const;

   private:
    int startingHandSize;
    int maxDrawsPerTurn;
    int unoCalloutPenalty, badUnoCalloutPenalty;
    RenegingOption renegingOption;
    bool _mustPlayCardEachTurn;

  };
}

#endif //ECS_36B_HOMEWORK_RULES_H
