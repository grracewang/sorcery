#include "../minion.h"
#include "changestat.h"
#include <iostream>
class NovicePyromancer : public Minion {
    public:
        NovicePyromancer(): Minion{"Novice Pyromancer", "Minion", "Deal 1 damage to target minion", 2} {};
        void activate(Minion *target) {
            target = new ChangeStat{target, '+', 0, -1};
        }
        int getAtk() const override { return 0; }
        int getDef() const override { return 1; }
};