#ifndef MINION_H
#define MINION_H
#include "card.h"
#include "spell.h"
#include "ritual.h"
#include "./concrete minions/changestat.h"
#include "ascii_graphics.h"
#include <string>
using namespace std;

class Player; // forward declaration

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
		virtual int getBeginActions() const = 0; // action points minion gets at turn start
		virtual int getActCost() const = 0; // cost of using activated ability (spell cost)
											// returns -1 if called on a minion without an
											// activated ability
		virtual vector<Spell*> getSpells() const = 0;
		virtual vector<Ritual*> getRituals() const = 0;

		// functions to manage the action of a minion
		void resetAction(); // call at start of turn
		bool useAction(); // call before using a minion
									  // to do something requiring actions
									  // if return is false, you can't continue
									  // to do that action

		// for removing enchantments
		Minion *removeEnchantments();
		Minion *removeTopEnchantment();

		// minion attack
		Minion *attack(Minion *enemy); // format in main: enemy = m.attack(enemy);
		void attack(Player *enemy); // still need to implement

		// for printing
		card_template_t display() const override;

		virtual ~Minion();
};

#endif
