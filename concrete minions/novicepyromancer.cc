#include "novicepyromancer.h"

string NovicePyromancer::getName() const { return "Novice Pyromancer"; }
string NovicePyromancer::getType() const { return "Minion"; }
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
    vector<Spell*> empty;
    return empty;
}
// vector<Ritual*> NovicePyromancer::getRituals() const {
//     vector<Ritual*> empty;
//     return empty;
// }
