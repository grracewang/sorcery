#include "minion.h"

class PotionSeller : public Minion {
    public:
        PotionSeller(): Minion{"Potion Seller", "Minion", "At the end of your turn, all your minions gain +0/+1", 2, 1, 3} {};
        void activate() override {};
};