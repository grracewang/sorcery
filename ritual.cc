#include "ritual.h"

Ritual::Ritual(string name, string filename, int cost, int charges,
               int activationCost, Player* owner):
    charges{charges}, activationCost{activationCost} {
  this->name = name;
  this->type = "Ritual";
  this->description = description;
  this->cost = cost;
}

Ritual::~Ritual() { delete owner; }

int Ritual::getCharges() const { return charges; }

int Ritual::getActivationCost() const { return activationCost; }

// for printing
card_template_t Ritual::display() const {
  return display_ritual(name, cost, activationCost, description, charges);
}
