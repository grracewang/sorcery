#ifndef NOVICEPYROMANCERABILITY_H
#define NOVICEPYROMANCERABILITY_H

#include "../spell.h"
#include "../concrete minions/changestat.h"

class NovicePyromancerAbility: public Spell {
    public:
        explicit NovicePyromancerAbility(): Spell{"ability", "Deal 1 damage to target minion", 1} {}
        void activate(Player *target, int t) {
            Minion* minion = target->getSummonedMinion(t);
            // if the top enchantment is +2/+2 or *2/*2 then we wrap another change stat that divides by 2
            minion = new ChangeStat{minion, "0", "-1", 0, 0, false, false};
        }
};

#endif