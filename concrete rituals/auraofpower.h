#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "../ritual.h"
#include "../minion.h"

class AuraOfPower: public Ritual {
    public:
        explicit AuraOfPower(Player *owner): Ritual{"Aura of Power", "Whenever a minion enters play under your control, it gains +1/+1", 1, 5, 1, owner} {};

        ~AuraOfPower() {
            owner->detachMinionEnter(this);
        }
        // bool activate(Card *t)  {}
        void notify() override {
            Minion* m = owner->getSummonedMinion(owner->getSummoned().size() - 1);
            m = new ChangeStat{m, '+', 1, 1};
        }
        void attach() {
            owner->attachMinionEnter(this);
        }
};

#endif