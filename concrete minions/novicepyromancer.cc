#include "novicepyromancer.h"
#include "../concrete spells/novicepyromancerability.h"

string NovicePyromancer::getName() const { return "Novice Pyromancer"; }
string NovicePyromancer::getType() const { return "Minion"; }
string NovicePyromancer::getDescription() const { return "Deal 1 damage to target minion"; };
int NovicePyromancer::getCost() const { return 1; }
bool NovicePyromancer::isEnchantment() const { return false; }

int NovicePyromancer::getAtk() const { return 0; }
int NovicePyromancer::getDef() const { return 1; }
int NovicePyromancer::getBeginActions() const { return 1; }
int NovicePyromancer::getActCost() const {
    if (getSpells().empty()) return -1;
    else return getSpells()[0]->getCost();
}

void addAbility(Player* owner, Player *opponent) {}

vector<Spell*> NovicePyromancer::getSpells() const {
    vector<Spell*> s;
    s.emplace_back(new NovicePyromancerAbility());
    return s;
}

