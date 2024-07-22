#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H
#include "../minion.h"
#include <string>

class AirElemental : public Minion {
    public: 
        AirElemental(): Minion{"Air Elemental", "Minion", "", 0} {};
        bool activate(Card *t) override {
            if ( t == nullptr ) {
                cerr << "Must provide a target." << endl;
                return false;
            } else {
                return true;  
            }
        }
        int getAtk() const override { return 1; }
        int getDef() const override { return 1; }
};

#endif
