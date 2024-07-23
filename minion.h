#ifndef MINION_H
#define MINION_H

#include "enchantment.h"
#include "card.h"
#include "spell.h"
#include "ritual.h"
#include "ascii_graphics.h"
#include <string>

using namespace std;

class Minion: public Card {
	protected: 
		bool actions = 1;
		vector<Spell*> spells;
		vector<Ritual*> rituals;
		vector<Enchantment*> enchantments; // enchantments that are casted on this Minion

	public:
		explicit Minion(string, string, string, int); 
		virtual ~Minion() = default;
		virtual int getAtk() const = 0;
		virtual int getDef() const = 0;
		virtual int getCost() const = 0;
		// void attack(Player *);
		bool getActions() const;
		void setActions(bool);
		string getDescription() const;
		vector<Spell*> getSpells() const;
		vector<Ritual*> getRituals() const;
		card_template_t display() const override;
};

#endif
