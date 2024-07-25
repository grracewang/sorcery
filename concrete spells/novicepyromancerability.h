#ifndef NOVICEPYROMANCERABILITY_H
#define NOVICEPYROMANCERABILITY_H

#include "../spell.h"
#include "../concrete minions/changestat.h"

class NovicePyromancerAbility: public Spell {
    public:
        NovicePyromancerAbility(): Spell{"Novice Pyromancer Ability", "Deal 1 damage to target minion", 1} {}
        bool activate(Player *owner, Player *enemy, int t) override {
            int size = enemy->getSummoned().size();
            Minion* m = enemy->removeSummonedMinion(t - 1);
            // if the top enchantment is +2/+2 or *2/*2 then we wrap another change stat that divides by 2
            m = new ChangeStat{m, "0", "-1", 0, 0, false, false};
            enemy->addToSummoned(m); // added at index size - 1
            for (int i = t - 1; i < size; i++) {
                Minion* n = enemy->removeSummonedMinion(i);
                enemy->addToSummoned(n); 
                // removes and adds minions that were previously AFTER target minion
                // this is so that the summoned minions return back to their original order
            }
            return true;
        }
};

#endif