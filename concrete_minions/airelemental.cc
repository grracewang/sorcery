#include "airelemental.h"

string AirElemental::getName() const { return "Air Elemental"; }
string AirElemental::getType() const { return "Minion"; }
string AirElemental::getDescription() const { return ""; }
int AirElemental::getCost() const { return 0; }

int AirElemental::getAtk() const { return 1; }
int AirElemental::getDef() const { return 1; }
int AirElemental::getBeginActions() const { return 1; }
int AirElemental::getActCost() const { return -1; }

void AirElemental::addAbility(Player* owner, Player* opponent) {};

vector<Spell*> AirElemental::getSpells() const {
    vector<Spell*> empty;
    return empty;
}
