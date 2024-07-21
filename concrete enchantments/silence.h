#ifndef SILENCE_H
#define SILENCE_H

#include "enchantment.h"

class Silence: public Enchantment {
    public:
        explicit Silence(): Enchantment{"Silence", "silence.txt", 1} {}
        bool activate(Player *p, Card *t) override {}
};

#endif