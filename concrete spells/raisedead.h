#ifndef RAISEDEAD_H
#define RAISEDEAD_H

#include "../spell.h"
#include "player.h"

class RaiseDead: public Spell {
    public:
        explicit RaiseDead(): Spell{"Raise Dead", "raisedead.txt", 1} {}
        void activate(Player* owner) {
            Minion* revived = owner->getGraveyard();
            revived = new ChangeStat{revived, '+', 0, -1 * revived->getDef() + 1, 0};
            owner->addToSummoned(revived);
        }
};

#endif