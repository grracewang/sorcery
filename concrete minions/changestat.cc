#include "changestat.h"
#include <iostream>
#include <sstream>
using namespace std;

ChangeStat::ChangeStat(Minion *target, string atkStr, string defStr,
                       int actionInc, int actCostInc, bool blockAbilities,
                       bool enchantment): 
    Decorator{target}, atkStr{atkStr}, defStr{defStr}, actionInc{actionInc},
    actCostInc{actCostInc}, blockAbilities{blockAbilities},
    enchantment{enchantment} {}


// normal unchanged getters
string ChangeStat::getName() const { return target->getName(); }
string ChangeStat::getType() const { return target->getType(); }
int ChangeStat::getCost() const { return target->getCost(); }
bool ChangeStat::isEnchantment() const { return enchantment; }

int ChangeStat::getAtk() const  {
    // no effect on minion's attack when string is empty
    if (atkStr == "") return target->getAtk();
    
    // get the information for the string
    char op;
    int val;
    if (istringstream iss{atkStr}; iss >> op >> val) {
        if (op == '+') {
            return target->getAtk() + val;
        }
        if (op == '*') {
            return target->getAtk() * val;
        }  
    }
    
    // code shouldn't reach this point (for debugging)
    cerr << "poorly formatted atkStr" << endl;
    return 0;
}

int ChangeStat::getDef() const {
    // no effect on minion's defence when string is empty
    if (defStr == "") return target->getDef();
    
    // get the information for the string
    char op;
    int val;
    if (istringstream iss{defStr}; iss >> op >> val) {
        if (op == '+') {
            return target->getDef() + val;
        }
        if (op == '*') {
            return target->getDef() * val;
        }  
    }
    
    // code shouldn't reach this point (for debugging)
    cerr << "poorly formatted defStr" << endl;
    return 0;
}

int ChangeStat::getBeginActions() const { return target->getAction() + actionInc; }

int ChangeStat::getActCost() const {
    if (target->getActCost() == -1) return -1;
    else return target->getActCost() + actCostInc;
}

vector<Spell*> ChangeStat::getSpells() const {
    if (blockAbilities) {
        vector<Spell*> empty;
        return empty;
    }
    return target->getSpells();
}

vector<Ritual*> ChangeStat::getRituals() const {
    if (blockAbilities) {
        vector<Ritual*> empty;
        return empty;
    }
    return target->getRituals();
}

string ChangeStat::toString(char op, int val) {
    return string(1, op) + to_string(val);
}
