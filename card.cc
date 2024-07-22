#include "card.h"

Card::Card(string name, string type, string filename, int cost) : 
    name{name}, type{type}, filename{filename}, cost{cost} {}

string Card::getName() const { return name; }

string Card::getType() const { return type; }

// string getDescription() const { return description; }

int Card::getCost() const { return cost; }
