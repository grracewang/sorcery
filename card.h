#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card { 
	private:
		string name, type, description;
		int cost;
		bool hasTarget;
	public:
		string getName() const;
		string getType() const;
		string getDescription() const;
		int getCost() const;
		bool hasTarget() const;
		
		virtual void activate() = 0;
		//void printCard();
};

#endif
