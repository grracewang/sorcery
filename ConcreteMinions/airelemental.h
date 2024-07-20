#include "minion.h"

class AirElemental : public Minion {
    public: 
        AirElemental(): Minion{"Air Elemental", "Minion", "", 0, 1, 1} {};
        void activate() override {};
};