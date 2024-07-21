#include "ritual.h"

explicit Ritual::Ritual(string name, string filename, int cost, int charges, int activationCost, Player *owner):
    Card{name, "Ritual", filename, cost}, charges{charges}, activationCost{activationCost} {}

Ritual::~Ritual() { delete owner; }

int Ritual::getCharges() const { return charges; }

int Ritual::getActivationCost() const { return activationCost; }