#include "minion.h"

class PotionSeller : public Minion {
    public:
        PotionSeller(): Minion{"Potion Seller", "Minion", "At the end of your turn, all your minions gain +0/+1", 2} {};
        bool activate(Card *t) override {};
        int getAtk() const override { return 1; }
        int getDef() const override { return 3; }
};