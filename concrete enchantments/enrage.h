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
        void activate(Minion *t) {
            t = new ChangeStat{t, '*', 2, 2, 0};
        }
};

#endif