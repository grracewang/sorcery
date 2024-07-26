#ifndef BONEGOLEMABILITY_H
#define BONEGOLEMABILITY_H

#include "../ritual.h"
#include "../concrete_minions/bonegolem.h"
#include "../concrete_minions/changestat.h"
#include <string>

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
            owner->setSummoned(boneGolemIndex, new ChangeStat{bg, "+1", "+1", 0, 0, false, nullptr});
        }

        void attach() override {
            owner->attachMinionLeave(this);
        }
};

#endif
