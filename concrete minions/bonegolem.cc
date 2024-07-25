#include "bonegolem.h"

string BoneGolem::getName() const { return "Bone Golem"; }
string BoneGolem::getType() const { return "Minion"; }
int BoneGolem::getCost() const { return 2; }

int BoneGolem::getAtk() const { return 1; }
int BoneGolem::getDef() const { return 3; }
int BoneGolem::getBeginActions() const { return 1; }
int BoneGolem::getActCost() const { return -1; }
vector<Spell*> BoneGolem::getSpells() const {
    vector<Spell*> empty;
    return empty;
}
vector<Ritual*> BoneGolem::getRituals() const {
    vector<Ritual*> r;
    r.emplace_back(BoneGolemAbility(player, myself_pointer)) // change this
    return r;
}
