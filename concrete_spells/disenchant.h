#ifndef DISENCHANT_H
#define DISENCHANT_H
#include "../spell.h"
#include "../concrete_minions/changestat.h"
#include <string>

class Disenchant: public Spell {
    public:
        Disenchant(): Spell{"Disenchant", "Destroy the top enchantment on target minion", 1} {}
        bool activate(Player *target, Player *other, size_t t) override {
            t -= 49;
            if (target->getSummoned().size() <= t) {
                cout << "Unable to use ability" << endl;
                return false;
            }
            Minion* minion = target->getSummonedMinion(t);
            minion = Minion::removeTopEnchantment(minion);
            target->setSummoned(t, minion);
            return true;
        }
};

#endif
