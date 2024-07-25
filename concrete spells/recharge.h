#ifndef RECHARGE_H
#define RECHARGE_H

#include "../spell.h"
#include "../ritual.h"
#include <iostream>

class Recharge: public Spell {
    public:
        Recharge(): Spell{"Recharge", "Your ritual gains 3 charges", 1} {}
        bool activate(Player *owner, Player *enemy, int t) {
            if (owner->getRitual() == nullptr) {
                std::cout << "You have no ritual." << std::endl;
            }
            Ritual* card = owner->getRitual();
            card->changeCharges(3);
            return true;
        }
};

#endif
