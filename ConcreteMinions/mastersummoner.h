#include "minion.h"

class MasterSummoner : public Minion {
    public:
        MasterSummoner(): Minion{"Master Summoner", "Minion", "Summon up to three 1/1 air elementals", 3, 2, 3} {};
        activate() override {};
};