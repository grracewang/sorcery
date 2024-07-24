#include "card.h"

Card::~Card() {}

string Card::getName() const { return name; }

string Card::getType() const { return type; }

string Card::getDescription() const { return description; }

int Card::getCost() const { return cost; }
