#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include <iostream>
#include <string>
#include "enchantment.h"
#include "changestat.h"

using namespace std;

class GiantStrength: public Enchantment {
    public:
        explicit GiantStrength(): 
            Enchantment{"Giant Strength", "", 1, "+2", "+2"} {}
        void activate(Minion *t) {
            if (t) t = new ChangeStat{t, '+', 2, 2};
        }
};

#endif