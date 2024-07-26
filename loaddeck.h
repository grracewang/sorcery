#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

#include "card.h"
#include "player.h"
#include "minion.h"
#include "./concrete_minions/airelemental.h"
#include "./concrete_minions/earthelemental.h"
#include "./concrete_minions/bonegolem.h"
#include "./concrete_minions/fireelemental.h"
#include "./concrete_minions/apprenticesummoner.h"
#include "./concrete_minions/mastersummoner.h"
#include "./concrete_minions/novicepyromancer.h"
#include "./concrete_minions/potionseller.h"
#include "./concrete_spells/banish.h" // spells
#include "./concrete_spells/blizzard.h"
#include "./concrete_spells/disenchant.h"
#include "./concrete_spells/raisedead.h"
#include "./concrete_spells/recharge.h"
#include "./concrete_spells/unsummon.h"
#include "./concrete_rituals/auraofpower.h" // rituals
#include "./concrete_rituals/darkritual.h"
#include "./concrete_rituals/standstill.h"
#include "./concrete_enchantments/enrage.h" // enchantments
#include "./concrete_enchantments/giantstrength.h"
#include "./concrete_enchantments/haste.h"
#include "./concrete_enchantments/magicfatigue.h"
#include "./concrete_enchantments/silence.h"

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