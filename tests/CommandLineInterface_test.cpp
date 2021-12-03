#include "interface/CommandLineInterface.hpp"

#include <sstream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

// This is a helper function used only in tests in order to make output more
// clear.
std::ostream& operator<<(std::ostream& out, const Element& e) {
  switch (e) {
    case Element::Rock:
      out << "Rock";
      break;
    case Element::Paper:
      out << "Paper";
      break;
    case Element::Scissors:
      out << "Scissors";
      break;
  }
  return out;
}

class CommandLineInterfaceTest : public ::testing::Test {
 protected:
  std::istringstream fake_input;
  std::ostringstream fake_output;

  CommandLineInterface create_SUT() {
    return CommandLineInterface(fake_input, fake_output);
  }

  CommandLineInterface create_SUT_with(const std::string& user_input) {
    fake_input = std::istringstream(user_input);
    return CommandLineInterface(fake_input, fake_output);
  }
};

TEST_F(CommandLineInterfaceTest, getNumberOfRounds__positive_number) {
  // Given
  std::string user_input = "22";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getNumberOfRounds(), 22);
}

TEST_F(CommandLineInterfaceTest, getNumberOfRounds__negative_number) {
  // Given
  std::string user_input = "-47";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getNumberOfRounds(), -47);
}

TEST_F(CommandLineInterfaceTest, getPlayerAction__map_closed_fist_to_rock) {
  // Given
  std::string user_input = "R";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getPlayerAction(), Element::Rock);
}

TEST_F(CommandLineInterfaceTest, getPlayerAction__map_open_hand_to_paper) {
  // Given
  std::string user_input = "P";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getPlayerAction(), Element::Paper);
}

TEST_F(CommandLineInterfaceTest, getPlayerAction__map_two_fingers_to_scissors) {
  // Given
  std::string user_input = "S";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getPlayerAction(), Element::Scissors);
}

TEST_F(CommandLineInterfaceTest, showOpponentHand__show_rock) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showOpponentHand(Element::Rock);

  // Then
  EXPECT_EQ(fake_output.str(), "Opponent's hand is Rock\n");
}

TEST_F(CommandLineInterfaceTest, showOpponentHand__show_paper) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showOpponentHand(Element::Paper);

  // Then
  EXPECT_EQ(fake_output.str(), "Opponent's hand is Paper\n");
}

TEST_F(CommandLineInterfaceTest, showOpponentHand__show_scissors) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showOpponentHand(Element::Scissors);

  // Then
  EXPECT_EQ(fake_output.str(), "Opponent's hand is Scissors\n");
}

TEST_F(CommandLineInterfaceTest, showScore__round4_player3_opponent1) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showScore(4, 3, 1);

  // Then
  EXPECT_EQ(fake_output.str(),
            "Round #4. You have 3 points. Your opponent has 1 point.\n");
}

TEST_F(CommandLineInterfaceTest, showScore__round3_player1_opponent2) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showScore(3, 1, 2);

  // Then
  EXPECT_EQ(fake_output.str(),
            "Round #3. You have 1 point. Your opponent has 2 points.\n");
}

TEST_F(CommandLineInterfaceTest, showGameResults__2vs1) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showGameResults(2, 1);

  // Then
  EXPECT_EQ(fake_output.str(),
            "Final results\n"
            "Your score is 2. Your opponent's score is 1.\n"
            "You WON.\n\n");
}

TEST_F(CommandLineInterfaceTest, showGameResults__1vs2) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showGameResults(1, 2);

  // Then
  EXPECT_EQ(fake_output.str(),
            "Final results\n"
            "Your score is 1. Your opponent's score is 2.\n"
            "You LOST.\n\n");
}

TEST_F(CommandLineInterfaceTest, showGameResults__2vs2) {
  // Given
  CommandLineInterface cli = create_SUT();

  // When
  cli.showGameResults(2, 2);

  // Then
  EXPECT_EQ(fake_output.str(),
            "Final results\n"
            "Your score is 2. Your opponent's score is 2.\n"
            "It's a TIE.\n\n");
}