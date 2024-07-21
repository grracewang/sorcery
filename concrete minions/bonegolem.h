#include "minion.h"

class BoneGolem : public Minion {
    public: 
        BoneGolem(): Minion{"Bone Golem", "Minion", "bonegolem.txt", 2, 1, 3} {};
        void activate() override {};
};