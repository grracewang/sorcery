#ifndef CHANGESTAT_H
#define CHANGESTAT_H
#include "decorator.h"
#include "../minion.h"
using namespace std;

class ChangeStat: public Decorator {
        // initialization information it needs for functions
        string atkStr, defStr;
        int actionInc, actCostInc;
        bool blockAbilities;

    public:
        ChangeStat(Minion *target, string atkStr, string defStr, int actionInc,
                   int actCostInc, bool blockAbilities);
		int getAtk() const override;
		int getDef() const override;
        int getBeginActions() const override;
        int getActCost() const override;
		vector<Spell*> getSpells() const override;
		vector<Ritual*> getRituals() const override;
};

#endif
