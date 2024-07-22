#include "spell.h"

explicit Spell::Spell(string name, string description, int cost):
    Card{name, "Spell", description, cost} {}

card_template_t Spell::display() const {
  return display_spell(name, cost, description);
}
