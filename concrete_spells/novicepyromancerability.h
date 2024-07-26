#ifndef NOVICEPYROMANCERABILITY_H
#define NOVICEPYROMANCERABILITY_H
#include "../spell.h"
#include "../concrete_minions/changestat.h"
#include <string>

class NovicePyromancerAbility: public Spell {
    public:
        NovicePyromancerAbility(): Spell{"Novice Pyromancer Ability", "Deal 1 damage to target minion", 1} {}
        bool activate(Player *target, Player *other, size_t t) override {
            Minion *m = target->getSummonedMinion(t - 1);
            m = new ChangeStat{m, "", ChangeStat::toString('+', -1), 0, 0, false, nullptr};
            target->setSummoned(t - 1, m);
            return true;
        }
};

#endif
