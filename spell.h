#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include "player.h"

class Spell: public Card {
    public:
        explicit Spell(string name, string description, int cost): Card{name, "Spell", description, cost} {}
};

#endif