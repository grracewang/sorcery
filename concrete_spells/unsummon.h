#ifndef UNSUMMON_H
#define UNSUMMON_H
#include "../spell.h"
#include <iostream>
#include <string>

class Unsummon: public Spell {
    public:
        Unsummon(): Spell{"Unsummon", "Return target minion to its owner’s hand ", 1} {}
        bool activate(Player *target, Player *other, size_t t) override {
            // target's hand is full
            if (target->getHand().size() >= 5) {
                std::cout << "Players hand is full, cannot unsummon its minion." << std::endl;
                return false;
            }
            t -= 49;
            if (t >= 0 && t < target->getSummoned().size()) {
                Minion *targetMinion = target->removeSummonedMinion(t);
                target->addToHand(Minion::removeEnchantments(targetMinion));
                return true;
            }

            // ~no minoin at this index or attempted to play unsummon on a ritual
            cout << "You cannot unsummon this card. Try another command." << endl;
            return false;
        }
};

#endif
