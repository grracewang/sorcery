#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "card/minion/ritual.h"
#include "card/minion/minion.h"
#include "card/minion/spell.h"
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Player {
	private: 
		string name;
		int life = 20, magic = 3; // life is 20, magic is 3, using cards cost magic
		Ritual* ritual; // currently played ritual, nullptr if no ritual
		
		vector<Card*> hand; // vector of 5 cards MAX
		vector<Card*> deck;
		vector<Minion*> minions; // minions that have been played
		stack<Minion*> graveyard;
		
		//observer pattern fields
		vector<Ritual*> preTurn;
		vector<Ritual*> afterTurn;
		vector<Ritual*> minionEnter;
		vector<Ritual*> minionLeave;
		
	public:
        explicit Player(string name);

		// accessor and mutators
		void changeMagic(int newMagic);
		void changeLife(int newLife);
		int getLife() const;
		int getMagic() const;
		string getName() const;
		vector<Card*> getHand() const;
		vector<Minion*> getMinions() const;

		// other method
		Minion* revive(); // returns top of stack
		bool fullHand(); // draw another card if non full hand
		void draw(); // transfers deck card to hand iff fullHand = false
		
		//observer pattern methods
		void notifyCards(vector<Card*>) const;
		void attach(Card*);
		void detach(Card*);
		
};

#endif
