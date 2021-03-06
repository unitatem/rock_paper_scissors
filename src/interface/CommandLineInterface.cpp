#include "CommandLineInterface.hpp"

#include <iostream>
#include <unordered_map>

#include "Logger.hpp"

CommandLineInterface::CommandLineInterface(std::istream& is, std::ostream& os)
    : input_stream{is}, output_stream{os} {}

void CommandLineInterface::welcome() const {
  output_stream << "\n\nWelcome in Rock-Paper-Scissors Game\n\n"
                << "Actions possible in the game:\n"
                   "R (closed fist)                      => Rock\n"
                   "P (flat hand)                        => Paper\n"
                   "S (extended index and middle finger) => Scissors\n"
                << "\n";
}

int CommandLineInterface::getNumberOfRounds() const {
  do {
    output_stream << "How many rounds would you like to play? ";

    int rounds;
    input_stream >> rounds;

    DEBUG("Number of rounds provided by user: " << rounds);
    if (rounds > 0) return rounds;

    output_stream << "Invalid number.\n";
  } while (true);
}

Element CommandLineInterface::getPlayerAction() const {
  do {
    output_stream << "What is your next move? ";
    char hand;
    input_stream >> hand;

    switch (hand) {
      case 'R':
        return Element::Rock;
      case 'P':
        return Element::Paper;
      case 'S':
        return Element::Scissors;
    }

    output_stream << "Invalid action. Please only use action specified at the "
                     "begging of the game.\n";
  } while (true);
}

void CommandLineInterface::showOpponentHand(const Element& hand) const {
  static std::unordered_map<Element, std::string> hand2name = {
      {Element::Rock, "Rock"},
      {Element::Paper, "Paper"},
      {Element::Scissors, "Scissors"}};
  output_stream << "Opponent's hand is " << hand2name[hand] << "\n";
}

void CommandLineInterface::showScore(int round, int player,
                                     int opponent) const {
  output_stream << "Round #" << round << ". You have " << player << " point";
  if (player > 1) output_stream << "s";
  output_stream << ". Your opponent has " << opponent << " point";
  if (opponent > 1) output_stream << "s";
  output_stream << ".\n\n";
}

void CommandLineInterface::showGameResults(int player, int opponent) const {
  output_stream << "Final results\n"
                   "Your score is "
                << player << ". Your opponent's score is " << opponent << ".\n";

  if (player > opponent)
    output_stream << "You WON.\n\n";
  else if (player < opponent)
    output_stream << "You LOST.\n\n";
  else
    output_stream << "It's a TIE.\n\n";
}