#include "minion.h"
#include "./concrete minions/changestat.h"

string Minion::getDescription() const {
    if (getSpells().empty()) return "";
    else return getSpells()[0]->getDescription();
}

int Minion::getAction() const { return actions; }

int Minion::getCost() const { return 0; }

Minion *Minion::getMinion() const { return nullptr; }

void Minion::setMinion(const Minion *m) {}

Minion *Minion::removeEnchantments() {
  // use removeTopEnchantment to get rid of enchantments
}

Minion *Minion::removeTopEnchantment() { return this; }



// for attacking minions
Minion *Minion::attack(Minion *enemy) {
  return new ChangeStat{enemy, "", ChangeStat::toString('+', -getAtk()),
    0, 0, false, false};
}

void Minion::attack(Player *enemy) {
  enemy->changeLife(-getAtk());
}


void Minion::resetAction() {
  actions = getBeginActions();
}
bool Minion::useAction() {
  actions--;
  return actions >= 0;
}

// for printing
card_template_t Minion::display() const {
  if (getDescription() == "") {
    return display_minion_no_ability(getName(), getCost(), getAtk(), getDef());
  } else if (!getSpells().empty()) {
    return display_minion_activated_ability(getName(), getCost(), getAtk(), getDef(),
        getActCost(), getDescription());
  } else {
    return display_minion_triggered_ability(getName(), getCost(), getAtk(),
        getDef(), getDescription());
  }
}

Minion::~Minion() {}
