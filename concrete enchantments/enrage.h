#ifndef ENRAGE_H
#define ENRAGE_H

#include "enchantment.h"
#include "changestat.h"
#include <string>

class Enrage: public Enchantment {
    public:
        explicit Enrage(): Enchantment{"Enrage", "enrage.txt", 2, "*2", "*2"} {}
        bool activate(Player *p, Card *t) override {
            t = new ChangeStat{t->getAtk
        }
};

#endif