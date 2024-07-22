#include "../minion.h"
#include "changestat.h"
#include <iostream>
class NovicePyromancer : public Minion {
    public:
        NovicePyromancer(): Minion{"Novice Pyromancer", "Minion", "Deal 1 damage to target minion", 2} {};
        bool attack(Minion *target) override {
            if (target) {
                target = new ChangeStat{target, '+', 0, 0, 0};
                return true;
            } else {
                std::cerr << "You must provide a target." << std::endl;
                return false;
            }
        }
        bool activate(Card *t) override { return true; }
        int getAtk() const override { return 0; }
        int getDef() const override { return 1; }
        int getCost() const override { return 1; }// change to spell.cost()
};