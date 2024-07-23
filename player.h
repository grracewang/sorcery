#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
#include "minion.h"
#include <vector>
#include <stack>
#include <string>
#include "ascii_graphics.h"

using namespace std;

class Player {
	private: 
		string name;
		int life = 20, magic = 3; // life is 20, magic is 3, using cards cost magic
		Card* ritual; // currently played ritual, nullptr if no ritual
		
		vector<Card*> hand; // vector of 5 cards MAX
		vector<Card*> deck;
		vector<Minion*> summoned; // minions that have been played
		stack<Minion*> graveyard;
		
		//observer pattern fields
		vector<Card*> preTurn;
		vector<Card*> afterTurn;
		vector<Card*> minionEnter;
		vector<Card*> minionLeave;
		
	public:
		static inline const int MAX_SUMMONED = 5;
        explicit Player(string name);
		virtual ~Player();

		// accessor and mutators
		void changeMagic(int newMagic);
		void changeLife(int newLife);
		void removeRitual();
		int getLife() const;
		int getMagic() const;
		Card* getRitual() const;
		string getName() const;
		vector<Card*> getDeck() const;
		vector<Card*> getHand() const;
		vector<Minion*> getSummoned() const;
		stack<Minion*> getGraveyard() const; // returns top value 
		Card* getHandCard(int i) const;
		Minion* getSummonedMinion(int i) const;
		Card* removeHandCard(int i);
		Minion* removeSummonedMinion(int i);

		// other method
		Minion* revive(); // returns top of stack and pops it
		bool fullHand(); // draw another card if non full hand
		void draw(); // transfers deck card to hand iff fullHand = false
		void placeMinion(int i); // places hand card to board
		void placeRitual(int i); // swaps ritual
		void addToDeck(Card*);
		void addToHand(Card*);
		void addToSummoned(Minion*);
		bool playCard(int i); // places down the i-th card in hand
		bool playCard(int i, Player* target, char t);
		void discard(int i); // discards i-th card, doesn't move to graveyard, just trashes it
		void moveToGraveyard(int i);
		// void remove(int i); // removes ith element from hand

		//observer pattern methods
		void notifyCards(vector<Card*>) const;
		void attach(Card*);
		void detach(Card*);

		// printing
		card_template_t display(int player_num) const;
		
};

#endif
