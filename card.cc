#include "card.h"
#include "player.h"

Card::Card(string name, string type, string filename, int cost) : 
    name{name}, type{type}, filename{filename}, cost{cost} {}

string getName() const { return name; }

string getType() const { return type; }

// string getDescription() const { return description; }

int getCost() const { return cost; }
