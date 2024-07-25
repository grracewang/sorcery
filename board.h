#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <vector>
using namespace std;


class Board {
	private:
		vector<Player*> players;
	public:
        // constructor
        Board(vector<Player*> players);

        // printing functions
		ostream &printBoard(ostream &out);
		ostream &printHand(ostream &out, int playerNum);

		// static ostream &inspect(ostream &out, Minion *m);
};

#endif
