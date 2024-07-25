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
            return new ChangeStat{t, getAtkStr(), getDefStr(), 0, 0, true, this};
        }
};

#endif