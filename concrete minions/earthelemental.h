#ifndef EARTHELEMENTAL_H
#define EARTHELEMENTAL_H
#include "../minion.h"

class EarthElemental : public Minion {
    public:
        EarthElemental(): Minion{"Earth Elemental", "Minion", "", 3} {};
        bool activate(Card *t) override {};
        int getAtk() const override { return 4; }
        int getDef() const override { return 4; }
};
