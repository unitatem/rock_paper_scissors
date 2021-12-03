#ifndef COMMANDLINEINTERFACE_HPP_
#define COMMANDLINEINTERFACE_HPP_

#include <iostream>

#include "GameInterface.hpp"

class CommandLineInterface : public GameInterface {
 private:
  std::istream& input_stream;
  std::ostream& output_stream;

 public:
  CommandLineInterface(std::istream& is = std::cin,
                       std::ostream& os = std::cout);

  void welcome() const override;
  int getNumberOfRounds() const override;
  Element getPlayerAction() const override;
  void showOpponentHand(const Element& hand) const override;
  void showScore(int round, int player, int opponent) const override;
  void showGameResults(int player, int opponent) const override;
};

#endif  // COMMANDLINEINTERFACE_HPP_