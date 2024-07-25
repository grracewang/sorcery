#ifndef APPRENTICESUMMONERABILITY_H
#define APPRENTICESUMMONERABILITY_H

#include "../spell.h"
#include "../concrete minions/airelemental.h"
#include <iostream>

class ApprenticeSummonerAbility: public Spell {
    public:
        ApprenticeSummonerAbility(): Spell{"Ability", "Summon a 1/1 Air Elemental", 1} {}
        bool activate(Player *target, Player* enemy, int t) {
            if (target->getSummoned().size() >= 5) {
                std::cout << "Cannot use ability." << std::endl;
                return false;
            }
            target->addToSummoned(new AirElemental());
            return true;
        }
};

#endif