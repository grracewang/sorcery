#include "minion.h"
// #include "changestat.h"
#include "player.h" // Include Player if needed in definitions
#include "card.h"
#include "spell.h"
#include "ritual.h"
#include "enchantment.h"

// Implement Minion methods here

Minion::Minion(string name, string type, string description, int cost): 
    Card{name, "Minion", description, cost}, actions{true} {}

Minion::~Minion() {}

bool Minion::getActions() const { return actions; }

void Minion::setActions(bool b) { actions = b; }

void Minion::atkPlayer(Player* target) {
    target->changeLife(0 - this->getAtk());
}

Minion *Minion::atkMinion(Minion* target) {
    // target = new ChangeStat(target, "+", 0, 0 - this->getAtk());
}

string Minion::getDescription() const { return description; }

vector<Spell*> Minion::getSpells() const { return spells; }

vector<Ritual*> Minion::getRituals() const { return rituals; }

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
