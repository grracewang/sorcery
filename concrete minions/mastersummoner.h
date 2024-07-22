#include "../minion.h"
#include "changestat.h"

class MasterSummoner : public Minion {
    public:
        MasterSummoner(): Minion{"Master Summoner", "Minion", "Summon up to three 1/1 air elementals", 3} {};
        bool activate(Card *t) override {};
        int getAtk() const override { return 2; }
        int getDef() const override { return 3; }
        int getCost() const override { return 2; } // change to spell.cost()
};