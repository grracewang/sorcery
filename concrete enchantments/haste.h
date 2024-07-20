#ifndef HASTE_H
#define HASTE_H

#include "enchantment.h"

class Haste: public Enchantment {
    public: 
        explicit Haste(): Enchantment{"Haste", "haste.txt", 1} {}
        void activate() override {}
};

#endif