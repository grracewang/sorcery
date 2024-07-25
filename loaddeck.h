#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "card.h"
#include "player.h"
#include "minion.h"
#include "./concrete minions/airelemental.h"
#include "./concrete minions/earthelemental.h"
#include "./concrete minions/bonegolem.h"
#include "./concrete minions/fireelemental.h"
#include "./concrete minions/apprenticesummoner.h"
#include "./concrete minions/mastersummoner.h"
#include "./concrete minions/novicepyromancer.h"
#include "./concrete minions/potionseller.h"
#include "./concrete spells/banish.h" // spells
#include "./concrete spells/blizzard.h"
#include "./concrete spells/disenchant.h"
#include "./concrete spells/raisedead.h"
#include "./concrete spells/recharge.h"
#include "./concrete spells/unsummon.h"
#include "./concrete rituals/auraofpower.h" // rituals
#include "./concrete rituals/darkritual.h"
#include "./concrete rituals/standstill.h"
#include "./concrete enchantments/enrage.h" // enchantments
#include "./concrete enchantments/giantstrength.h"
#include "./concrete enchantments/haste.h"
#include "./concrete enchantments/magicfatigue.h"
#include "./concrete enchantments/silence.h"

Card* loadCard(string card, Player* owner, Player* opponent) {
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
        return new Standstill(owner, opponent);
    } else if (card == "Enrage") { // Enchantments
        return new Enrage();
    } else if (card == "Giant Strength") { 
        return new GiantStrength();
    } else if (card == "Haste") {
        return new Haste();
    } else if (card == "Magic Fatigue") {
        return new MagicFatigue();
    } else { // Silence
        return new Silence(opponent, owner); // we assume target is opponent
    }
}

void shuffleDeck(std::vector<Card*>& deck) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::shuffle(deck.begin(), deck.end(), rng);
}