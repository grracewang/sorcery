#ifndef CARD_H
#define CARD_H
#include "ascii_graphics.h"
#include <string>
#include <fstream>

using namespace std;

class Card { 
	protected:
		string name, type, description;
		int cost;
	public:
		explicit Card(string, string, string, int);
		virtual ~Card() = default;
		string getName() const;
		string getType() const;
		string getDescription() const;
		int getCost() const;
		virtual card_template_t display() const = 0;
};

#endif
