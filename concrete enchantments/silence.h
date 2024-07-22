#ifndef SILENCE_H
#define SILENCE_H

#include <iostream>
#include "enchantment.h"

using namespace std;

class Silence: public Enchantment {
    public:
        explicit Silence(): Enchantment{"Silence", "Enchanted minion cannot use abilities", 1} {}
        bool activate(Minion *t) {
            if (t) return 1;
            else {
                cerr << "You must provide a target." << endl;
                return 0;
            }
        }
};

#endif