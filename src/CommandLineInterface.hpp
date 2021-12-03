#ifndef COMMANDLINEINTERFACE_HPP_
#define COMMANDLINEINTERFACE_HPP_

#include "GameInterface.hpp"

class CommandLineInterface : public GameInterface {
 public:
  void welcome() const override;
  unsigned getNumberOfRounds() const override;
};

#endif  // COMMANDLINEINTERFACE_HPP_