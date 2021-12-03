#ifndef DEFAULTRULES_HPP_
#define DEFAULTRULES_HPP_

#include "Rules.hpp"

class DefaultRules : public Rules {
 public:
  PlayOutcome play(const Element& player, const Element& other) const override;
};

#endif  // DEFAULTRULES_HPP_
