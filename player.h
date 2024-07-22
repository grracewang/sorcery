#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Player {
	private: 
		string name;
		int life = 20, magic = 3; // life is 20, magic is 3, using cards cost magic
		Card* ritual; // currently played ritual, nullptr if no ritual
		
		vector<Card*> hand; // vector of 5 cards MAX
		vector<Card*> deck;
		vector<Card*> minions; // minions that have been played
		stack<Card*> graveyard;
		
		//observer pattern fields
		vector<Card*> preTurn;
		vector<Card*> afterTurn;
		vector<Card*> minionEnter;
		vector<Card*> minionLeave;
		
	public:
        explicit Player(string name);
		virtual ~Player();
		// accessor and mutators
		void changeMagic(int newMagic);
		void changeLife(int newLife);
		void changeRitual(Card *ritual);
		int getLife() const;
		int getMagic() const;
		Card *getRitual() const;
		string getName() const;
		vector<Card*>& getDeck();
		vector<Card*> getHand() const;
		vector<Card*> getMinions() const;
		stack<Card*> getGraveyard() const;
		

		// other method
		Card* revive(); // returns top of stack
		bool fullHand(); // draw another card if non full hand
		void draw(); // transfers deck card to hand iff fullHand = false
		void placeCard(int i); // places hand card to board
		void addToDeck(Card*);
		bool playCard(int i, Player* curr, Player* target); // places down the i-th card in hand
		bool playCard(int i, Player* target, char t);
		void discard(int i); // discards i-th card, doesn't move to graveyard, just trashes it
		// void remove(int i); // removes ith element from hand

		//observer pattern methods
		void notifyCards(vector<Card*>) const;
		void attach(Card*);
		void detach(Card*);
		
};

#endif
