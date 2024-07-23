#ifndef HASTE_H
#define HASTE_H

#include "enchantment.h"
#include <iostream>
using namespace std;

class Haste: public Enchantment {
    private:
        inline static bool usedHaste = 0;
    public: 
        explicit Haste(): Enchantment{"Haste", "Enchanted minion gains +1 action each turn", 1} {}
        void activate(Minion *target) override {
            if (target) {
                if (!usedHaste) target->setActions(1);
            }
        }
};

#endif