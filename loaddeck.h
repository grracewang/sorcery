#include "card.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "player.h"

#include "airelemental.h"
#include "earthelemental.h"
#include "bonegolem.h"
#include "fireelemental.h"
#include "apprenticesummoner.h"
#include "fireelemental.h"
#include "mastersummoner.h"
#include "novicepyromancer.h"
#include "potionseller.h"
#include "banish.h" // spells
#include "blizzard.h"
#include "disenchant.h"
#include "raisedead.h"
#include "recharge.h"
#include "unsummon.h"
#include "auraofpower.h" // rituals
#include "darkritual.h"
#include "standstill.h"
#include "enrage.h" // enchantments
#include "giantstrength.h"
#include "haste.h"
#include "magicfatigue.h"
#include "silence.h"

Card* loadCard(string card, Player* owner) {
    if (card == "Air Elemental") { // Minions
        return new AirElemental();
    } else if (card == "Earth Elemental") {
        return new EarthElemental();
    } else if (card == "Bone Golem") {
        return new BoneGolem();
    } else if (card == "Apprentice Summoner") {
        return new ApprenticeSummoner();
    } else if (card == "Fire Elemental") {
        return new FireElemental();
    } else if (card == "Master Summoner") {
        return new MasterSummoner();
    } else if (card == "Novice Pyromancer") {
        return new NovicePyromancer();
    } else if (card == "Potion Seller") {
        return new PotionSeller();
    } else if (card == "Banish") { // Spells
        return new Banish();
    } else if (card == "Blizzard") { 
        return new Blizzard();
    } else if (card == "Disenchant") {
        return new Disenchant();
    } else if (card == "Raise Dead") { 
        return new RaiseDead();
    } else if (card == "Recharge") {
        return new Recharge();
    } else if (card == "Unsummon") { 
        return new Unsummon();
    } else if (card == "Aura of Power") { // Rituals
        return new AuraOfPower(owner);
    } else if (card == "Dark Ritual") { 
        return new DarkRitual(owner);
    } else if (card == "Standstill") { 
        return new Standstill(owner);
    } else if (card == "Enrage") { // Enchantments
        return new Enrage();
    } else if (card == "Giant Strength") { 
        return new GiantStrength();
    } else if (card == "Haste") {
        return new Haste();
    } else if (card == "Magic Fatigue") {
        return new MagicFatigue();
    } else { // Silence
        return new Silence();
    }
}

