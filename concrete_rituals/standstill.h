#ifndef STANDSTILL_H
#define STANDSTILL_H

#include "../ritual.h"
#include "../minion.h"

class Standstill: public Ritual {
    private:
        Player *opponent;
    public:
        explicit Standstill(Player *owner, Player* opponent): 
            Ritual{"Standstill", "Whenever a minion enters play, destroy it", 3, 4, 2, owner}, opponent{opponent} {}

        ~Standstill() {
            owner->detachMinionEnter(this);
            opponent->detachMinionEnter(this);
            // need to detach it for opponent as well
        }
        
        void notify() override {
            charges -= activationCost;
            if (charges < 0) {
                owner->setRitual(nullptr);
            } else {
                if (owner->isPlaying()) {
                    int i = owner->getSummoned().size() - 1;
                    Minion* m = owner->removeSummonedMinion(i);
                    delete m;
                } else {
                    int i = opponent->getSummoned().size() - 1;
                    Minion* m = opponent->removeSummonedMinion(i);
                    delete m;
                }
            }
        }

        void attach() {
            owner->attachMinionEnter(this);
            opponent->attachMinionEnter(this);
        }
};

#endif
