#include "../minion.h"
#include "changestat.h"
#include "airelemental.h"

class MasterSummoner : public Minion {
    public:
        // MasterSummoner(): Minion{"Master Summoner", "Minion", "Summon up to three 1/1 air elementals", 3} {};
        // void activate(Player *p) {
        //     for (int i = 0; i < 3; ++i) {
        //         if (p->getSummoned().size() < p->MAX_SUMMONED) p->addToSummoned(new AirElemental);
        //     }
        // }
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
		void addAbility(Player*, Player*) override;
		vector<Spell*> getSpells() const override;
};