#ifndef RAISEDEAD_H
#define RAISEDEAD_H

#include "../spell.h"
#include "player.h"
#include "../concrete minions/changestat.h"
class RaiseDead: public Spell {
    public:
        RaiseDead(): Spell{"Raise Dead", "Resurrect the top minion in your graveyard and set its defence to 1", 1} {}
        void activate(Player* owner) {
            Minion* target = owner->revive();
            if (target->getDef() <= 0) {
                target = new ChangeStat{target, "", ChangeStat::toString('+', -1 * target->getDef() + 1), 0, 0, false, false};
            } else {
                target = new ChangeStat{target, "", ChangeStat::toString('+', 1 * target->getDef() + 1), 0, 0, false, false};
            }
            owner->addToSummoned(target);
        }
};
#endif
