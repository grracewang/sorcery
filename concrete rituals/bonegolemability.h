#ifndef BONEGOLEMABILITY_H
#define BONEGOLEMABILITY_H

#include "../ritual.h"
#include "../concrete minions/bonegolem.h"
#include "../concrete minions/changestat.h"

class BoneGolemAbility: public Ritual {
    Minion *boneGolem;
    public:
        explicit BoneGolemAbility(Player *owner, Minion *bg): 
            Ritual{"Bone Golem Ability", "Gain +1/+1 whenever a minion leaves play", 0, 1, 0, owner}, boneGolem{bg} {}

        ~BoneGolemAbility() { owner->detachMinionLeave(this); }
        void notify() override { boneGolem = new ChangeStat{boneGolem, '+', 1, 1}; }

        void attach() ov
};

#endif