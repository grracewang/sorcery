#ifndef FIREELEMENTALABILITY_H
#define FIREELEMENTALABILITY_H

#include "../ritual.h"
#include "../minion.h"
#include "../concrete minions/changestat.h"

class FireElementalAbility: public Ritual {
    Player *opponent;
    public:
        explicit FireElementalAbility(Player* owner, Player* opponent):
            Ritual{"Fire Elemental Ability", "Whenever an opponent's minion enters play, deal 1 damage to it", 0, 1, 0, owner}, opponent{opponent} {}
        
        ~FireElementalAbility() { 
            opponent->detachMinionEnter(this);
        }

        void notify() override { 
            int i = opponent->getSummoned().size() - 1;
            Minion *m = opponent->removeSummonedMinion(i);∑
            opponent->replaceMinion(i, new ChangeStat{m, "0", "-1", 0, 0, false, nullptr});
        }

        void attach() override {
            opponent->attachMinionEnter(this);
        }
};

#endif