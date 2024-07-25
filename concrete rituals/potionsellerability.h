#ifndef POTIONSELLERABILITY_H
#define POTIONSELLERABILITY_H

#include "../ritual.h"
#include "../concrete minions/changestat.h"

class PotionSellerAbility: public Ritual {
    public: 
        explicit PotionSellerAbility(Player *owner):
            Ritual{"PotionSellerAbility", "At the end of your turn, all your minions gain +0/+1", 0, 1, 0, owner} {}
        
        ~PotionSellerAbility() { owner->detachAfterTurn(this); }

        void notify() override {
            int size = owner->getSummoned().size();
            for (int i = 0; i < size; i++) {
                Minion* m = owner->removeSummonedMinion(0);
                m = new ChangeStat{m, "0", "+1", 0, 0, false, false};
                owner->addToSummoned(m);
            }
        }

        void attach() override {
            owner->detachAfterTurn(this);
        }
};

#endif