#ifndef RECHARGE_H
#define RECHARGE_H

#include "../spell.h"
#include "../ritual.h"
#include <iostream>

class Recharge: public Spell {
    public:
        Recharge(): Spell{"Recharge", "Your ritual gains 3 charges", 1} {}
        bool activate(Player *owner, Player *enemy, size_t t) override {
            if (!owner->getRitual()) {
                std::cout << "You have no ritual." << std::endl;
                return false;
            }
            Ritual *r = owner->getRitual();
            r->changeCharges(3);
            owner->setRitual(r);
            return true;
        }
};

#endif
