#include "bonegolem.h"
#include "../ritual.h"
#include "../concrete rituals/bonegolemability.h"

string BoneGolem::getName() const { return "Bone Golem"; }
string BoneGolem::getType() const { return "Minion"; }
string BoneGolem::getDescription() const {
    return "Gain +1/+1 whenever a minion leaves play";
}
int BoneGolem::getCost() const { return 2; }

int BoneGolem::getAtk() const { return 1; }
int BoneGolem::getDef() const { return 3; }
int BoneGolem::getBeginActions() const { return 1; }
int BoneGolem::getActCost() const { return -1; }

void BoneGolem::addAbility(Player* owner, Player *opponent) {
    Ritual* r = new BoneGolemAbility(owner, owner->getSummoned().size() - 1);
    rituals.emplace_back(r);
    owner->attachMinionLeave(r);
    opponent->attachMinionLeave(r);
}

vector<Spell*> BoneGolem::getSpells() const {
    vector<Spell*> empty;
    return empty;
}