#ifndef BLIZZARD_H
#define BLIZZARD_H

#include "spell.h"

class Blizzard: public Spell {
    public:
        explicit Blizzard(): Spell{"Blizzard", "blizzard.txt", 3} {}
        bool activate(Card *t) override {}
};

#endif