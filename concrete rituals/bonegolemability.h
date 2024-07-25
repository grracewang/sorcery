#ifndef BONEGOLEMABILITY_H
#define BONEGOLEMABILITY_H

#include "../ritual.h"
#include "../concrete minions/bonegolem.h"
#include "../concrete minions/changestat.h"

class BoneGolemAbility: public Ritual {
    int boneGolemIndex;
    public:
        explicit BoneGolemAbility(Player *owner, int boneGolemIndex): 
            Ritual{"Bone Golem Ability", "Gain +1/+1 whenever a minion leaves play", 0, 1, 0, owner}, 
            boneGolemIndex{boneGolemIndex} {}

        ~BoneGolemAbility() { 
            owner->detachMinionLeave(this); 
        }
        
        void notify() override { 
            Minion *bg = owner->getSummonedMinion(boneGolemIndex);
            owner->replaceMinion(boneGolemIndex, new ChangeStat{m, "+1", "+1", 0, 0, false, nullptr});
        }

        void attach() override {
            owner->attachMinionLeave(this);
        }
};

#endif