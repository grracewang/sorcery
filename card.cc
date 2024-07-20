#include "card.h"

Card::Card(string name, string type, string description, int cost) : 
    name{name}, type{type}, description{description}, cost{cost} {}

string getName() const { return name; }

string getType() const { return type; }

string getDescription() const { return description; }

int getCost() const { return cost; }
