#ifndef APPRENTICESUMMONERABILITY_H
#define APPRENTICESUMMONERABILITY_H

#include "../spell.h"
#include "../concrete minions/airelemental.h"

class MasterSummonerAbility: public Spell {
    public:
        explicit MasterSummonerAbility(): Spell{"ability", "Deal 1 damage to target minion", 1} {}
        void activate(Player *target, int t) {
            for (int i = 0; i < 3; i++) {
                if (target->getSummoned().size() < 5) {
                    target->addToSummoned(new AirElemental());
                } else {
                    break;
                }
            }
            
        }
};

#endif