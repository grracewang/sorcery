#ifndef AURAOFPOWER_H
#define AURAOFPOWER_H

#include "ritual.h"

class AuraOfPower: public Ritual {
    public:
        explicit AuraOfPower(Player *owner): Ritual{"Aura of Power", "auraofpower.txt", 1, 5, 1, owner} {}
        void activate() override {}
        void notify() override {}
};

#endif