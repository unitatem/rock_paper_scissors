#include "RockPaperScissors.hpp"

RockPaperScissors::RockPaperScissors(GameInterface& gi) : game_interface{gi} {}

void RockPaperScissors::play() {
  game_interface.welcome();
  int rounds = game_interface.getNumberOfRounds();
  (void)rounds;
}
