#ifndef ENRAGE_H
#define ENRAGE_H

#include "enchantment.h"
#include "changestat.h"
#include <string>

class Enrage: public Enchantment {
    public:
        explicit Enrage(): Enchantment{"Enrage", "", 2, "*2", "*2"} {}
        bool activate(Card *t) override {}
};

#endif