#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include "player.h"
#include "ascii_graphics.h"

class Spell: public Card {
    public:
        explicit Spell(string name, string description, int cost);
        card_template_t display() const override;
};

#endif
