#ifndef SILENCE_H
#define SILENCE_H

#include <iostream>
#include <string>
#include "../enchantment.h"
#include "../concrete_minions/changestat.h"

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
            if (t->getDescription() != "" && !t->getSpells().empty()) {
                t->removeAbilities();
                minion = new ChangeStat{t, getAtkStr(), getDefStr(), 0, 0, true, this}; 
            } else {
                cout << "Minion has no ability to use this enchantment on." << endl;
            }
            return minion;
        }
};

#endif
