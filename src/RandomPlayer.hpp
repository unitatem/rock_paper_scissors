#ifndef RANDOMPLAYER_HPP_
#define RANDOMPLAYER_HPP_

#include <random>

#include "AlgorithmicPlayer.hpp"

class RandomPlayer : public AlgorithmicPlayer {
 private:
  std::mt19937 random_generator;
  std::uniform_int_distribution<> distribution;

 public:
  RandomPlayer(long unsigned seed = std::random_device()());
  Element getHand() override;
};

#endif  // RANDOMPLAYER_HPP_