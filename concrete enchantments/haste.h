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
        bool activate(Minion *t) {
            if (t) {
                if (!usedHaste) t->setActions(1);
                return 1;
            } else {
                cerr << "You must provide a target." << endl;
                return 0;
            }
        }
};

#endif