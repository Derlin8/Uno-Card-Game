//
// Created by mfbut on 10/4/2019.
//

#ifndef INPUTVALIDATION_INPUTVALIDATION_H
#define INPUTVALIDATION_INPUTVALIDATION_H
#include <istream>
#include <string>
#include <set>
#include "StringMethods.h"
namespace InputValidation {
  using options = std::set<std::string>;
  bool StreamOnlyContainsWhiteSpace(std::istream& stream);
  int getValidInt(const std::string& prompt);
  int getPositiveInt(const std::string& prompt);
  int getIntAtLeast(const std::string& prompt, int min);
  std::string getWord(const std::string& prompt);

}

#endif //INPUTVALIDATION_INPUTVALIDATION_H
