#include "earthelemental.h"

string EarthElemental::getName() const { return "Earth Elemental"; }
string EarthElemental::getType() const { return "Minion"; }
string EarthElemental::getDescription() const { return ""; }
int EarthElemental::getCost() const { return 3; }

int EarthElemental::getAtk() const { return 4; }
int EarthElemental::getDef() const { return 4; }
int EarthElemental::getBeginActions() const { return 1; }
int EarthElemental::getActCost() const { return -1; }

vector<Spell*> EarthElemental::getSpells() const {
    vector<Spell*> empty;
    return empty;
}

void EarthElemental::addAbility(Player* owner, Player *opponent) {}

