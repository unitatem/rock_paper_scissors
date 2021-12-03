#include "../src/CommandLineInterface.hpp"

#include <sstream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

class CommandLineInterfaceTest : public ::testing::Test {
 protected:
  std::istringstream fake_input;
  std::ostringstream fake_output;

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
  std::string user_input = "F";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getPlayerAction(), Element::Rock);
}

TEST_F(CommandLineInterfaceTest, getPlayerAction__map_open_hand_to_paper) {
  // Given
  std::string user_input = "H";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getPlayerAction(), Element::Paper);
}

TEST_F(CommandLineInterfaceTest, getPlayerAction__map_two_fingers_to_scissors) {
  // Given
  std::string user_input = "V";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getPlayerAction(), Element::Scissors);
}
