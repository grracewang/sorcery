#ifndef CHANGESTAT_H
#define CHANGESTAT_H

#include "decorator.h"
#include "minion.h"

class ChangeStat: public Decorator {
    public:
        ChangeStat(Minion *target, char op): Decorator{target, op} {}
        int getAtk() const override {}
        int getDef() const override {}
        void activate() const override {}
};

#endif