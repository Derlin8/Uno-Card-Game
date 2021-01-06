//
// Created by mfbut on 10/20/2019.
//
#include <chrono>
#include <iostream>
#include <string>
#include "GameOfUno.h"

int main(int argc, char** argv) {
  int seed = std::chrono::system_clock::now().time_since_epoch().count();
  if (argc < 3) {
    std::cout << "Not enough arguments given." << std::endl;
    std::cout << "Usage: uno deckFile rulesFile [seed]" << std::endl;
  }else {
    const char* deckFileName = argv[1];
    const char* ruleFileName = argv[2];

    if (argc == 4) {
      seed = std::stoi(argv[3]);
    }

    Uno::GameOfUno game = Uno::GameOfUno::createGame(deckFileName, ruleFileName, seed);
    game.play();
  }
  return 0;
}
