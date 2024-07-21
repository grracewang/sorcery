#include "minion.h"

class FireElemental : public Minion {
    public:
        FireElemental(): Minion{"Fire Elemental", "Minion", "fireelemental.txt", 2, 2, 2} {};
        void activate() override {};
};