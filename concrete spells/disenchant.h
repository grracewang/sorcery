#ifndef DISENCHANT_H
#define DISENCHANT_H

#include "../spell.h"
#include "../concrete minions/changestat.h"

class Disenchant: public Spell {
    public:
        Disenchant(): Spell{"Disenchant", "Destroy the top enchantment on target minion", 1} {}
        bool activate(Player *owner, Player *enemy, int t) {
            Minion* minion = target->getSummonedMinion(t);
            // if the top enchantment is +2/+2 or *2/*2 then we wrap another change stat that divides by 2
            // Enchantment* removed = minion->removeEnchantment(minion->getEnchantments().size());
            // if (removed->getName() == "Giant Strength") {
            //     minion = new ChangeStat{minion, "-2", "-2", 0, 0, false, false};
            // } else if (removed->getName() == "Enrage") {
            //     minion = new ChangeStat{minion, '*', 0.5, 0.5, 0};
            // } else if (removed->getName() == "Magic Fatigue") {
            //     minion = new ChangeStat{minion, '+', 0, 0, -2};
            // }
            return true;
        }
};

#endif