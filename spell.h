#ifndef SPELL_H
#define SPELL_H

#include "card.h"
#include "player.h"
#include "ascii_graphics.h"

class Spell: public Card {
    public:
        Spell(string name, string description, int cost);
        virtual bool activate(Player* owner, Player* enemy, int t) = 0;
        card_template_t display() const override;
};

#endif
