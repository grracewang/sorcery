#include "../minion.h"

class BoneGolem : public Minion {
    public: 
        BoneGolem(): Minion{"Bone Golem", "Minion", "Gain +1/+1 whenever a minion leaves play.", 2} {};
        bool activate(Card *t) override {};
        int getAtk() const override { return 1; }
        int getDef() const override { return 3; }
};