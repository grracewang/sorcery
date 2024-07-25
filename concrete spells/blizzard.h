#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "../spell.h"
#include "../concrete minions/changestat.h"

class Blizzard: public Spell {
    public:
        explicit Blizzard(): Spell{"Blizzard", "Deal 2 damage to all minions", 3} {}
        void activate(Player *owner, Player *enemy) {
            for (auto minion: owner->getSummoned()) {
                minion = new ChangeStat{minion, "", "-2", 0, 0, false, false};
            } 
            for (auto minion: enemy->getSummoned()) {
                minion = new ChangeStat{minion, "", "-2", 0, 0, false, false};
            }
        }
};

#endif
