#ifndef DARKRITUAL_H
#define DARKRITUAL_H

#include "ritual.h"

class DarkRitual: public Ritual {
    public:
        explicit DarkRitual(Player *owner): Ritual{"Dark Ritual", "darkritual.txt", 0, 5, 1, owner} {}
        bool activate(Card *t) override {}
        void notify() override {}
};

#endif