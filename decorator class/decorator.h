#ifndef DECORATOR_H
#define DECORATOR_H

#include "minion.h"

class Decorator: public Minion {
    protected:
        Minion *target;
    public:
        Decorator(Minion *target): 
            Minion{target->getName(), target->getType(), target->getDescription(), target->getCost()}, target{target} {}
        virtual ~Decorator();
};

#endif