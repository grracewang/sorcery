#include "enchantment.h"

Enchantment::Enchantment(string name, string description, int cost, string atkStr = "", string defStr = ""): 
    Card{name, "Enchantment", description, cost}, atkStr{atkStr}, defStr{defStr} {}

// getters (we can remove these if there's no where other than print
//    that needs them since print is a member now)
string Enchantment::getAtkStr() const { return atkStr; }
string Enchantment::getDefStr() const { return defStr; }

// for printing
card_template_t Enchantment::display() const {
    if (atkStr == "" && defStr == "") {
        return display_enchantment(name, cost, description);
    } else {
        return display_enchantment_attack_defence(name, cost, description, atkStr, defStr);
    }
}
