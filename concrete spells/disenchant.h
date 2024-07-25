#ifndef DISENCHANT_H
#define DISENCHANT_H

#include "../spell.h"
#include "../concrete minions/changestat.h"

class Disenchant: public Spell {
    public:
        Disenchant(): Spell{"Disenchant", "Destroy the top enchantment on target minion", 1} {}
        bool activate(Player *target, Player *other, int t) override {
            Minion* minion = target->getSummonedMinion(t);
            minion = Minion::removeTopEnchantment(minion);
            target->replaceMinion(t, minion);
            return true;
        }
};

#endif