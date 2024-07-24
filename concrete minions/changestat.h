#ifndef CHANGESTAT_H
#define CHANGESTAT_H
#include "decorator.h"
#include "../minion.h"
using namespace std;

class ChangeStat: public Decorator {
        // initialization information it needs for functions
        string atkStr, defStr;
        int actionInc, actCostInc;
        bool blockAbilities, enchantment;

    public:
        ChangeStat(Minion *target, string atkStr, string defStr, int actionInc,
                   int actCostInc, bool blockAbilities, bool enchantment);

        // normal getters (not changed by decorators)
		virtual string getName() const override;
		virtual string getType() const override;
		virtual string getDescription() const override;
		virtual int getCost() const = 0;
		virtual int getAction() const = 0;

        // getters changed by decorators
		int getAtk() const override;
		int getDef() const override;
        int getBeginActions() const override;
        int getActCost() const override;
		vector<Spell*> getSpells() const override;
		vector<Ritual*> getRituals() const override;

        // functions to manage the action of a minion
		void resetAction() override; // call at start of turn
		bool useAction() override; // call when use an action
};

#endif
