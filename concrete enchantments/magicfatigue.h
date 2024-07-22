#ifndef MAGICFATIGUE_H
#define MAGICFATIGUE_H

#include "enchantment.h"

class MagicFatigue: public Enchantment {
    public:
        explicit MagicFatigue(): Enchantment{"Magic Fatigue", "Enchanted minion's activated ability costs 2 more", 0} {}
        bool activate(Minion *t) {}
};

#endif