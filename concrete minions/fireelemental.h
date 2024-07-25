#include "../minion.h"
#include "changestat.h"

class FireElemental : public Minion {
    public:
        FireElemental(): 
            Minion{"Fire Elemental", "Minion", "Whenever an opponent's minion enters play, deal 1 damage to it", 2} {};
        void activate(Card *t) {};
        int getAtk() const override { return 2; }
        int getDef() const override { return 2; }
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