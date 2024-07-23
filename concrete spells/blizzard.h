#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "../spell.h"

class Blizzard: public Spell {
    public:
        explicit Blizzard(): Spell{"Blizzard", "blizzard.txt", 3} {}
        void activate(Player* owner, Player* target) {
            for (auto minion: owner->getMinions()) {
                minion = new ChangeStat{dynamic_cast<Minion*>(minion), '+', 0, -2, 0};
            } 
            for (auto minion: target->getMinions()) {
                minion = new ChangeStat{dynamic_cast<Minion*>(minion), '+', 0, -2, 0};
            }
        }
};

#endif