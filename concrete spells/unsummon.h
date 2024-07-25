#ifndef UNSUMMON_H
#define UNSUMMON_H

#include "../spell.h"
#include <iostream>

class Unsummon: public Spell {
    public:
        Unsummon(): Spell{"Unsummon", "Return target minion to its owner’s hand", 1} {}
        bool activate(Player *owner, Player *enemy, int t) {
            if (enemy->getHand().size() == 5) {
                std::cout << "Players hand is full, cannot unsummon its minion." << std::endl;
                return false;
            }
            Card* target = enemy->removeSummonedMinion(t - 1);
            enemy->addToHand(target);
            return true;
        }
};

#endif