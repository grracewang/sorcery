#include "airelemental.h"

string AirElemental::getName() const { return "Air Elemental"; }
string AirElemental::getType() const { return "Minion"; }
int AirElemental::getCost() const { return 0; }
bool AirElemental::isEnchantment() const { return false; }

int AirElemental::getAtk() const { return 1; }
int AirElemental::getDef() const { return 1; }
int AirElemental::getBeginActions() const { return 1; }
int AirElemental::getActCost() const { return -1; }
vector<Spell*> AirElemental::getSpells() const {
    vector<Spell*> empty;
    return empty;
}
vector<Ritual*> AirElemental::getRituals() const {
    vector<Ritual*> empty;
    return empty;
}
