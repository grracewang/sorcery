#include "../minion.h"
#include "changestat.h"

class BoneGolem : public Minion {
    public: 
        BoneGolem(): Minion{"Bone Golem", "Minion", "Gain +1/+1 whenever a minion leaves play.", 2} {};
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