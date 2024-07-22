#ifndef HASTE_H
#define HASTE_H

#include "enchantment.h"

class Haste: public Enchantment {
    public: 
        explicit Haste(): Enchantment{"Haste", "Enchanted minion gains +1 action each turn", 1} {}
        bool activate(Card *t) override {}
};

#endif