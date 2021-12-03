#ifndef ROCKPAPERSCISSORS_HPP_
#define ROCKPAPERSCISSORS_HPP_

#include "algo_player/AlgorithmicPlayer.hpp"
#include "interface/GameInterface.hpp"

class RockPaperScissors {
 private:
  GameInterface& game_interface;
  AlgorithmicPlayer& algo_player;

 public:
  RockPaperScissors(GameInterface& gi, AlgorithmicPlayer& ap);

  void play();
};

#endif  // ROCKPAPERSCISSORS_HPP_