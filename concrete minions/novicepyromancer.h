#ifndef NOVICEPYROMANCER_H
#define NOVICEPYROMANCER_H
#include "../minion.h"
#include "../spell.h"
#include <vector>
#include <string>
using namespace std;

class NovicePyromancer : public Minion {
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
