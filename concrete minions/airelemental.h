#include "minion.h"
#include <string>

class AirElemental : public Minion {
    public: 
        AirElemental(): Minion{"Air Elemental", "Minion", "airelemental.txt", 0, 1, 1} {};
        void activate() override {};
};