#ifndef RAISEDEAD_H
#define RAISEDEAD_H

#include "../spell.h"
#include "player.h"

class RaiseDead: public Spell {
    public:
        explicit RaiseDead(): Spell{"Raise Dead", "raisedead.txt", 1} {}
        void activate(Player* owner) {
            owner->getGraveyard();
            owner->getHand();

        }
};

#endif