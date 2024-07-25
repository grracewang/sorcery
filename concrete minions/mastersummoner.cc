#include "mastersummoner.h"

string MasterSummoner::getName() const { return "Master Summoner"; }
string MasterSummoner::getType() const { return "Minion"; }
string MasterSummoner::getDescription() const { return "Summon up to three 1/1 air elementals"; }
int MasterSummoner::getCost() const { return 3; }
bool MasterSummoner::isEnchantment() const { return false; }

int MasterSummoner::getAtk() const { return 2; }
int MasterSummoner::getDef() const { return 3; }
int MasterSummoner::getBeginActions() const { return 1; }
int MasterSummoner::getActCost() const { return 2; }

void MasterSummoner::addAbility(Player* owner, Player *opponent) {}

// minion deletes the ritual when it dies or leaves the field

vector<Spell*> MasterSummoner::getSpells() const {
    vector<Spell*> empty;
    return empty;
}