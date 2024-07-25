#include "fireelemental.h"
#include "../ritual.h"
#include "../concrete rituals/fireelementalability.h"

 // normal getters (not changed by decorators)
string FireElemental::getName() const { return "Fire Elemental"; }
string FireElemental::getType() const { return "Minion"; }
string FireElemental::getDescription() const {
    return "Whenever an opponent’s minion enters play, deal 1 damage to it";
}
int FireElemental::getCost() const {return 2; }
bool FireElemental::isEnchantment() const { return false; }

// getters changed by decorators
int FireElemental::getAtk() const { return 2; }
int FireElemental::getDef() const { return 2; }
int FireElemental::getBeginActions() const { return 1; };
int FireElemental::getActCost() const { return -1; };

void FireElemental::addAbility(Player* owner, Player* opponent) {
    Ritual* r = new FireElementalAbility(owner, opponent);
    rituals.emplace_back(r);
    owner->attachMinionLeave(r);

} 

vector<Spell*> FireElemental::getSpells() const {
    vector<Spell*> empty;
    return empty;
}
