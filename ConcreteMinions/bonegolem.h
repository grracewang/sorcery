#include "minion.h"

class BoneGolem : public Minion {
    public: 
        BoneGolem(): Minion{"Bone Golem", "Minion", "Gain +1/+1 whoenever a minion leaves play.", 2, 1, 3} {};
        activate() override {};
};