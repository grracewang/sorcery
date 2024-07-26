#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include "player.h"
#include "ascii_graphics.h"

class Spell: public Card {
    public:
        Spell(string name, string description, int cost);
        // if called with play i p t: (target, other, t)
        // if called with play i: (owner, enemy, t)
        virtual bool activate(Player*, Player*, size_t t) = 0;
        card_template_t display() const override;
        virtual ~Spell();
};

#endif
