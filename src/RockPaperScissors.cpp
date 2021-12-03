#include "RockPaperScissors.hpp"

RockPaperScissors::RockPaperScissors(GameInterface& gi) : game_interface{gi} {}

void RockPaperScissors::play() {
  game_interface.welcome();
  int rounds = game_interface.getNumberOfRounds();

  for (int round = 1; round <= rounds; ++round) {
    Element player_hand = game_interface.getPlayerAction();
    (void)player_hand;

    // TODO NPC

    // TODO engine
  }

  // game_interface.results;
}
