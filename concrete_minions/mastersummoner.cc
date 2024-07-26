#include "mastersummoner.h"
#include "../concrete_spells/mastersummonerability.h"

string MasterSummoner::getName() const { return "Master Summoner"; }
string MasterSummoner::getType() const { return "Minion"; }
string MasterSummoner::getDescription() const { return "Summon up to three 1/1 air elementals"; }
int MasterSummoner::getCost() const { return 3; }

int MasterSummoner::getAtk() const { return 2; }
int MasterSummoner::getDef() const { return 3; }
int MasterSummoner::getBeginActions() const { return 1; }
int MasterSummoner::getActCost() const { 
    if (getSpells().empty()) return -1;
    else return getSpells()[0]->getCost();
}

void MasterSummoner::addAbility(Player* owner, Player *opponent) {}

vector<Spell*> MasterSummoner::getSpells() const {
    vector<Spell*> s;
    s.emplace_back(new MasterSummonerAbility());
    return s;
}