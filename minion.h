#ifndef MINION_H
#define MINION_H

#include <string>
#include "card.h"
#include "enchantment.h"
#include "spell.h"
#include "ritual.h"
#include "player.h"

using namespace std;


class Minion: public Card {
	private: 
		bool actions = 1;
		int atk, def;
		vector<Spell*> spells;
		vector<Ritual*> rituals;
		vector<Enchantment*> enchantments; // enchantments that are casted on this Minion

	public:
		explicit Minion(string, string, string, int, int, int); 
		virtual ~Minion();
		~Minion();
		void atkPlayer(Player*);
		Minion *atkMinion(Minion*);
		virtual int getAtk();
		virtual int getDef();
		virtual bool getActions();
};

#endif