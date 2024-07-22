#include "minion.h"
#include "player.h" // Include Player if needed in definitions
#include "card.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"

// Implement Minion methods here

Minion::Minion(string name, string type, string filename, int cost): 
    Card{name, "Minion", filename, cost}, actions{true} {}

bool Minion::getActions() const { return actions; }

void Minion::atkPlayer(Player*) {};

Minion *Minion::atkMinion(Minion*) {}

vector<Spell*> Minion::getSpells() const { return spells; }

vector<Ritual*> Minion::getRituals() const { return rituals; }
