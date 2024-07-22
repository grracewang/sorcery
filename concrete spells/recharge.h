#ifndef RECHARGE_H
#define RECHARGE_H

#include "spell.h"

class Recharge: public Spell {
    public:
        explicit Recharge(): Spell{"Recharge", "recharge.txt", 1} {}
        bool activate(Card *t) override {}
};

#endif