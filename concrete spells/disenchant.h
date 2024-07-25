#ifndef DISENCHANT_H
#define DISENCHANT_H

#include "../spell.h"
#include "../concrete minions/changestat.h"

class Disenchant: public Spell {
    public:
        Disenchant(): Spell{"Disenchant", "Destroy the top enchantment on target minion", 1} {}
        bool activate(Player *target, Player *other, size_t t) override {
            Minion* minion = target->getSummonedMinion(t - 1);
            minion = Minion::removeTopEnchantment(minion);
            target->setSummoned(t - 1, minion);
            return true;
        }
};

#endif