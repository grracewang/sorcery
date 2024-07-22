#include "../minion.h"
#include "changestat.h"

class PotionSeller : public Minion {
    public:
        PotionSeller(): Minion{"Potion Seller", "Minion", "At the end of your turn, all your minions gain +0/+1", 2} {};
        bool attack(Minion *target) override {
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
        int getDef() const override { return 3; }
        int getCost() const override { return 0; }
};