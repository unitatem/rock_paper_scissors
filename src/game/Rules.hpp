#ifndef RULES_HPP_
#define RULES_HPP_

#include "Element.hpp"

enum class PlayOutcome { WIN, LOSS, TIE };

class Rules {
 public:
  virtual ~Rules();

  virtual PlayOutcome play(const Element& player,
                           const Element& other) const = 0;
};

#endif  // RULES_HPP_
