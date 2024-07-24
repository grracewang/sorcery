#ifndef AIRELEMENTAL_H
#define AIRELEMENTAL_H
#include "../minion.h"
#include <string>
using namespace std;

class AirElemental : public Minion {
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

		// functions to manage the action of a minion
		void resetAction() override;
		bool useAction() override;
};

#endif
