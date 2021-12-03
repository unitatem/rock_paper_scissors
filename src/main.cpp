#include <iostream>

#include "CommandLineInterface.hpp"
#include "RockPaperScissors.hpp"

int main() {
  CommandLineInterface cli;
  RockPaperScissors game(cli);
  game.play();

  return 0;
}
