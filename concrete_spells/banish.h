#ifndef BANISH_H
#define BANISH_H
#include "../spell.h"
#include <iostream>
#include <string>

class Banish: public Spell {
    public:
        Banish(): Spell{"Banish", "Destroy target minion or ritual", 2} {}
        bool activate(Player *target, Player *other, size_t t) override {
            if (t == 114) {
                if (!target->getRitual()) {
                    std::cout << "Target player has no ritual to destroy." << std::endl;
                    return false;
                }
                target->setRitual(nullptr); // also detaches ritual from owner
            } else {
                t -= 49;
                if (target->getSummoned().size() < t) {
                    std::cout << "This minion does not exist." << std::endl;
                    return false;
                }
                Minion* temp = target->removeSummonedMinion(t - 1);
                delete temp;
                temp = nullptr;
            }
            return true;
        }
};

#endif