//
// Created by mfbut on 10/4/2019.
//

#include <sstream>
#include <iostream>
#include <string>
#include "InputValidation.h"

int InputValidation::getValidInt(const std::string& prompt) {
  std::string lineRead;
  int val;
  bool readSuccessful = false;
  do {
    std::cout << prompt;
    std::getline(std::cin, lineRead); // grab the line
    std::stringstream lineParser(lineRead); //put it into a string stream so we can parse it
    lineParser >> val; //read what we want
    readSuccessful = StreamOnlyContainsWhiteSpace(lineParser); //check that there isn't anything left
  } while (!readSuccessful); //keep asking until they give me what I want
  return val;
}

/**
 * Check that the stream is empty or contains only white space
 * @param stream: The stream to read from which is modified by the read
 * @return
 */
bool InputValidation::StreamOnlyContainsWhiteSpace(std::istream& stream) {
  char c = '!';
  if (!stream) { //if you can't read from the stream
    return false; //something is wrong with the stream
  } else {
    stream >> c; // attempt to read a nonwhitespace character
    //if the stream is bad it means we failed to read
    //and we should since there shouldn't be anything left
    return !stream;
  }
}

int InputValidation::getPositiveInt(const std::string& prompt) {
  return getIntAtLeast(prompt, 0);
}

int InputValidation::getIntAtLeast(const std::string& prompt, int min) {
  int val;
  do {
    val = getValidInt(prompt);
  } while (val < min);
  return val;
}

std::string InputValidation::getWord(const std::string& prompt) {
  std::string lineRead;
  std::string val;
  bool readSuccessful = false;
  do {
    std::cout << prompt;
    std::getline(std::cin, lineRead); // grab the line
    std::stringstream lineParser(lineRead); //put it into a string stream so we can parse it
    lineParser >> val; //read what we want
    readSuccessful = StreamOnlyContainsWhiteSpace(lineParser); //check that there isn't anything left
  } while (!readSuccessful); //keep asking until they give me what I want
  return val;
}




