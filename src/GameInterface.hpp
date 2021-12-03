#ifndef GAMEINTERFACE_HPP_
#define GAMEINTERFACE_HPP_

#include "Element.hpp"

class GameInterface {
 public:
  virtual ~GameInterface();

  virtual void welcome() const = 0;
  virtual int getNumberOfRounds() const = 0;

  virtual Element getPlayerAction() const = 0;
};

#endif  // GAMEINTERFACE_HPP_