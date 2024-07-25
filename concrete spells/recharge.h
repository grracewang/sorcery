#ifndef RECHARGE_H
#define RECHARGE_H

#include "../spell.h"
#include "../ritual.h"
#include <iostream>

class Recharge: public Spell {
    public:
        Recharge(): Spell{"Recharge", "Your ritual gains 3 charges", 1} {}
        bool activate(Player *owner, Player *enemy, int t) override {
            if (!owner->getRitual() {
                std::cout << "You have no ritual." << std::endl;
                return false;
            }
            owner->setRitual(getRitual()->changeCharges(3));
            return true;
        }
};

#endif
