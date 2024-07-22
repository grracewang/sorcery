#ifndef EARTHELEMENTAL_H
#define EARTHELEMENTAL_H
#include "../minion.h"
#include "changestat.h"

class EarthElemental : public Minion {
    public:
        EarthElemental(): Minion{"Earth Elemental", "Minion", "", 3} {};
        bool attack(Card *target) override { 
            if ( target) {
                target = new ChangeStat{target, '+', 0, -4, 0};
                return true;
            } else {
                // cerr << "Must provide a target." << endl;
                return false;  
            }
        }
        int getAtk() const override { return 4; }
        int getDef() const override { return 4; }
        int getCost() const override { return 0; }
};

#endif
