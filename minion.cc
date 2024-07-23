#include "minion.h"
#include "changestat.h"

// Implement Minion methods here

Minion::Minion(string name, string type, string description, int cost): 
  Card{name, "Minion", description, cost} {}

bool Minion::getActions() const { return actions; }

void Minion::setActions(bool b) { actions = b; }

string Minion::getDescription() const { return description; }

vector<Spell*> Minion::getSpells() const { return spells; }

vector<Ritual*> Minion::getRituals() const { return rituals; }

vector<Enchantment*> Minion::getEnchantments() const { return enchantments; }

Enchantment* Minion::getEnchantment(int i) {
  return enchantments[i];
}

Enchantment* Minion::removeEnchantment(int i) {
  Enchantment* enchantment = enchantments[i];
  enchantments.erase(enchantments.begin() + i);
  return enchantment;
}

card_template_t Minion::display() const {
  if (spells.empty() && rituals.empty()) {
    return display_minion_no_ability(name, cost, getAtk(), getDef());
  } else if (!spells.empty()) {
    return display_minion_activated_ability(name, cost, getAtk(), getDef(),
        spells[0]->getCost(), spells[0]->getDescription());
  } else {
    return display_minion_triggered_ability(name, cost, getAtk(),
        getDef(), rituals[0]->getDescription());
  }
}
