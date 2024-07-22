#include "../minion.h"
#include "changestat.h"

class FireElemental : public Minion {
    public:
        FireElemental(): Minion{"Fire Elemental", "Minion", "Whenever an opponent's minion enters play, deal 1 damage to it", 2} {};
        bool attack(Minion *target) override {
            if (target) {
                target = new ChangeStat{target, '+', 0, -2, 0};
                return true;
            } else {
                // cerr << "You must provide a target." << endl;
                return false;
            }
        }
        bool activate(Card *t) override {};
        int getAtk() const override { return 2; }
        int getDef() const override { return 2; }
        int getCost() const override { return 0; }
};