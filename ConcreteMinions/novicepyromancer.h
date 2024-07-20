#include "minion.h"

class NovicePyromancer : public Minion {
    public:
        NovicePyromancer(): Minion{"Novice Pyromancer", "Minion", "novicepyromancer.txt", 2, 0, 1} {};
        void activate() override {};
};