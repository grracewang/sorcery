#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card { 
	private:
		string name, type, description;
		int cost;
		// bool hasTarget;
	public:
		explicit Card(string, string, string, int);
		string getName() const;
		string getType() const;
		string getDescription() const;
		int getCost() const;
		virtual void activate() = 0; // activates spell/ritual/enchantment/minion's ability
};

#endif
