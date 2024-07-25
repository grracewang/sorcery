#ifndef POTIONSELLER_H
#define POTIONSELLER_H
#include "../minion.h"
#include "../ritual.h"

class PotionSeller : public Minion {
	vector<Ritual*> abilities;
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
		void addAbility(Player *owner, Player *opponent) override;
		vector<Spell*> getSpells() const override;
		// vector<Ritual*> getRituals() const override;
};

#endif
