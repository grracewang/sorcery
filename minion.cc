#include "minion.h"
#include "./concrete minions/changestat.h"

string Minion::getDescription() const {
    if (getSpells().empty()) return "";
    else return getSpells()[0]->getDescription();
}

int Minion::getAction() const { return actions; }

int Minion::getCost() const { return 0; }

Minion *Minion::getMinion() const { return nullptr; }

void Minion::setMinion(Minion *m) {}

vector<Card*> Minion::getEnchantments() const {
  vector<Card*> empty;
  return empty;
}


// for attacking minions
Minion *Minion::attack(Minion *enemy) {
  return new ChangeStat{enemy, "", ChangeStat::toString('+', -getAtk()),
    0, 0, false, nullptr};
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

// added static functions
Minion *Minion::removeTopEnchantment(Minion *m) {
    if (m == nullptr) return m; // return nullptr right away if m is nullptr

    // m is an enchantment ChangeStat (base case)
    if (m->isEnchantment()) {
        Minion *temp = m;
        m = temp->getMinion();
        temp->setMinion(nullptr);
        delete temp;
        return m;
    }
    Minion *newMinion = m; // outermost pointer to return

    Minion *prev = newMinion; // not enchantment guaranteed
    Minion *curr = prev->getMinion();
    while (curr) {
        if (curr->isEnchantment()) {
            prev->setMinion(curr->getMinion());
            curr->setMinion(nullptr);
            delete curr;
            return newMinion;
        }

        prev = curr;
        curr = prev->getMinion();
    }
    
    return newMinion;
}

Minion *Minion::removeEnchantments(Minion *m) {
    if (m == nullptr) return m; // return nullptr right away if m is nullptr
    
    // remove until not ench. ChangeStat
    while (true) {
        if (m->isEnchantment()) {
            Minion *temp = m;
            m = temp->getMinion();
            temp->setMinion(nullptr);
            delete temp;
        } else {
            break;
        }
    }    
    Minion *newMinion = m; // outermost pointer to return (not ench)

    Minion *prev = newMinion; // not enchantment guaranteed
    Minion *curr = prev->getMinion();
    while (curr) {
        if (curr->isEnchantment()) {
            prev->setMinion(curr->getMinion());
            curr->setMinion(nullptr);
            delete curr;
            curr = prev->getMinion();
        } else {
            prev = curr;
            curr = prev->getMinion();
        }
    }
    
    return newMinion;
}

// add ability 
void Minion::removeAbilities() {
  for (int i = 0; i < rituals.size(); i++) {
    Ritual* r = rituals[0];
    rituals.erase(rituals.begin());
    delete r;
  }
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
