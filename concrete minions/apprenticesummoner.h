#ifndef APPRENTICESUMMONER_H
#define APPRENTICESUMMONER_H
#include "../minion.h"

class ApprenticeSummoner : public Minion {
    public:
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
};

#endif
