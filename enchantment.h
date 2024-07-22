#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include "card.h"
#include "minion.h"

class Enchantment: public Card {
    private:
        const string atkStr, defStr;
    public:
        Enchantment(string name, string description, int cost, string atkStr = "", string defStr = ""): 
            Card{name, "Enchantment", description, cost}, atkStr{atkStr}, defStr{defStr} {}
        string getAtkStr() const { return atkStr; }
        string getDefStr() const { return defStr; }
};

#endif