#include "algo_player/RandomPlayer.hpp"

#include <unordered_map>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(RandomPlayerTest, expect_random_hands_with_uniform_distribution) {
  // Given
  std::unordered_map<Element, int> hand2cnt;
  RandomPlayer player(5ul);

  // When
  for (int i = 0; i < 100; ++i) {
    Element hand = player.getHand();
    ++hand2cnt[hand];
  }

  // Then
  std::cout << "Rock cnt=" << hand2cnt[Element::Rock]
            << ", Paper cnt=" << hand2cnt[Element::Paper]
            << ", Scissors cnt=" << hand2cnt[Element::Scissors] << std::endl;
  EXPECT_TRUE(hand2cnt[Element::Rock] > 0);
  EXPECT_TRUE(hand2cnt[Element::Paper] > 0);
  EXPECT_TRUE(hand2cnt[Element::Scissors] > 0);
}
