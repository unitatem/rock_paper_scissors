#include "CommandLineInterface.hpp"

#include <iostream>

#include "Logger.hpp"

CommandLineInterface::CommandLineInterface(std::istream& is, std::ostream& os)
    : input_stream{is}, output_stream{os} {}

void CommandLineInterface::welcome() const {
  output_stream << "\n\nWelcome in Rock-Paper-Scissors Game\n\n\n";
  // TODO explain rules here
}

int CommandLineInterface::getNumberOfRounds() const {
  output_stream << "How many rounds would you like to play? ";

  int rounds;
  input_stream >> rounds;

  DEBUG("Number of rounds provided by user: " << rounds);
  return rounds;
}