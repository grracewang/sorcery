#ifndef ENRAGE_H
#define ENRAGE_H

#include <iostream>
#include <string>
#include "enchantment.h"
#include "changestat.h"

using namespace std;

class Enrage: public Enchantment {
    public:
        explicit Enrage(): Enchantment{"Enrage", "", 2, "*2", "*2"} {}
        bool activate(Minion *t = nullptr) {
            if (t) {
                t = new ChangeStat{t, '*', 2, 2};
                return 1;
            } else {
                cerr << "You must provide a target." << endl;
                return 0;
            }
        }
};

#endif