#include "player.h"
#include "card.h"
#include "minion.h"
#include "ritual.h"
#include "enchantment.h"
#include "spell.h"
#include "loaddeck.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int NUM_PLAYERS = 2;

enum class Op {HELP, END, QUIT, DRAW, DISCARD, ATTACK, PLAY, USE, INSPECT, HAND, BOARD, INVALID_COMMAND};

bool convertOp(const string &command, Op &op, bool testing) {
    bool result = true;
    if (command == "help") op = Op::HELP;
    else if (command == "end") op = Op::END;
    else if (command == "quit") op = Op::QUIT;
    else if (command == "draw" && testing) op = Op::DRAW;
    else if (command == "discard" && testing) op = Op::DISCARD;
    else if (command == "attack") op = Op::ATTACK;
    else if (command == "play") op = Op::PLAY;
    else if (command == "use") op = Op::USE;
    else if (command == "inspect") op = Op::INSPECT;
    else if (command == "hand") op = Op::HAND;
    else if (command == "board") op = Op::BOARD;
    else {
        op = Op::INVALID_COMMAND;
        result = false;
    }
    return result;
}


int main(int argc, char *argv[]) {
    Op op;

    int i = 0;

    // filenames
    string initFile = "";
    string deck1 = "";
    string deck2 = "";

    // check for flags
    bool init = false;
    bool testing = false;
    bool setDeck1 = false;
    bool setDeck2 = false;
    bool graphics = false;

    // set up arguments
    while (i < argc) {
		string arg = argv[i]; 
        
		if (arg == "-init") {
            cout << "-init on" << endl;
            init = true;
            ++i;
            arg = argv[i];
            initFile = arg;
        } else if (arg == "-deck1") {
            cout << "-deck1 on" << endl;
            setDeck1 = true;
            ++i;
            arg = argv[i];
            deck1 = arg;
        } else if (arg == "-deck2") {
            cout << "-deck2 on" << endl;
            setDeck2 = true;
            ++i;
            arg = argv[i];
            deck2 = arg;
        } else if (arg == "-graphics") {
            cout << "graphics on" << endl;
            graphics = true;
        } else if (arg == "-testing") {
            cout << "testing mode on" << endl;
            testing = true;
        } 
        // else {
        //     cerr << "Not a valid command line argument" << endl;
        // }

        ++i;
    } // command line loop
    
    vector<Player*> players;

    // getting both player's names if not provided (but didn't implement the if not provided part)
    for (int i = 1; i <= NUM_PLAYERS; i++) {
        string name;

        cout << "What's player " << i << "'s name?" << endl;
        cin >> name;
        players.emplace_back(new Player{name});
    }

    ifstream d1;
    if (setDeck1) {
        d1.open(deck1);
    } else {
        d1.open("default.deck");
    }

    ifstream d2;
    if (setDeck2) {
        d1.open(deck2);
    } else {
        d1.open("default.deck");
    }

    string card;
    while (getline(d1, card)) {
        // players[0]->addToCards(players[0]->getDeck(), loadCard(card, players[0])); // adds cards to deck
        players[0]->addToDeck(loadCard(card));
        //shuffle(player[0])
    }
    while (getline(d2, card)) {
        players[1]->addToDeck(loadCard(card));
    }

    i = 0;
    int curr = 0;
    int next = 1;
    while (true) {
        if (curr == players.size()) { // helps us count whose turn it is
            curr = 0; 
            next = 1;
        } else if (next == players.size()) {
            next = 0;
        }
        string command;

        cin >> command;
        if (cin.fail()) break;
        if (!convertOp(command, op, testing)) {
            cerr << "Invalid command!" << endl;
            continue;
        }

        // if (op == Op::QUIT) break;

        switch (op) {
            case Op::HELP:
            {
                // outputs the help message in help.txt
                ifstream f{"help.txt"};
                string str;
                while (getline(f, str)) {
                    cout << str << endl;
                }
            }
            break;

            case Op::END:
            {
                cout << "Command: end" << endl;
                // trigger all spells and rituals at the end
            }
            break;

            case Op::DRAW:
            {
                players[curr]->draw();
                cout << "Command: Card drawn for player " << curr + 1 << endl;
            }
            break;

            case Op::DISCARD:
            {
                cin >> i;
                players[curr]->discard(i);
                cout << "Command: Discarded card " << i << "of player " << curr + 1 << endl;
            }
            break;

            case Op::ATTACK:
            {
                int j;
                cin >> i;
                cin >> j;
                if (cin.fail()) {
                    cin.clear();
                    cout << "Command: attack minion" << i << endl;
                } else {
                    cout << "Command: attack minion" << i << j << endl;
                }
            }
            break;

            case Op::PLAY:
            {
                int p; // t-th card owned by player
                cin >> i;
                cin >> p;
                if (cin.fail()) {
                    cin.clear();
                    // check if card played is minion, if it's a minion we call all the spells/rituals minion related
                    if (players[curr]->playCard(i, players[curr], players[next])) {
                        cout << "Command: Played card " << i << endl;
                    } else {
                        cout << "Card can't be played." << endl;
                    }
                } else {
                    char t; // t can only be 30, 31, 32, 33, 34, 114 (= r)
                    cin >> t;
                    //if (players[curr]->playCard(i, players[next], t)) {
                    if (true) {
                       cout << "Command: Played card " << i << p << t << endl; 
                    } else {
                        cout << "Card can't be played." << endl;
                    }
                    
                }
            }
            break;

            case Op::USE:
            {

                cin >> i;
                cout << "Command: use" << i << endl;    
            }
            break;

            case Op::INSPECT:
            {
                cin >> i;
                cout << "Command: inspect" << i << endl;
            }
            break;

            case Op::HAND:
            {
                cout << "Command: hand" << endl;
            }
            break;

            case Op::BOARD:
            {
                cout << "Command: board" << endl;
            } 
            break;

            case Op::QUIT:
            {
                break;
            }
            break;
            // case Op::INVALID_COMMAND:
            // {

            // }
        } //switch

        ++curr; // next player's turn
        ++next;
    } //while

    // delete everything created on the stack
} // main
