#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H

#include <string>
#include "card.h"
#include "minion.h"
#include "spell.h"
#include "ritual.h"

class Enchantment: public Card {
    private:
        string atkStr, defStr;
    public:
        Enchantment(string name, string filename, int cost, string atkStr, string defStr): 
            Card{name, "Enchantment", filename, cost}, atkStr{atkStr}, defStr{defStr} {}
        string getAtkStr() { return atkStr; }
        string getDefStr() { return defStr; }
};

#endif