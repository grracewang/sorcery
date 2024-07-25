#ifndef APPRENTICESUMMONER_H
#define APPRENTICESUMMONER_H

#include "../minion.h"
#include "../player.h"
#include "../spell.h"
#include <string>
#include <vector>
using namespace std;

class ApprenticeSummoner : public Minion {
    public:
        // normal getters (not changed by decorators)
		string getName() const override;
		string getType() const override;
		string getDescription() const override;
		int getCost() const override;
        bool isEnchantment() const override;

		// getters changed by decorators
        int getAtk() const override;
		int getDef() const override;
		int getBeginActions() const override;
        int getActCost() const override;
		vector<Spell*> getSpells() const override;
		void addAbility(Player* owner, Player *opponent) override;
};

#endif
