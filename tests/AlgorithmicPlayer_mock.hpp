#ifndef ALGORITHMICPLAYER_MOCK_HPP_
#define ALGORITHMICPLAYER_MOCK_HPP_

#include "algo_player/AlgorithmicPlayer.hpp"
#include "gmock/gmock.h"

class AlgorithmicPlayerMock : public AlgorithmicPlayer {
 public:
  MOCK_METHOD(Element, getHand, (), (override));
};

#endif  // ALGORITHMICPLAYER_MOCK_HPP_