#ifndef RITUAL_H
#define RITUAL_H
#include "card.h"
#include "player.h"
#include "ascii_graphics.h"

class Ritual: public Card {
    protected:  
        int charges, activationCost;
        Player *owner;
    public:
        explicit Ritual(string, string, int, int, int, Player *);
        virtual void notify() = 0;
        int getCharges() const;
        int getActivationCost() const;

        card_template_t display() const override;
};

#endif
