#ifndef HASTE_H
#define HASTE_H

#include "../enchantment.h"
#include "../concrete minions/changestat.h"
#include <iostream>
#include <string>

class Haste: public Enchantment {
    private:
        inline static bool usedHaste = 0;
    public: 
        explicit Haste(): Enchantment{"Haste", "Enchanted minion gains +1 action each turn", 1} {}
        Minion *activate(Minion *t) override {
            return new ChangeStat{t, getAtkStr(), getDefStr(), 1, 0, false, this};
        }
};

#endif
