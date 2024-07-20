#ifndef MAGICFATIGUE_H
#define MAGICFATIGUE_H

#include "enchantment.h"

class MagicFatigue: public Enchantment {
    public:
        explicit MagicFatigue(): Enchantment{"Magic Fatigue", "magicfatigue.txt", 0} {}
        void activate() override {}
};

#endif