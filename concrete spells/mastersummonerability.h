#ifndef APPRENTICESUMMONERABILITY_H
#define APPRENTICESUMMONERABILITY_H
#include "../spell.h"
#include "../concrete minions/airelemental.h"
#include <iostream>

class MasterSummonerAbility: public Spell {
    public:
        MasterSummonerAbility(): Spell{"Master Summoner Ability", "Summon up to three 1/1 air elementals", 1} {}
        bool activate(Player *owner, Player* enemy, int t) override {
            if (owner->getSummoned().size() >= 5) {
                std::cout << "You already have 5 minions summoned. You cannot summon more." << std::endl;
                return false;
            }
            for (int i = 0; i < 3; i++) {
                if (owner->getSummoned().size() < 5) {
                    owner->addToSummoned(new AirElemental());
                } else {
                    break;
                }
            }
            return true;
        }
};

#endif