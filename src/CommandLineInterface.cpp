#include "CommandLineInterface.hpp"

#include <iostream>

void CommandLineInterface::welcome() const {
  std::cout << "\n\nWelcome in Rock-Paper-Scissors Game\n\n\n";
}

unsigned CommandLineInterface::getNumberOfRounds() const { return 0; }