#ifndef UNSUMMON_H
#define UNSUMMON_H

#include "spell.h"

class Unsummon: public Spell {
    public:
        explicit Unsummon(): Spell{"Unsummon", "unsummon.txt", 1} {}
        void activate() override {}
};

#endif