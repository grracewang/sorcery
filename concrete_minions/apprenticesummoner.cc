#include "apprenticesummoner.h"
#include "../concrete_spells/apprenticesummonerability.h"

string ApprenticeSummoner::getName() const { return "Apprentice Summoner"; }
string ApprenticeSummoner::getType() const { return "Minion"; }
string ApprenticeSummoner::getDescription() const {
    if (getSpells().empty()) return "";
    else return getSpells()[0]->getDescription();
}
int ApprenticeSummoner::getCost() const { return 1; }

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
