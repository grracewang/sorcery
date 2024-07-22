#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include "enchantment.h"
#include "changestat.h"
#include <string>

class GiantStrength: public Enchantment {
    public:
        explicit GiantStrength(): 
            Enchantment{"Giant Strength", "", 1, "+2", "+2"} {}
        bool activate(Card *t) override {}
};

#endif