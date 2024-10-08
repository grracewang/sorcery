#ifndef DARKRITUAL_H
#define DARKRITUAL_H

#include "../ritual.h"
#include <string>

class DarkRitual: public Ritual {
    public:
        explicit DarkRitual(Player *owner): Ritual{"Dark Ritual", "At the start of your turn, gain 1 magic", 0, 5, 1, owner} {}
        
        ~DarkRitual() {
            owner->detachPreTurn(this);
        }
        void notify() override {
            charges -= activationCost;
            if (charges < 0) {
                owner->setRitual(nullptr);
            } else {
                owner->changeMagic(1);
            }
        }

        
        void attach() override {
            owner->attachPreTurn(this);
        }
};

#endif
