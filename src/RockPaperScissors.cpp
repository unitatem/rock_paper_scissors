#include "RockPaperScissors.hpp"

RockPaperScissors::RockPaperScissors(GameInterface& gi) : game_interface{gi} {}

void RockPaperScissors::play() {
  game_interface.welcome();
  unsigned rounds = game_interface.getNumberOfRounds();
  (void)rounds;
}
