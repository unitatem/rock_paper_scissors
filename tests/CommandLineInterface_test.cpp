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

TEST_F(CommandLineInterfaceTest, getNumberOfRounds_positiveNumber) {
  // Given
  std::string user_input = "22";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getNumberOfRounds(), 22);
}

TEST_F(CommandLineInterfaceTest, getNumberOfRounds_negativeNumber) {
  // Given
  std::string user_input = "-47";
  CommandLineInterface cli = create_SUT_with(user_input);

  // When
  EXPECT_EQ(cli.getNumberOfRounds(), -47);
}
