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
        bool activate(Minion *t) {
            if (t) {
                t = new ChangeStat{t, '+', 2, 2};
                return 1;
            } else {
                cerr << "You must provide a target." << endl;
                return 0;
            }
        }
};

#endif