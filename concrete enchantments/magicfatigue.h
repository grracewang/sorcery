#ifndef MAGICFATIGUE_H
#define MAGICFATIGUE_H

#include "../enchantment.h"
#include "../concrete minions/changestat.h"

class MagicFatigue: public Enchantment {
    public:
        explicit MagicFatigue(): Enchantment{"Magic Fatigue", "Enchanted minion's activated ability costs 2 more", 0} {}
        Minion *activate(Minion *t) override {
            return new ChangeStat{t, getAtkStr(), getDefStr(), 0, 2, false, true};
        }
};

#endif