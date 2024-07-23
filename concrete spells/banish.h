#ifndef BANISH_H
#define BANISH_H

#include "../spell.h"
using namespace std;

class Banish: public Spell {
    public:
        explicit Banish(): Spell{"Banish", "banish.txt", 2} {}
        void activate(Player *owner, char t) {
            if (t == 'r') {
                owner->removeRitual();
            } else {
                owner->getSummoned(); // 
                delete target;
            }
        }
};

#endif