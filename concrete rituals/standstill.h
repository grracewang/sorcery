#ifndef STANDSTILL_H
#define STANDSTILL_H

#include "../ritual.h"

class Standstill: public Ritual {
    public:
        explicit Standstill(Player *owner): Ritual{"Standstill", "Whenever a minion enters play, destroy it", 3, 4, 2, owner} {}
        bool activate(Card *) override {}
        void notify() override {}
};

#endif