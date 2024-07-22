#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H
#include "../minion.h"
#include "changestat.h"
#include <string>

using namespace std;

class AirElemental : public Minion {
    public: 
        AirElemental(): Minion{"Air Elemental", "Minion", "", 0} {};
        bool attack (Minion *t) {
            if (t) {
                t = new ChangeStat{t, '+', 0, -1, 0};
                return 1;
            } else {
                cerr << "You must provide a target." << endl;
            }
        }
        int getAtk() const override { return 1; }
        int getDef() const override { return 1; }
};

#endif
