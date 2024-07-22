#include "../minion.h"
#include "changestat.h"

class ApprenticeSummoner : public Minion {
    public: 
        ApprenticeSummoner(): Minion{"Apprentice Summoner", "Minion", "Summon a 1/1 air elemental.", 1} {};
        void activate(Card *t) {

        }
        int getAtk() const override { return 1; }
        int getDef() const override { return 1; }
        int getCost() const override { return 1; } // change to spell.cost()
};