#ifndef EARTHELEMENTAL_H
#define EARTHELEMENTAL_H

#include "../minion.h"
#include "../player.h"
#include "../spell.h"
#include <string>
#include <vector>
using namespace std;

class EarthElemental : public Minion {
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
		void addAbility(Player* owner, Player *opponent) override;
		vector<Spell*> getSpells() const override;
};

#endif
