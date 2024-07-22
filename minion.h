#ifndef MINION_H
#define MINION_H
#include "player.h"
#include "enchantment.h"

#include "card.h"
#include "spell.h"
#include "ritual.h"
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
		virtual ~Minion();
		// ~Minion();
		void atkPlayer(Player*);
		Minion *atkMinion(Minion*);
		virtual int getAtk() const = 0;
		virtual int getDef() const = 0;
		virtual bool getActions() const;
		string getDescription() const;
		vector<Spell*> getSpells() const;
		vector<Ritual*> getRituals() const;
};

#endif
