#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "../spell.h"
#include "../concrete minions/changestat.h"

class Blizzard: public Spell {
    public:
        Blizzard(): Spell{"Blizzard", "Deal 2 damage to all minions", 3} {}
        bool activate(Player *owner, Player *enemy, int t) {
            int ownerSize = owner->getSummoned().size();
            int enemySize = enemy->getSummoned().size();
            for (int i = 0; i < ownerSize; i++) { // removes each minion, mutates it and adds it back
                Minion* m = owner->removeSummonedMinion(0);
                m = new ChangeStat{m, "", "-2", 0, 0, false, false};
                owner->addToSummoned(m);
            }
            for (int i = 0; i < enemySize; i++) {
                Minion* m = enemy->removeSummonedMinion(0);
                m = new ChangeStat{m, "", "-2", 0, 0, false, false};
                enemy->addToSummoned(m);
            }
            return true;
        }
};

#endif
