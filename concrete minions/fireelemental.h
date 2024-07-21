#include "../minion.h"

class FireElemental : public Minion {
    public:
        FireElemental(): Minion{"Fire Elemental", "Minion", "Whenever an opponent's minion enters play, deal 1 damage to it", 2} {};
        bool activate(Card *t) override {};
        int getAtk() const override { return 2; }
        int getDef() const override { return 2; }
};