#include "RandomPlayer.hpp"

#include "Logger.hpp"

RandomPlayer::RandomPlayer(long unsigned seed)
    : random_generator{seed},
      distribution{distribution_min, distribution_max} {}

Element RandomPlayer::getHand() {
  int random_number = distribution(random_generator);

  switch (random_number) {
    case 0:
      return Element::Rock;
    case 1:
      return Element::Paper;
    default:
      return Element::Scissors;
  }
}
