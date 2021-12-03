#include "RockPaperScissors.hpp"

RockPaperScissors::RockPaperScissors(GameInterface& gi, AlgorithmicPlayer& ap)
    : game_interface{gi}, algo_player{ap} {}

void RockPaperScissors::play() {
  game_interface.welcome();
  int rounds = game_interface.getNumberOfRounds();

  for (int round = 1; round <= rounds; ++round) {
    Element player_hand = game_interface.getPlayerAction();
    (void)player_hand;

    Element algo_hand = algo_player.getHand();
    (void)algo_hand;

    // TODO engine
  }

  // game_interface.results;
}
