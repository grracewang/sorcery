#include "spell.h"

Spell::Spell(string name, string description, int cost) {
  this->name = name;
  this->type = "Spell";
  this->description = description;
  this->cost = cost;
}

card_template_t Spell::display() const {
  return display_spell(name, cost, description);
}

Spell::~Spell() {}
