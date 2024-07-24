#include "minion.h"

Minion* Minion::removeEnchantments() {
  // use removeTopEnchantment to get rid of enchantments
}
Minion* Minion::removeTopEnchantment() {
  // check if you have an enchantment and remove if it is
}

// for printing
card_template_t Minion::display() const {
  if (getSpells().empty() && getRituals().empty()) {
    return display_minion_no_ability(getName(), getCost(), getAtk(), getDef());
  } else if (!getSpells().empty()) {
    return display_minion_activated_ability(getName(), getCost(), getAtk(), getDef(),
        getSpells()[0]->getCost(), getSpells()[0]->getDescription());
  } else {
    return display_minion_triggered_ability(getName(), getCost(), getAtk(),
        getDef(), getRituals()[0]->getDescription());
  }
}

Minion::~Minion() {}
