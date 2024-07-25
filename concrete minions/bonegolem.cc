#include "bonegolem.h"

string BoneGolem::getName() const { return "Bone Golem"; }
string BoneGolem::getType() const { return "Minion"; }
string BoneGolem::getDescription() const { return " Gain +1/+1 whenever a minion leaves play."; }
int BoneGolem::getCost() const { return 2; }
int BoneGolem::getAction() const { return actions; }

int BoneGolem::getAtk() const { return 1; }
int BoneGolem::getDef() const { return 3; }
int BoneGolem::getBeginActions() const { return 1; }
int BoneGolem::getActCost() const { return -1; }
vector<Spell*> BoneGolem::getSpells() const {
    vector<Spell*> empty;
    return empty;
}
vector<Ritual*> BoneGolem::getRituals() const {
    vector<Ritual*> empty;
    return empty;
}
