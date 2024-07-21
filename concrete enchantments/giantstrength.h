#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include "enchantment.h"
#include "changestat.h"
#include <string>

class GiantStrength: public Enchantment {
    public:
        explicit GiantStrength(): 
            Enchantment{"Giant Strength", "giantstrength.txt", 1, "+2", "+2"} {}
        void activate(Player *p, Card *t) override {}
};

#endif