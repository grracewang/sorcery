#ifndef FIRELEMENTAL_H
#define FIRELEMENTAL_H
#include "../minion.h"
#include "../spell.h"
#include <vector>
#include <string>
using namespace std;

class FireElemental : public Minion {
    public:
         // normal getters (not changed by decorators)
		string getName() const override;
		string getType() const override;
		string getDescription() const override;
		int getCost() const override;

		// getters changed by decorators
        int getAtk() const override;
		int getDef() const override;
		int getBeginActions() const override;
        int getActCost() const override;
		void addAbility(Player*, Player*) override;
		vector<Spell*> getSpells() const override;
};

#endif
