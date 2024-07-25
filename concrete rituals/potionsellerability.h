#ifndef POTIONSELLERABILITY_H
#define POTIONSELLERABILITY_H

#include "../ritual.h"
#include "../concrete minions/changestat.h"
#include <vector>
#include <string>

class PotionSellerAbility: public Ritual {
    public: 
        explicit PotionSellerAbility(Player *owner):
            Ritual{"PotionSellerAbility", "At the end of your turn, all your minions gain +0/+1", 0, 1, 0, owner} {}
        
        ~PotionSellerAbility() { owner->detachAfterTurn(this); }

        void notify() override {
            int size = owner->getSummoned().size();
            for (int i = 0; i < size; i++) {
                Minion* m = owner->getSummoned(i);
                owner->replaceMinion(i, new ChangeStat{m, "0", "+1", 0, 0, false, nullptr});
            }
        }

        void attach() override {
            owner->detachAfterTurn(this);
        }
};

#endif
