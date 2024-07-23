#ifndef RAISEDEAD_H
#define RAISEDEAD_H

#include "../spell.h"
#include "player.h"

class RaiseDead: public Spell {
    public:
        explicit RaiseDead(): Spell{"Raise Dead", "raisedead.txt", 1} {}
        void activate(Player* owner) {
            Minion* target = owner->revive();
            target = new ChangeStat{target, '+', 0, -1 * target->getDef() + 1, 0};
            owner->addToSummoned(target);
        }
};
#endif
