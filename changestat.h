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
        ChangeStat(Minion *target, char op, int changeAtk, int changeDef): 
            Decorator{target}, op{op}, changeAtk{changeAtk}, changeDef{changeDef} {}

        int getAtk() const override {
            if (op == '+') {
                return target->getAtk() + changeAtk;
            } else if (op == '*') {
                return target->getAtk() * changeAtk;
            } else {
                cerr << "op is neither + nor *" << endl;
                return 0;
            }
        }

        int getDef() const override {
            if (op == '+') {
                return target->getDef() + changeDef;
            } else if (op == '*') {
                return target->getDef() * changeDef;
            } else {
                cerr << "op is neither + nor *" << endl;
                return 0;
            }
        }

        bool activate(Player *p, Card *t) override {}
};

#endif