#ifndef GAMEINTERFACE_MOCK_HPP_
#define GAMEINTERFACE_MOCK_HPP_

#include "gmock/gmock.h"
#include "interface/GameInterface.hpp"

class GameInterfaceMock : public GameInterface {
 public:
  MOCK_METHOD(void, welcome, (), (const, override));
  MOCK_METHOD(int, getNumberOfRounds, (), (const, override));
  MOCK_METHOD(Element, getPlayerAction, (), (const, override));
  MOCK_METHOD(void, showOpponentHand, (const Element& hand), (const, override));
  MOCK_METHOD(void, showScore, (int round, int player, int opponent),
              (const, override));
  MOCK_METHOD(void, showGameResults, (int player, int opponent),
              (const, override));
};

#endif  // GAMEINTERFACE_MOCK_HPP_