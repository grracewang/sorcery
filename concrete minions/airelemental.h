#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H
#include "../minion.h"
#include <string>
using namespace std;

class AirElemental : public Minion {
        int actions = 0;

    public:
        // normal getters (not changed by decorators)
		string getName() const override;
		string getType() const override;
		string getDescription() const override;
		int getCost() const override;
        int getAction() const override;

		// getters changed by decorators
        int getAtk() const override;
		int getDef() const override;
		int getBeginActions() const override;
        int getActCost() const override;
		vector<Spell*> getSpells() const override;
		vector<Ritual*> getRituals() const override;
};

#endif
