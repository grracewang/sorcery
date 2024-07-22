#ifndef RITUAL_H
#define RITUAL_H
#include "card.h"
#include "player.h"




class Ritual: public Card {
    private:  
        int charges, activationCost;
        Player *owner;
    public:
        explicit Ritual(string, string, int, int, int, Player *);
        virtual void notify() = 0;
        int getCharges() const;
        int getActivationCost() const;
};

#endif