#ifndef CHANGESTAT_H
#define CHANGESTAT_H

#include "decorator.h"
#include "../minion.h"
using namespace std;

class ChangeStat: public Decorator {
    private:
        char op; // either '+' or '*'
        int changeAtk;
        int changeDef;
        int changeCost;
    public:
        ChangeStat(Minion *target, char op, int changeAtk, int changeDef, int changeCost);
        int getAtk() const override;
        int getDef() const override;
        int getCost() const override;

        // overriden virtual fcn that do nothing
        void attack(Minion *) override;

};

#endif