#ifndef SILENCE_H
#define SILENCE_H

#include <iostream>
#include "../enchantment.h"
#include "../concrete minions/changestat.h"

using namespace std;

class Silence: public Enchantment {
    public:
        explicit Silence(): Enchantment{"Silence", "Enchanted minion cannot use abilities", 1} {}
        Minion *activate(Minion *t) override {
            t = new ChangeStat{t, t->getAtkStr(), t->getDefStr(), 0, 0, true, true};
            return t;
        }
};

#endif