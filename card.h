#ifndef CARD_H
#define CARD_H
#include <string>
#include <fstream>

using namespace std;

class Card { 
	protected:
		string name, type, description;
		int cost;
	public:
		explicit Card(string, string, string, int);
		virtual ~Card();
		string getName() const;
		string getType() const;
		string getDescription() const;
		int getCost() const;
		virtual bool activate(Card *t = nullptr) = 0; // activates spell/ritual/enchantment/minion's ability
};

#endif
