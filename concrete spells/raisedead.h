#ifndef RAISEDEAD_H
#define RAISEDEAD_H

#include "../spell.h"
#include "player.h"
#include <sstream>
#include <iostream>
#include "string.h"
class RaiseDead: public Spell {
    public:
        explicit RaiseDead(): Spell{"Raise Dead", "Resurrect the top minion in your graveyard and set its defence to 1", 1} {}
        void activate(Player* owner) {
            Minion* target = owner->revive();
            int i = -1 * target->getDef() + 1;
            std::istringstream iss(i);
            std::string str;
            iss >> str;
            target = new ChangeStat{target, "", str, 0, 0, false, false};
            owner->addToSummoned(target);
        }
};
#endif
