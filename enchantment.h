#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include "card.h"
#include "minion.h"
#include "ascii_graphics.h"

class Enchantment: public Card {
    private:
        const string atkStr, defStr;
    public:
        Enchantment(string name, string description, int cost, string atkStr = "", string defStr = "");
        string getAtkStr() const;
        string getDefStr() const;
        
        card_template_t display() const override;
};

#endif
