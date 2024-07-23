#ifndef RECHARGE_H
#define RECHARGE_H

#include "../spell.h"

class Recharge: public Spell {
    public:
        explicit Recharge(): Spell{"Recharge", "recharge.txt", 1} {}
        void activate(Player *target) {
            Ritual* card = dynamic_cast<Ritual*>(target->getRitual());
            card->changeCharges(3);
        }
};

#endif
