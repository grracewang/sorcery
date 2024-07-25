#ifndef RAISEDEAD_H
#define RAISEDEAD_H

#include "../spell.h"
#include "../player.h"
#include "../concrete minions/changestat.h"
class RaiseDead: public Spell {
    public:
        RaiseDead(): Spell{"Raise Dead", "Resurrect the top minion in your graveyard and set its defence to 1", 1} {}
        bool activate(Player *owner, Player *enemy, int t) {
            Minion* target = owner->revive();
            if (target == nullptr || owner->getSummoned().size()) {
                cout << "You cannot use this card." << endl
                     << "Either there is nothing in the graveyard or you already summoned 5 minions." << endl;
                return false;
            }
            target = new ChangeStat{target, "", ChangeStat::toString('+', -target->getDef() + 1), 0, 0, false, false};
            owner->addToSummoned(target);
            return true;
        }
};
#endif
