#ifndef MINION_H
#define MINION_H
#include "card.h"
#include "spell.h"
#include "ritual.h"
#include "ascii_graphics.h"
#include <string>

using namespace std;

class Minion: public Card {
	protected:
        int actions = 0;

	public:
		// normal getters (not changed by decorators)
		virtual string getName() const = 0;
		virtual string getType() const = 0;
		virtual string getDescription() const = 0;
		virtual int getCost() const = 0;
		virtual int getAction() const = 0;
		

		// getters changed by decorators (in ChangeStat)
		virtual int getAtk() const = 0;
		virtual int getDef() const = 0;
		virtual int getBeginActions() const = 0;
		virtual int getActCost() const = 0;
		virtual vector<Spell*> getSpells() const = 0;
		virtual vector<Ritual*> getRituals() const = 0;

		// functions to manage the action of a minion
		virtual void resetAction() = 0; // call at start of turn
		virtual bool useAction() = 0; // call before using a minion
									  // to do something requiring actions
									  // if return is false, you can't continue
									  // to do that action

		// for removing enchantments
		virtual Minion* removeEnchantments();
		Minion* removeTopEnchantment();

		// minion attack


		// for printing
		card_template_t display() const override;

		virtual ~Minion();
};

#endif
