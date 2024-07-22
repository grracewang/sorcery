#ifndef SILENCE_H
#define SILENCE_H

#include "enchantment.h"

class Silence: public Enchantment {
    public:
        explicit Silence(): Enchantment{"Silence", "Enchanted minion cannot use abilities", 1} {}
        bool activate(Card *t) override {}
};

#endif