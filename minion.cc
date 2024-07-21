#include "minion.h"

Minion::Minion(string name, string type, string filename, int cost, int atk, int def): 
    Card{name, "Minion", filename, cost}, actions{true}, atk{atk}, def{def} {}

int Minion::getAtk() const { return atk; }

int Minion::getDef() const { return def; }

bool Minion::getActions() const { return actions; }

void Minion::atkPlayer(Player*) {};

Minion *Minion::atkMinion(Minion*) {}

vector<Spell*> Minion::getSpells() const { return spells; }

vector<Ritual*> Minion::getRituals() const { return rituals; }
