#ifndef SILENCE_H
#define SILENCE_H

#include <iostream>
#include "../enchantment.h"
#include "../concrete minions/changestat.h"

using namespace std;

class Silence: public Enchantment {
    Player* target;
    Player* other;
    Minion* minion;
    public:
        explicit Silence(Player* target, Player* other): Enchantment{"Silence", "Enchanted minion cannot use abilities", 1}, target{target}, other{other} {}
        ~Silence() {
            while (minion->getMinion()) {
                minion = minion->getMinion();
            }
            minion->addAbility(target, other); // adds back onto opponents observers
            target = nullptr;
            other = nullptr;
            minion = nullptr;
        }
        Minion *activate(Minion *t) override {
            minion = new ChangeStat{t, getAtkStr(), getDefStr(), 0, 0, true, this};
            return minion;
        }
};

#endif