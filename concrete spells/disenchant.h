#ifndef DISENCHANT_H
#define DISENCHANT_H

#include "spell.h"

class Disenchant: public Spell {
    public:
        explicit Disenchant(): Spell{"Disenchant", "disenchant.txt", 1} {}
        void activate() override {}
};

#endif