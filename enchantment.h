#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include "card.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"

class Enchantment: public Card {
    private:
        Minion *target;
    public:
        Enchantment(string name, string filename, int cost): Card{name, "Enchantment", filename, cost}, target{nullptr} {}
        virtual ~Enchantment() { delete target; };
        Minion *getTarget() { return target; }
};

#endif