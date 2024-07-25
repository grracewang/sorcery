#include "apprenticesummoner.h"
#include "../concrete spells/apprenticesummonerability.h"

string ApprenticeSummoner::getName() const { return "Apprentice Summoner"; }
string ApprenticeSummoner::getType() const { return "Minion"; }
int ApprenticeSummoner::getCost() const { return 1; }

int ApprenticeSummoner::getAtk() const { return 1; }
int ApprenticeSummoner::getDef() const { return 1; }
int ApprenticeSummoner::getBeginActions() const { return 1; }
int ApprenticeSummoner::getActCost() const { return -1; }
vector<Spell*> ApprenticeSummoner::getSpells() const {
    vector<Spell*> s;
    s.emplace_back(new ApprenticeSummonerAbility());
    return s;
}
vector<Ritual*> ApprenticeSummoner::getRituals() const {
    vector<Ritual*> empty;
    return empty;
}
