#ifndef PLAYER_H
#define PLAYER_H
#include "subject.h"
#include "card.h"
#include "ritual.h"
#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "ascii_graphics.h"
using namespace std;

class Minion; // Forward declaration

class Player : public Subject{
	private: 
		string name;
		int life = 20, magic = 3; // life is 20, magic is 3, using cards cost magic
		Ritual* ritual; // currently played ritual, nullptr if no ritual
		
		vector<Card*> hand; // vector of 5 cards MAX
		vector<Card*> deck;
		vector<Minion*> summoned; // minions that have been played
		stack<Minion*> graveyard;
		bool playing; // switch it whenever we play
	public:
        explicit Player(string name);
		virtual ~Player();

		// accessor and mutators
		string getName() const;

		void changeMagic(int newMagic);
		void changeLife(int newLife);
		int getLife() const;
		int getMagic() const;
		
		Ritual* getRitual() const;
		void setRitual(Ritual *r); // swaps ritual

		vector<Card*>& getDeck();
		vector<Card*> getHand() const;

		vector<Minion*> getSummoned() const;
		void setSummoned(size_t i, Minion *newMinion); // replaces minion at pos i with newMinion

		stack<Minion*> getGraveyard() const; // returns top value 

		Card* getHandCard(size_t i) const;
		Card* removeHandCard(size_t i);
		Minion* getSummonedMinion(size_t i) const;
		Minion* removeSummonedMinion(size_t i);
		
		// other method
		Minion* revive(); // returns top of stack and pops it
		bool fullHand(); // checks if hand is full
		void draw(); // transfers deck card to hand iff fullHand = false

		void placeMinion(size_t i); // places hand card to board

		void addToDeck(Card*);
		void addToHand(Card*);
		void addToSummoned(Minion*, Player*);

		void discard(size_t i); // discards i-th card, just trashes it, used in testing mode
		void discard(Card*); // takes in a spell
		void moveToGraveyard(size_t i);
		

		//observer pattern methods
		bool isPlaying(); // aka getState
		void changeState(); // change turns

		// prsize_ting
		card_template_t display(size_t player_num) const;
		
};

#endif
