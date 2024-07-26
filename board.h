#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <vector>
using namespace std;


class Board {
	private:
		vector<Player*> &players;
	public:
        // constructor
        Board(vector<Player*> &players);

        // printing functions
		void printBoard(ostream &out);
		void printHand(ostream &out, int playerNum);
		
		static void inspect(ostream &out, Minion *m);
};

#endif
