#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "../ritual.h"

class AuraOfPower: public Ritual {
    public:
        explicit AuraOfPower(Player *owner): Ritual{"Aura of Power", "Whenever a minion enters play under your control, it gains +1/+1", 1, 5, 1, owner} {}
        bool activate(Card *t) override {}
        void notify() override {}
};

#endif