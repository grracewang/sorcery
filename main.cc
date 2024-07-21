// #include "player.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM_PLAYERS = 2;

<<<<<<< HEAD
enum Op {HELP = 0, END, QUIT, DRAW, DISCARD, ATTACK, PLAY, USE, INSPECT, HAND, BOARD, INVALID_COMMAND};
=======
enum class Op {HELP, END, QUIT, DRAW, DISCARD, ATTACK, PLAY, USE, INSPECT, HAND, BOARD, INVALID_COMMAND};
>>>>>>> b643136 (fixed main while loop)

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
    string initFile;
    string deck1;
    string deck2;

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
    
    // vector<Player*> players;

    // getting both player's names if not provided (but didn't implement the if not provided part)
    // for (int i = 1; i <= NUM_PLAYERS; i++) {
    //     string name;

    //     cout << "What's player " << i << "'s name?" << endl;
    //     cin >> name;
    //     players.emplace_back(new Player{name});
    // }

    i = 0;

    while (true) {
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
            }
            break;

            case Op::DRAW:
            {
                cout << "Command: draw (testing mode)" << endl;
            }
            break;

            case Op::DISCARD:
            {
                cin >> i;
                cout << "Command: discard (testing mode)" << i << endl;
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
                int j;
                cin >> i;
                cin >> j;
                if (cin.fail()) {
                    cin.clear();
                    cout << "Command: play" << i << endl;
                } else {
                    cout << "Command: play" << i << j << endl;
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
        }
    }

    // delete everything created on the stack
}
