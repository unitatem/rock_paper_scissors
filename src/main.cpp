#include <iostream>

#include "algo_player/RandomPlayer.hpp"
#include "game/RockPaperScissors.hpp"
#include "interface/CommandLineInterface.hpp"

int main() {
  CommandLineInterface cli;
  RandomPlayer player;
  RockPaperScissors game(cli, player);
  game.play();

  return 0;
}
