#ifndef RITUAL_H
#define RITUAL_H
#include "card.h"
#include "ascii_graphics.h"

class Player;

class Ritual: public Card {
    protected:
		int charges, activationCost;
        Player *owner;
    public:
        explicit Ritual(string, string, int, int, int, Player *);
        virtual ~Ritual();
        virtual void notify() = 0;
        virtual void attach() = 0;
        int getCharges() const;
        int getActivationCost() const;
        void changeCharges(int i);
        card_template_t display() const override;
};

#endif
