#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include <iostream>
#include <string>
#include "../enchantment.h"
#include "../concrete_minions/changestat.h"

using namespace std;

class GiantStrength: public Enchantment {
    public:
        GiantStrength(): 
            Enchantment{"Giant Strength", "", 1, "+2", "+2"} {}
        Minion *activate(Minion *t) override {
            return new ChangeStat{t, getAtkStr(), getDefStr(), 0, 0, false, this};
        }
};

#endif
