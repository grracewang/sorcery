#ifndef ENRAGE_H
#define ENRAGE_H

#include <iostream>
#include <string>
#include "../enchantment.h"
#include "../concrete_minions/changestat.h"

using namespace std;

class Enrage: public Enchantment {
    public:
        explicit Enrage(): Enchantment{"Enrage", "", 2, "*2", "*2"} {}
        Minion *activate(Minion *t) override {
            return new ChangeStat{t, getAtkStr(), getDefStr(), 0, 0, false, this};
        }
};

#endif
