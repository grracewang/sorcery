#ifndef MINION_H
#define MINION_H

#include <string>
#include <card.h>
#include <enchantment.h>
#include <spell.h>
#include <ritual.h>
using namespace std;


class Minion: public Card {
	private: 
		bool actions;
		int atk, def;
		vector<Enchantment*> enchantments // enchantments that are casted on this Minion

		// minion abilities
		vector<Spell*> spells;
		vector<Ritual*> rituals;

	public:
		
		void atkPlayer(Player*);
		Minion *atkMinion(Minion*);
		virtual int getAtk();
		virtual int getDef();
		virtual bool getActions();
};

#endif