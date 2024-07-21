#ifndef CARD_H
#define CARD_H
#include <string>
#include <fstream>
using namespace std;

class Card { 
	private:
		string name, type, filename;
		int cost;
	public:
		explicit Card(string, string, string, int);
		string getName() const;
		string getType() const;
		string getFilename() const;
		int getCost() const;
		virtual bool activate(Player *p = nullptr, Card *t = nullptr) = 0; // activates spell/ritual/enchantment/minion's ability
};

#endif
