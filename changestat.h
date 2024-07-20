#ifndef CHANGESTAT_H
#define CHANGESTAT_H

#include "decorator.h"
#include "minion.h"

class ChangeStat: public Decorator {
    public:
        ChangeStat(Minion *target, char op): Decorator{target, op} {}
        int getAtk() override;
        int getDef() override;
};

#endif