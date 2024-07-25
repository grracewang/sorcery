#include "../minion.h"
#include "changestat.h"
#include "../ritual.h"
class FireElemental : public Minion {
    <Ritual*> abilities;
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
		void addAbility(Player*) override; // called when bone golem is summoned
		vector<Spell*> getSpells() const override;
		// vector<Ritual*> getRituals() const override;
};