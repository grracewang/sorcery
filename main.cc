#include "player.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM_PLAYERS = 2;

enum Op {HELP, END, QUIT, DRAW, DISCARD, ATTACK, PLAY, USE, INSPECT, HAND, BOARD, INVALID_COMMAND};

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
    bool testing = false;
    
    // set up arguments
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-testing") testing = true;
    }


    vector<Player*> players;

    // getting both player's names if not provided (but didn't implement the if not provided part)
    for (int i = 1; i <= NUM_PLAYERS; i++) {
        string name;

        cout << "What's player " << i << "'s name?" << endl;
        cin >> name;
        players.emplace_back(new Player{name});
    }


    while (true) {
        string command;

        cin >> command;
        if (cin.fail()) break;
        if (!convertOp(command, op, testing)) {
            cerr << "Invalid command!" << endl;
            continue;
        }

        if (op == Op::QUIT) break;

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
            case Op::DRAW:
            case Op::DISCARD:
            case Op::ATTACK:
            case Op::PLAY:
            case Op::USE:
            case Op::INSPECT:
            case Op::HAND:
            case Op::BOARD:
        }
    }

    // delete everything created on the stack
}
