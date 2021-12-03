#include "RockPaperScissors.hpp"

RockPaperScissors::RockPaperScissors(GameInterface& gi, AlgorithmicPlayer& ap,
                                     Rules& r)
    : game_interface{gi}, algo_player{ap}, rules{r} {}

void RockPaperScissors::play() {
  game_interface.welcome();
  int rounds = game_interface.getNumberOfRounds();

  for (int round = 1; round <= rounds; ++round) {
    Element player_hand = game_interface.getPlayerAction();
    Element algo_hand = algo_player.getHand();
    // TODO print opponents hand

    evaluateRound(player_hand, algo_hand);

    // TODO show score
  }

  // game_interface.results;
}

// TODO this method should be refactored or Element enum should be refactored
void RockPaperScissors::evaluateRound(const Element& player_hand,
                                      const Element& algo_hand) {
  (void)player_hand;
  (void)algo_hand;
  // hands2score.at({player_hand, algo_hand})(player2score);
}
