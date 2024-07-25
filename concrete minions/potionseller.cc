#include "potionseller.h"

string PotionSeller::getName() const { return "Potion Seller"; }
string PotionSeller::getType() const { return "Minion"; }
int PotionSeller::getCost() const { return 2; }
bool PotionSeller::isEnchantment() const { return false; }

int PotionSeller::getAtk() const { return 1; }
int PotionSeller::getDef() const { return 3; }
int PotionSeller::getBeginActions() const { return 1; }
int PotionSeller::getActCost() const { return -1; }

void PotionSeller::addAbility(Player* owner, Player *oponent) {};

vector<Spell*> PotionSeller::getSpells() const {
    vector<Spell*> empty;
    return empty;
}
// vector<Ritual*> PotionSeller::getRituals() const {
//     vector<Ritual*> empty;
//     return empty;
// }
