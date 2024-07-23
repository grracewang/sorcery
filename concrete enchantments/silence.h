#ifndef SILENCE_H
#define SILENCE_H

#include <iostream>
#include "enchantment.h"

using namespace std;

class Silence: public Enchantment {
    public:
        explicit Silence(): Enchantment{"Silence", "Enchanted minion cannot use abilities", 1} {}
        void activate(Minion *target) override {
            
        }
};

#endif