//
// Created by mfbut on 10/26/2019.
//

#ifndef ECS_36B_HOMEWORK_STRINGMETHODS_H
#define ECS_36B_HOMEWORK_STRINGMETHODS_H
#include <string>
namespace StringMethods {
  std::string toupper(const std::string& str);
  std::string tolower(const std::string& str);
  bool ignoreCaseEqual(const std::string& str1, const std::string& str2);
  bool isPrefix(const std::string& prefix, const std::string& str, bool ignoreCase = true);
  bool startsWith(const std::string& str, const std::string& prefix, bool ignoreCase = true);
}

#endif //ECS_36B_HOMEWORK_STRINGMETHODS_H
