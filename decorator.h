#ifndef DECORATOR_H
#define DECORATOR_H

#include "minion.h"

class Decorator: public Minion {
    protected:
        Minion *target;
        char op; // operator for changing stats for minion: can be '*' or '+'
    public:
        Decorator(Minion *target, char op): Minion{target->getName(), target->getType(), target->get
        virtual ~Decorator();
};

#endif