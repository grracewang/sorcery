#ifndef CHANGESTAT_H
#define CHANGESTAT_H

#include "decorator.h"
#include "minion.h"

class ChangeStat: public Decorator {
    public:
        ChangeStat(Minion *m);
        int getAtk() override;
        int getDef() override;
};

#endif