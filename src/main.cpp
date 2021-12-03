#include <iostream>

#include "CommandLineInterface.hpp"
#include "RandomPlayer.hpp"
#include "RockPaperScissors.hpp"

int main() {
  CommandLineInterface cli;
  RandomPlayer player;
  RockPaperScissors game(cli, player);
  game.play();

  return 0;
}
