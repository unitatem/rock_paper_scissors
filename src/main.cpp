#include <iostream>

#include "algo_player/RandomPlayer.hpp"
#include "game/DefaultRules.hpp"
#include "game/RockPaperScissors.hpp"
#include "interface/CommandLineInterface.hpp"

int main() {
  CommandLineInterface cli;
  RandomPlayer player;
  DefaultRules rules;
  RockPaperScissors game(cli, player, rules);
  game.play();

  return 0;
}
