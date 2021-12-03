#include "CommandLineInterface.hpp"

#include <iostream>

#include "Logger.hpp"

CommandLineInterface::CommandLineInterface(std::istream& is, std::ostream& os)
    : input_stream{is}, output_stream{os} {}

void CommandLineInterface::welcome() const {
  output_stream << "\n\nWelcome in Rock-Paper-Scissors Game\n\n\n";
  // TODO explain general rules here
}

int CommandLineInterface::getNumberOfRounds() const {
  output_stream << "How many rounds would you like to play? ";

  int rounds;
  input_stream >> rounds;

  DEBUG("Number of rounds provided by user: " << rounds);
  return rounds;
}

Element CommandLineInterface::getPlayerAction() const {
  output_stream << "Select your next action:\n"
                   "R (closed fist)                      => Rock\n"
                   "P (flat hand)                        => Paper\n"
                   "S (extended index and middle finger) => Scissors\n"
                   "What is your next move? ";
  char hand;
  input_stream >> hand;
  // TODO handle evil input

  switch (hand) {
    case 'R':
      return Element::Rock;
      break;
    case 'P':
      return Element::Paper;
      break;
    case 'S':
      return Element::Scissors;
      break;
  }

  // TODO handle evil input
  return Element::Paper;
}