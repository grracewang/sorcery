#ifndef APPRENTICESUMMONERABILITY_H
#define APPRENTICESUMMONERABILITY_H

#include "../spell.h"
#include "../concrete minions/airelemental.h"

class ApprenticeSummonerAbility: public Spell {
    public:
        explicit ApprenticeSummonerAbility(): Spell{"ability", "Deal 1 damage to target minion", 1} {}
        void activate(Player *target, int t) {
            if (target->getSummoned().size() < 5) {
                target->addToSummoned(new AirElemental());
            }
        }
};

#endif