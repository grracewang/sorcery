#include "minion.h"

class PotionSeller : public Minion {
    public:
        PotionSeller(): Minion{"Potion Seller", "Minion", "potionseller.txt", 2, 1, 3} {};
        void activate() override {};
};