#include "minion.h"

Minion::Minion(string name, string type, string filename, int cost, int atk, int def): 
    Card{name, "Minion", filename, cost}, actions{true}, atk{atk}, def{def} {}

int Minion::getAtk() { return atk; }

int Minion::getDef() { return def; }

bool Minion::getActions() { return actions; }

void atkPlayer(Player*) {};

Minion *atkMinion(Minion*);
