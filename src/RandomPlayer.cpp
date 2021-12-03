#include "RandomPlayer.hpp"

#include "Logger.hpp"

RandomPlayer::RandomPlayer(long unsigned seed)
    : random_generator{seed},
      distribution{0, 2}  // range is inclusive <a, b>
{}

Element RandomPlayer::getHand() {
  int random_number = distribution(random_generator);

  switch (random_number) {
    case 0:
      return Element::Rock;
      break;
    case 1:
      return Element::Paper;
      break;
    case 2:
      return Element::Scissors;
      break;
  }

  // TODO fix impossible case
  return Element::Rock;
}
