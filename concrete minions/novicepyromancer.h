#include "minion.h"

class NovicePyromancer : public Minion {
    public:
        NovicePyromancer(): Minion{"Novice Pyromancer", "Minion", "Deal 1 damage to target minion", 2} {};
        bool activate(Card *t) override {};
        int getAtk() const override { return 0; }
        int getDef() const override { return 1; }
};