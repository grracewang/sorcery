#ifndef EARTHELEMENTAL_H
#define EARTHELEMENTAL_H
#include "../minion.h"
#include "changestat.h"

class EarthElemental : public Minion {
    public:
        EarthElemental(): Minion{"Earth Elemental", "Minion", "", 3} {};
        int getAtk() const override { return 4; }
        int getDef() const override { return 4; }
};

#endif
