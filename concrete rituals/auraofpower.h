#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "../ritual.h"
#include "../minion.h"
#include "../concrete minions/changestat.h"

class AuraOfPower: public Ritual {
    public:
        explicit AuraOfPower(Player *owner): Ritual{"Aura of Power", "Whenever a minion enters play under your control, it gains +1/+1", 1, 5, 1, owner} {};

        ~AuraOfPower() {
            owner->detachMinionEnter(this);
        }
        // bool activate(Card *t)  {}
        void notify() override {
            charges -= activationCost;
            if (charges < 0) {
                owner->removeRitual();
            } else {
                Minion* m = owner->getSummonedMinion(owner->getSummoned().size() - 1);
                m = new ChangeStat{m, '+', 1, 1};
            }
        }
        
        void attach() override {
            owner->attachMinionEnter(this);
        }
};

#endif