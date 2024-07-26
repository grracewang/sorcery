#include "potionseller.h"
#include "../ritual.h"
#include "../concrete_rituals/potionsellerability.h"

string PotionSeller::getName() const { return "Potion Seller"; }
string PotionSeller::getType() const { return "Minion"; }
string PotionSeller::getDescription() const {
    return "At the end of your turn, all your minions gain +0/+1.";
}
int PotionSeller::getCost() const { return 2; }

int PotionSeller::getAtk() const { return 1; }
int PotionSeller::getDef() const { return 3; }
int PotionSeller::getBeginActions() const { return 1; }
int PotionSeller::getActCost() const { return -1; }

void PotionSeller::addAbility(Player* owner, Player *opponent) {
    Ritual* r = new PotionSellerAbility(owner);
    rituals.emplace_back(r);
    owner->attachAfterTurn(r);

};

vector<Spell*> PotionSeller::getSpells() const {
    vector<Spell*> empty;
    return empty;
}

