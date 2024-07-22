#include "changestat.h"
#include <iostream>

using namespace std;

ChangeStat::ChangeStat(Minion *target, char op, int changeAtk, int changeDef, int changeCost): 
    Decorator{target}, op{op}, changeAtk{changeAtk}, changeDef{changeDef}, changeCost{changeCost} {}

int ChangeStat::getAtk() const  {
    if (op == '+') {
        return target->getAtk() + changeAtk;
    } else if (op == '*') {
        return target->getAtk() * changeAtk;
    } else {
        cerr << "op is neither + nor *" << endl;
        return 0;
    }
}

int ChangeStat::getDef() const {
    if (op == '+') {
        return target->getDef() + changeDef;
    } else if (op == '*') {
        return target->getDef() * changeDef;
    } else {
        cerr << "op is neither + nor *" << endl;
        return 0;
    }
}

int ChangeStat::getCost() const {
    if (op == '+') {
        return target->getCost() + changeCost;
    } else if (op == '*') {
        return target->getCost() * changeCost;
    } else {
        cerr << "op is neither + nor *" << endl;
        return 0;
    }
}

void ChangeStat::attack(Minion *) {}
