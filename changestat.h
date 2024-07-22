#ifndef CHANGESTAT_H
#define CHANGESTAT_H

#include "decorator.h"
#include "minion.h"
using namespace std;

class ChangeStat: public Decorator {
    private:
        char op; // either '+' or '*'
        int changeAtk;
        int changeDef;
    public:
        ChangeStat(Minion *target, char op, int changeAtk, int changeDef);
        int getAtk() const override;
        int getDef() const override;
        bool activate(Card *t) override;
};

#endif