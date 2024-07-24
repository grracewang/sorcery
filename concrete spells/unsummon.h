#ifndef UNSUMMON_H
#define UNSUMMON_H

#include "../spell.h"

class Unsummon: public Spell {
    public:
        explicit Unsummon(): Spell{"Unsummon", "Return target minion to its owner’s hand", 1} {}
        void activate(Player *owner, int t) {
            Card* target = owner->removeSummonedMinion(t);
            // what if hand is full
            owner->addToHand(target);
        }
};

#endif