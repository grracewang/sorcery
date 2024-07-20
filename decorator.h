#ifndef DECORATOR_H
#define DECORATOR_H

#include "minion.h"

class Decorator: public Minion {
    protected:
        Minion *minion;
        char op; // operator for changing stats for minion: can be '*' or '+'
    public:
        Decorator(Minion *);
        virtual ~Decorator();
};

#endif