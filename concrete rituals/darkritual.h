#ifndef DARKRITUAL_H
#define DARKRITUAL_H

#include "../ritual.h"

class DarkRitual: public Ritual {
    public:
        explicit DarkRitual(Player *owner): Ritual{"Dark Ritual", "At the start of your turn, gain 1 magic", 0, 5, 1, owner} {}
        bool activate(Card *t) override {}
        void notify() override {}
};

#endif