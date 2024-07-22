#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H
#include "../minion.h"
#include "changestat.h"
#include <string>

using namespace std;

class AirElemental : public Minion {
    public: 
        AirElemental(): Minion{"Air Elemental", "Minion", "", 0} {};
        int getAtk() const override { return 1; }
        int getDef() const override { return 1; }
        int getCost() const override { return 0; }
        void attack(Minion *target) override {
            target = new ChangeStat{target, '+', 0, -1, 0};
        }
};

#endif
