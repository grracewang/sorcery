#ifndef MAGICFATIGUE_H
#define MAGICFATIGUE_H

#include "enchantment.h"
#include "../concrete minion/changestat.h"

class MagicFatigue: public Enchantment {
    public:
        explicit MagicFatigue(): Enchantment{"Magic Fatigue", "Enchanted minion's activated ability costs 2 more", 0} {}
        void activate(Minion *target) override {
            target = new ChangeStats{target, '+', 0, 0, 2};
        }
};

#endif