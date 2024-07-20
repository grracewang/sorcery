#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <card.h>
#include <minion.h>
#include <spell.h>
#include <ritual.h>

class Enchantment: public Card {
    private:
        Minion *minion;
    public:
        explicit Enchantment(Minion*);
        virtual ~Enchantment();
        virtual void notify() = 0;
};

#endif