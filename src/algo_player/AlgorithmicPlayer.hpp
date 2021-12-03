#ifndef ALGORITHMICPLAYER_HPP_
#define ALGORITHMICPLAYER_HPP_

#include "game/Element.hpp"

class AlgorithmicPlayer {
 public:
  virtual ~AlgorithmicPlayer();

  virtual Element getHand() = 0;
};

#endif  // ALGORITHMICPLAYER_HPP_