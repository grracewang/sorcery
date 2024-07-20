#ifndef MINION_H
#define MINION_H

#include <string>
<<<<<<< HEAD:minion.h
#include <card.h>
#include <enchantment.h>
#include <spell.h>
#include <ritual.h>
#include <vector>
#include <player.h>
=======
#include "card.h"
#include "enchantment.h"
#include "spell.h"
#include "ritual.h"
#include "player.h"

>>>>>>> 497125d (Update minions):card/minion/minion.h
using namespace std;


class Minion: public Card {
	private: 
		bool actions = 1;
		int atk, def;
		vector<Enchantment*> enchantments; // enchantments that are casted on this Minion

	public:
<<<<<<< HEAD:minion.h
		explicit Minion(int, int);
		virtual ~Minion();
=======
		Minion(int, int);
		~Minion();
>>>>>>> 497125d (Update minions):card/minion/minion.h
		void atkPlayer(Player*);
		Minion *atkMinion(Minion*);
		virtual int getAtk();
		virtual int getDef();
		virtual bool getActions();
};

#endif