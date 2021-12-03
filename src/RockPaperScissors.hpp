#ifndef ROCKPAPERSCISSORS_HPP_
#define ROCKPAPERSCISSORS_HPP_

#include "GameInterface.hpp"

class RockPaperScissors {
 private:
  GameInterface& game_interface;

 public:
  RockPaperScissors(GameInterface& gi);

  void play();
};

#endif  // ROCKPAPERSCISSORS_HPP_