#ifndef NOVICEPYROMANCER_H
#define NOVICEPYROMANCER_H
#include "../minion.h"

class NovicePyromancer : public Minion {
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
		void addAbility(Player* owner, Player *opponent) override;
		vector<Spell*> getSpells() const override;
		// vector<Ritual*> getRituals() const override;
};

#endif
