#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "../ritual.h"
#include "../minion.h"
#include "../concrete minions/changestat.h"
#include <string>
#include <vector>

class AuraOfPower: public Ritual {
    public:
        explicit AuraOfPower(Player *owner): 
            Ritual{"Aura of Power", "Whenever a minion enters play under your control, it gains +1/+1", 1, 5, 1, owner} {};

        ~AuraOfPower() {
            owner->detachMinionEnter(this);
        }

        void notify() override {
            charges -= activationCost;
            if (charges < 0) owner->setRitual(nullptr);
            else {
                int idx = owner->getSummoned().size() - 1;
                Minion* m = owner->getSummonedMinion(idx);
                owner->setSummoned(idx, new ChangeStat{m, "+1", "+1", 0, 0, false, nullptr});
            }
        }
        
        void attach() override {
            owner->attachMinionEnter(this);
        }
};

#endif
