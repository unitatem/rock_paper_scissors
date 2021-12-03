#ifndef GAMEINTERFACE_HPP_
#define GAMEINTERFACE_HPP_

class GameInterface {
 public:
  virtual ~GameInterface();

  virtual void welcome() const = 0;
  virtual unsigned getNumberOfRounds() const = 0;
};

#endif  // GAMEINTERFACE_HPP_