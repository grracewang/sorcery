#include "minion.h"

class EarthElemental : public Minion {
    public:
        EarthElemental(): Minion{"Earth Elemental", "Minion", "earthelemental.txt", 3, 4, 4} {};
        void activate() override {};
};