#include "game/DefaultRules.hpp"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// This is a helper function used only in tests in order to make output more
// clear.
std::ostream& operator<<(std::ostream& out, const PlayOutcome& e) {
  switch (e) {
    case PlayOutcome::WIN:
      out << "Win";
      break;
    case PlayOutcome::LOSS:
      out << "Loss";
      break;
    case PlayOutcome::TIE:
      out << "Tie";
      break;
  }
  return out;
}

TEST(DefaultRulesTest, check_all_rules) {
  // Given
  DefaultRules rules;

  // When
  EXPECT_EQ(rules.play(Element::Rock, Element::Rock), PlayOutcome::TIE);
  EXPECT_EQ(rules.play(Element::Rock, Element::Paper), PlayOutcome::LOSS);
  EXPECT_EQ(rules.play(Element::Rock, Element::Scissors), PlayOutcome::WIN);

  EXPECT_EQ(rules.play(Element::Paper, Element::Rock), PlayOutcome::WIN);
  EXPECT_EQ(rules.play(Element::Paper, Element::Paper), PlayOutcome::TIE);
  EXPECT_EQ(rules.play(Element::Paper, Element::Scissors), PlayOutcome::LOSS);

  EXPECT_EQ(rules.play(Element::Scissors, Element::Rock), PlayOutcome::LOSS);
  EXPECT_EQ(rules.play(Element::Scissors, Element::Paper), PlayOutcome::WIN);
  EXPECT_EQ(rules.play(Element::Scissors, Element::Scissors), PlayOutcome::TIE);
}
