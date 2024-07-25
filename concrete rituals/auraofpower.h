#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "../ritual.h"
#include "../minion.h"
#include "../concrete minions/changestat.h"

class AuraOfPower: public Ritual {
    public:
        explicit AuraOfPower(Player *owner): 
            Ritual{"Aura of Power", "Whenever a minion enters play under your control, it gains +1/+1", 1, 5, 1, owner} {};

        ~AuraOfPower() {
            owner->detachMinionEnter(this);
        }

        void notify() override {
            charges -= activationCost;
            if (charges < 0) owner->removeRitual();
            else {
                int idx = owner->getSummoned().size() - 1;
                Minion* m = owner->getSummonedMinion(idx);
                owner->replaceMinion(idx, new ChangeStat{m, "+1", "+1", 0, 0, false, false});
            }
        }
        
        void attach() override {
            owner->attachMinionEnter(this);
        }
};

#endif