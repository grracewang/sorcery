#ifndef BANISH_H
#define BANISH_H

#include "../spell.h"
using namespace std;

class Banish: public Spell {
    public:
        explicit Banish(): Spell{"Banish", "Destroy target minion or ritual", 2} {}
        void activate(Player *owner, char t) {
            if (t == 'r') {
                owner->removeRitual();
            } else {
                Minion* temp = owner->getSummoned()[t - 1]; // 
                owner->getSummoned().erase(owner->getSummoned().begin() + t - 1);
                delete temp;
                temp = nullptr;
            }
        }
};

#endif