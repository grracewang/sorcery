#include "apprenticesummoner.h"
#include "../concrete spells/apprenticesummonerability.h"

string ApprenticeSummoner::getName() const { return "Apprentice Summoner"; }
string ApprenticeSummoner::getType() const { return "Minion"; }
string ApprenticeSummoner::getDescription() const { return "Summon a 1/1 air elemental"; }
int ApprenticeSummoner::getCost() const { return 1; }
bool ApprenticeSummoner::isEnchantment() const { return false; }

int ApprenticeSummoner::getAtk() const { return 1; }
int ApprenticeSummoner::getDef() const { return 1; }
int ApprenticeSummoner::getBeginActions() const { return 1; }
int ApprenticeSummoner::getActCost() const {
    if (getSpells().empty()) return -1;
    else return getSpells()[0]->getCost();
}

vector<Spell*> ApprenticeSummoner::getSpells() const {
    vector<Spell*> s;
    s.emplace_back(new ApprenticeSummonerAbility());
    return s;
}

void ApprenticeSummoner::addAbility(Player* owner, Player* opponent) {}

// vector<Ritual*> ApprenticeSummoner::getRituals() const {
//     vector<Ritual*> empty;
//     return empty;
// }
