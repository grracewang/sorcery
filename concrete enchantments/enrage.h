#ifndef ENRAGE_H
#define ENRAGE_H

#include "enchantment.h"
#include "changestat.h"
#include <string>

class Enrage: public Enchantment {
    public:
        explicit Enrage(): Enchantment{"Enrage", "enrage.txt", 2} {}
        void activate() override {}
};

#endif