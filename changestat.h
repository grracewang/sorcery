#ifndef CHANGESTAT_H
#define CHANGESTAT_H

#include "decorator.h"
#include "minion.h"

class ChangeStat: public Decorator {
    public:
        ChangeStat(Minion *target, char op): Decorator{target, op} {}
        int getAtk() const override {
            if (op == '+') { return atk; }
        }
        int getDef() const override { return def; }
        bool activate(Player *p, Card *t) override {}
};

#endif