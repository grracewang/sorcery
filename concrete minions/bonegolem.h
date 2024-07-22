#include "../minion.h"
#include "changestat.h"

class BoneGolem : public Minion {
    public: 
        BoneGolem(): Minion{"Bone Golem", "Minion", "Gain +1/+1 whenever a minion leaves play.", 2} {};
        void activate(Card *t) {};
        int getAtk() const override { return 1; }
        int getDef() const override { return 3; }
        int getCost() const override { return 0; }
};