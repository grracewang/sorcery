#ifndef RITUAL_H
#define RITUAL_H

#include "card.h"
#include "player.h"


class Ritual: public Card {
    private:  
        int charges, activationCost;
        Player *owner; // the player that owns this ritual card
    public:
        explicit Ritual(string, string, int, int, int, Player *);
        virtual ~Ritual();
        virtual void notify() = 0;
        int getCharges() const;
        int getActivationCost() const;
};

#endif