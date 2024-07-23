#include "../minion.h"
#include "changestat.h"
#include "airelemental.h"

class MasterSummoner : public Minion {
    public:
        MasterSummoner(): Minion{"Master Summoner", "Minion", "Summon up to three 1/1 air elementals", 3, false} {};
        void activate(Player *p) {
            for (int i = 0; i < 3; ++i) {
                if (p->getSummoned().size() < p->MAX_SUMMONED) p->addToSummoned(new AirElemental);
            }
        };
        int getAtk() const override { return 2; }
        int getDef() const override { return 3; }
        int getCost() const override { return 2; } // change to spell.cost()
};