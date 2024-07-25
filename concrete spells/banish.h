#ifndef BANISH_H
#define BANISH_H

#include "../spell.h"
#include <iostream>

class Banish: public Spell {
    public:
        Banish(): Spell{"Banish", "Destroy target minion or ritual", 2} {}
        bool activate(Player *owner, Player *enemy, int t) override {
            if (t == 114) {
                if (enemy->getRitual() == nullptr) {
                    std::cout << "Enemy has no ritual to destroy." << std::endl;
                    return false;
                }
                enemy->removeRitual(); // also detaches ritual from owner
            } else {
                if (enemy->getSummoned().size() < t) {
                    std::cout << "This minion does not exist." << std::endl;
                    return false;
                }
                Minion* temp = enemy->removeSummonedMinion(t - 1);
                delete temp;
                temp = nullptr;
            }
            return true;
        }
};

#endif