#include "airelemental.h"
#include "changestat.h"
using namespace std;

string AirElemental::getName() const { return "Air Elemental"; }
string AirElemental::getType() const { return "Minion"; }
string AirElemental::getDescription() const { return ""; }
int AirElemental::getCost() const { return 0; }
int AirElemental::getAction() const { return actions; }

int AirElemental::getAtk() const { return 1; }
int AirElemental::getDef() const { return 1; }
int AirElemental::getBeginActions() const { return 1; }
int AirElemental::getActCost() const {}
vector<Spell*> AirElemental::getSpells() const {
    vector<Spell*> empty;
    return empty;
}
vector<Ritual*> AirElemental::getRituals() const {
    vector<Ritual*> empty;
    return empty;
}

void AirElemental::resetAction() {
    actions = getBeginActions();
}
bool AirElemental::useAction() {
    actions--;
    return actions >= 0;
}
