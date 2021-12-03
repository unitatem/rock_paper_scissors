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
    game_interface.showOpponentHand(algo_hand);

    evaluateRound(player_hand, algo_hand);

    // TODO show score
  }

  // game_interface.results;
}

// TODO this method should be refactored or Element enum should be refactored
void RockPaperScissors::evaluateRound(const Element& player_hand,
                                      const Element& algo_hand) {
  PlayOutcome outcome = rules.play(player_hand, algo_hand);

  if (outcome == PlayOutcome::WIN)
    ++player2score[Player::Human];
  else if (outcome == PlayOutcome::LOSS)
    ++player2score[Player::Algorithm];
}
