#include "DefaultRules.hpp"

#include <functional>
#include <unordered_map>
#include <utility>

PlayOutcome DefaultRules::play(const Element& player,
                               const Element& other) const {
  struct ElementPairHash {
    size_t operator()(const std::pair<Element, Element>& elements) const {
      size_t first_hash = std::hash<Element>()(elements.first);
      size_t second_hash = std::hash<Element>()(elements.second) << 1;
      return first_hash ^ second_hash;
    }
  };
  static std::unordered_map<std::pair<Element, Element>, PlayOutcome,
                            ElementPairHash>
      hands2result = {
          {{Element::Rock, Element::Rock}, PlayOutcome::TIE},
          {{Element::Rock, Element::Paper}, PlayOutcome::LOSS},
          {{Element::Rock, Element::Scissors}, PlayOutcome::WIN},

          {{Element::Paper, Element::Rock}, PlayOutcome::WIN},
          {{Element::Paper, Element::Paper}, PlayOutcome::TIE},
          {{Element::Paper, Element::Scissors}, PlayOutcome::LOSS},

          {{Element::Scissors, Element::Rock}, PlayOutcome::LOSS},
          {{Element::Scissors, Element::Paper}, PlayOutcome::WIN},
          {{Element::Scissors, Element::Scissors}, PlayOutcome::TIE}};

  return hands2result.at({player, other});
}
