#include "../minion.h"
#include "changestat.h"

class ApprenticeSummoner : public Minion {
    public: 
        ApprenticeSummoner(): Minion{"Apprentice Summoner", "Minion", "Summon a 1/1 air elemental.", 1} {};
        bool attack(Card* target) override {
            if (target) {
                target = new ChangeStat{target, '+', 0, -1, 0};
                return true;
            } else {
                // cerr << "You must provide a target." << endl;
                return false;
            }
        }
        bool activate(Card *t) override {};
        int getAtk() const override { return 1; }
        int getDef() const override { return 1; }
        int getCost() const override { return 1; } // change to spell.cost()
};