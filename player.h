#ifndef PLAYER_H
#define PLAYER_H
#include "subject.h"
#include "card.h"
#include "minion.h"
#include <vector>
#include <stack>
#include <string>
#include "ascii_graphics.h"

using namespace std;

class Player : public Subject{
	private: 
		string name;
		int life = 20, magic = 3; // life is 20, magic is 3, using cards cost magic
		Card* ritual; // currently played ritual, nullptr if no ritual
		
		vector<Card*> hand; // vector of 5 cards MAX
		vector<Card*> deck;
		vector<Minion*> summoned; // minions that have been played
		stack<Minion*> graveyard;
		bool playing; // switch it whenever we play
	public:
		static inline const int MAX_SUMMONED = 5;
        explicit Player(string name);
		virtual ~Player();

		// accessor and mutators
		string getName() const;

		void changeMagic(int newMagic);
		void changeLife(int newLife);
		int getLife() const;
		int getMagic() const;
		
		Card* getRitual() const;
		void removeRitual();

		
		vector<Card*> getDeck() const;
		vector<Card*> getHand() const;
		vector<Minion*> getSummoned() const;
		stack<Minion*> getGraveyard() const; // returns top value 

		Card* getHandCard(int i) const;
		Card* removeHandCard(int i);
		Minion* getSummonedMinion(int i) const;
		Minion* removeSummonedMinion(int i);
		
		// other method
		Minion* revive(); // returns top of stack and pops it
		bool fullHand(); // checks if hand is full
		void draw(); // transfers deck card to hand iff fullHand = false



		void placeMinion(int i); // places hand card to board
		void placeRitual(int i); // swaps ritual

		void addToDeck(Card*);
		void addToHand(Card*);
		void addToSummoned(Minion*);

	
		bool playCard(int i, Player* target, char t);
		void discard(int i); // discards i-th card, doesn't move to graveyard, just trashes it
		void moveToGraveyard(int i);
		// void remove(int i); // removes ith element from hand

		//observer pattern methods

		bool isPlaying(); // aka getState

		// printing
		card_template_t display(int player_num) const;
		
};

#endif
