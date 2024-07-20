#include "minion.h"

Minion::Minion(int atk, int def): Card{}, atk{atk}, def{def} {}

int Minion::getAtk() { return atk; }

int Minion::getDef() { return def; }

bool Minion::getActions() { return actions; }

void atkPlayer(Player*) {};

Minion *atkMinion(Minion*);
