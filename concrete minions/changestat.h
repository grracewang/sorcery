#ifndef CHANGESTAT_H
#define CHANGESTAT_H
#include "decorator.h"
#include "../minion.h"
using namespace std;

// class Minion; // forward declaration

class ChangeStat: public Decorator {
        // initialization information it needs for functions
        string atkStr; // amount a minion's attack changes (ex. "*2")
        string defStr; // amount a minion's defence changes (ex. "-2")
        int actionInc; // amount a minion's beginning actions increase by
        int actCostInc; // amount a minion's spell's cost increases by
                        // in getActCost(), not the actual spell that changes
        bool blockAbilities; // whether a minion can use its abilities
        bool enchantment; // whether a ChangeStat came from an enchantment

    public:
        ChangeStat(Minion *target, string atkStr, string defStr, int actionInc,
                   int actCostInc, bool blockAbilities, bool enchantment);

        // normal getters (not changed by decorators)
		string getName() const override;
		string getType() const override;
		int getCost() const override;
        bool isEnchantment() const override;

        // getters changed by decorators
		int getAtk() const override;
		int getDef() const override;
        int getBeginActions() const override;
        int getActCost() const override;
		vector<Spell*> getSpells() const override;
		vector<Ritual*> getRituals() const override;
        Minion *getMinion() const override;
        void setMinion(const Minion *) override;

        // helper function for creating atkStr and defStr
        static string toString(char op, int val);

        void addAbility(Player* owner, Player *opponent) override;
};

#endif
