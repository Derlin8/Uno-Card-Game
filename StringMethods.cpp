//
// Created by mfbut on 10/26/2019.
//
#include <cctype>
#include "StringMethods.h"

std::string StringMethods::toupper(const std::string& str) {
  std::string upper(str);
  for (auto& letter : upper) {
    letter = ::toupper(letter);
  }
  return upper;
}

std::string StringMethods::tolower(const std::string& str) {
  std::string lower(str);
  for (auto& letter : lower) {
    letter = ::tolower(letter);
  }
  return lower;
}

bool StringMethods::isPrefix(const std::string& prefix, const std::string& str, bool ignoreCase) {
  return startsWith(str, prefix, ignoreCase);
}

bool StringMethods::startsWith(const std::string& str, const std::string& prefix, bool ignoreCase) {
  //if the prefix is longer than the string it can't be a prefix
  if (prefix.size() > str.size()) {
    return false;
  }

  char strLetter, prefixLetter;
  //iterate through the strings in parallel
  for (auto strItr = str.begin(), prefixItr = prefix.begin();
       strItr != str.end() && prefixItr != prefix.end();
       ++strItr, ++prefixItr) {
    strLetter = *strItr;
    prefixLetter = *prefixItr;
    if (ignoreCase) { //handle case issues
      strLetter = ::tolower(strLetter);
      prefixLetter = ::tolower(prefixLetter);
    }
    if (prefixLetter != strLetter) {
      return false;
    }
  }
  return true;
}

bool StringMethods::ignoreCaseEqual(const std::string& str1, const std::string& str2) {
  return tolower(str1) == tolower(str2);
}


