#ifndef FIREELEMENTALABILITY_H
#define FIREELEMENTALABILITY_H

#include "../ritual.h"
#include "../minion.h"
#include "../concrete minions/changestat.h"

class FireElementalAbility: public Ritual {
    Player *opponent;
    public:
        explicit FireElementalAbility(Player* owner, Player *opponent):
            Ritual{"Fire Elemental Ability", "Whenever an opponent's minion enters play, deal 1 damage to it", 0, 1, 0, owner},
            opponent{opponent} {}
        
        ~FireElementalAbility() { 
            owner->detachMinionEnter(this); 
            opponent->detachMinionEnter(this);
        }

        void notify() override { 
            if (!owner->isPlaying()) {
                int i = owner->getSummoned().size() - 1;
                Minion *m = owner->getSummoned().at(i);
                m = new ChangeStat{m, '+', 0, -1};
            }
        }
};

#endif