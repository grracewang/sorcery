#ifndef HASTE_H
#define HASTE_H

#include "enchantment.h"
#include "../concrete minions/changestat.h"
#include <iostream>

using namespace std;

class Haste: public Enchantment {
    private:
        inline static bool usedHaste = 0;
    public: 
        explicit Haste(): Enchantment{"Haste", "Enchanted minion gains +1 action each turn", 1} {}
        Minion *activate(Minion *t) override {
            t = new ChangeStat{t, t->getAtkStr(), t->getDefStr(), 1, 0, false, true};
            return t;
        }
};

#endif