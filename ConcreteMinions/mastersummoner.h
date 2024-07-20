#include "minion.h"

class MasterSummoner : public Minion {
    public:
        MasterSummoner(): Minion{"Master Summoner", "Minion", "mastersummoner.txt", 3, 2, 3} {};
        void activate() override {};
};