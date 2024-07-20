#include "minion.h"

class NovicePyromancer : public Minion {
    public:
        NovicePyromancer(): Minion{"Novice Pyromancer", "Minion", "At the end of your turn, all your minions gain +0/+1.", 2, 0, 1} {};
        activate() override {};
}