#ifndef STANDSTILL_H
#define STANDSTILL_H

#include "ritual.h"

class Standstill: public Ritual {
    public:
        explicit Standstill(Player *owner): Ritual{"Standstill", "standstill.txt", 3, 4, 2, owner} {}
        void activate() override {}
        void notify() override {}
};

#endif