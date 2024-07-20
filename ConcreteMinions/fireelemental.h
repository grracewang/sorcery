#include "minion.h"

class FireElemental : public Minion {
    public:
        FireElemental(): Minion{"Fire Elemental", "Minion", "Whenever an opponent's minion enters play, deal 1 damage to it.", 2, 2, 2} {};
        void activate() override {};
};