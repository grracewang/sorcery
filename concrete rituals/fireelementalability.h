#ifndef FIREELEMENTALABILITY_H
#define FIREELEMENTALABILITY_H

#include "../ritual.h"
#include "../minion.h"

class FireElementalAbility: public Ritual {
    Player *opponent;
    public:
        explicit FireElementalAbility(Player* owner, Player *opponent):
            Ritual{"Fire Elemental Ability", "Whenever an opponent's minion enters play, deal 1 damage to it", 0, 1, 0, owner},
            opponent{opponent} {}
        
        ~FireElementalAbility() { owner->detachMinionEnter(this); }
        void notify() override { }
}