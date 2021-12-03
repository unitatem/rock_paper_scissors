#ifndef ROCKPAPERSCISSORS_HPP_
#define ROCKPAPERSCISSORS_HPP_

#include <unordered_map>

#include "Rules.hpp"
#include "algo_player/AlgorithmicPlayer.hpp"
#include "interface/GameInterface.hpp"

class RockPaperScissors {
 private:
  GameInterface& game_interface;
  AlgorithmicPlayer& algo_player;
  Rules& rules;

  enum class Player { Algorithm, Human };
  using Score = unsigned int;
  using PlayerScore = std::unordered_map<Player, Score>;
  PlayerScore player2score;

 public:
  RockPaperScissors(GameInterface& gi, AlgorithmicPlayer& ap, Rules& r);

  void play();

 private:
  void evaluateRound(const Element& player_hand, const Element& algo_hand);
};

#endif  // ROCKPAPERSCISSORS_HPP_