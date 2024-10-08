#include "ritual.h"

Ritual::Ritual(string name, string description, int cost, int charges,
               int activationCost, Player* owner):
    charges{charges}, activationCost{activationCost}, owner{owner} {
  this->name = name;
  this->type = "Ritual";
  this->description = description;
  this->cost = cost;
}

Ritual::~Ritual() {}

int Ritual::getCharges() const { return charges; }

int Ritual::getActivationCost() const { return activationCost; }

void Ritual::changeCharges(int i) { charges += i; }

// for printing
card_template_t Ritual::display() const {
  return display_ritual(name, cost, activationCost, description, charges);
}
