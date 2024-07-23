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
                Minion* temp = owner->getSummoned()[t]; // 
                owner->getSummoned().erase(owner->getSummoned().begin() + t);
                delete temp;
                temp = nullptr;
            }
        }
};

#endif