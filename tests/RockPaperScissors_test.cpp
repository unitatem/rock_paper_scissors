#include "game/RockPaperScissors.hpp"

#include "AlgorithmicPlayer_mock.hpp"
#include "GameInterface_mock.hpp"
#include "game/DefaultRules.hpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Return;
using ::testing::Sequence;

class RockPaperScissorsTest : public ::testing::Test {
 protected:
  GameInterfaceMock interface_mock;
  AlgorithmicPlayerMock algo_mock;
  DefaultRules rules;

  Sequence s1, s2;

  void SetUp() override { EXPECT_CALL(interface_mock, welcome()).Times(1); }

  void setRoundExpectations(const Element& player_hand,
                            const Element& algo_hand, int round,
                            int player_points, int algo_points) {
    EXPECT_CALL(interface_mock, getPlayerAction())
        .InSequence(s1)
        .WillOnce(Return(player_hand));
    EXPECT_CALL(algo_mock, getHand())
        .InSequence(s2)
        .WillOnce(Return(algo_hand));
    EXPECT_CALL(interface_mock, showOpponentHand(algo_hand)).InSequence(s2);
    EXPECT_CALL(interface_mock, showScore(round, player_points, algo_points))
        .InSequence(s1, s2);
  }
};

TEST_F(RockPaperScissorsTest, play__1round_1vs0) {
  // Given
  EXPECT_CALL(interface_mock, getNumberOfRounds())
      .InSequence(s1, s2)
      .WillOnce(Return(1));
  // round 1
  setRoundExpectations(Element::Rock, Element::Scissors, 1, 1, 0);

  EXPECT_CALL(interface_mock, showGameResults(1, 0)).InSequence(s1, s2);

  // When
  RockPaperScissors rps(interface_mock, algo_mock, rules);
  rps.play();
}

TEST_F(RockPaperScissorsTest, play__3rounds_2vs1) {
  // Given
  EXPECT_CALL(interface_mock, getNumberOfRounds())
      .InSequence(s1, s2)
      .WillOnce(Return(3));
  // round 1
  setRoundExpectations(Element::Rock, Element::Scissors, 1, 1, 0);
  // round 2
  setRoundExpectations(Element::Paper, Element::Scissors, 2, 1, 1);
  // round 3
  setRoundExpectations(Element::Scissors, Element::Paper, 3, 2, 1);

  EXPECT_CALL(interface_mock, showGameResults(2, 1)).InSequence(s1, s2);

  // When
  RockPaperScissors rps(interface_mock, algo_mock, rules);
  rps.play();
}
