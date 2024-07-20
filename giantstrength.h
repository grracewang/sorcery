#ifndef GIANTSTRENGTH_H
#define GIANTSTRENGTH_H

#include "enchantment.h"
#include <string>

class GiantStrength: public Enchantment {
    public:
        explicit GiantStrength(string, string, string, int, Minion);
        void activate() override;
};

#endif