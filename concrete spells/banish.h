#ifndef BANISH_H
#define BANISH_H

#include "spell.h"

class Banish: public Spell {
    public:
        explicit Banish(): Spell{"Banish", "banish.txt", 2} {}
        void activate() override {}
};

#endif