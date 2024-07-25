#ifndef APPRENTICESUMMONERABILITY_H
#define APPRENTICESUMMONERABILITY_H

#include "../spell.h"
#include "../player.h"
#include "../concrete minions/airelemental.h"
#include <iostream>
#include <string>

class ApprenticeSummonerAbility: public Spell {
    public:
        ApprenticeSummonerAbility(): Spell{"Apprentice Summoner Ability", "Summon a 1/1 Air Elemental", 1} {}
        bool activate(Player *owner, Player* enemy, size_t t) override {
            if (owner->getSummoned().size() >= 5) {
                std::cout << "Cannot use ability." << std::endl;
                return false;
            }
            owner->addToSummoned(new AirElemental(), enemy);
            return true;
        }
};

#endif