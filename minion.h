#ifndef MINION_H
#define MINION_H

#include <string>
#include <card.h>
#include <enchantment.h>
#include <spell.h>
#include <ritual.h>
#include <vector>
#include <player.h>
using namespace std;


class Minion: public Card {
	private: 
		bool actions = 1;
		int atk, def;
		vector<Enchantment*> enchantments; // enchantments that are casted on this Minion

	public:
		explicit Minion(int, int);
		virtual ~Minion();
		void atkPlayer(Player*);
		Minion *atkMinion(Minion*);
		virtual int getAtk();
		virtual int getDef();
		virtual bool getActions();
};

#endif