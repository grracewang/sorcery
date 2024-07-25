#include "player.h"
#include "card.h"
#include "minion.h"
#include "ritual.h"
#include "enchantment.h"
#include "spell.h"
#include "loaddeck.h"

// concretes
#include "concrete spells/blizzard.h"
#include "concrete spells/raisedead.h"

#include <utility>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int NUM_PLAYERS = 2;

enum class Op {HELP, END, QUIT, DRAW, DISCARD, ATTACK, PLAY, USE, INSPECT, HAND, BOARD, INVALID_COMMAND};

bool convertOp(const string &command, Op &op, bool testing) {
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
        return false;
    }
    return true;
}


int main(int argc, char *argv[]) {

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

    int i = 0;
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
    for (i = 1; i <= NUM_PLAYERS; i++) {
        string name;

        cout << "What's player " << i << "'s name?" << endl;
        cin >> name;
        players.emplace_back(new Player{name});
    }

    ifstream d1;
    if (setDeck1) {
        d1.open(deck1);
    } else {
        d1.open("tester.deck");
        cout << "opened"<< endl;
    }

    ifstream d2;
    if (setDeck2) {
        d2.open(deck2);
    } else {
        d2.open("tester.deck");
        cout << "opened"<< endl;
    }

    string card;
    while (getline(d1, card)) {
        players[0]->addToDeck(loadCard(card, players[0], players[1]));
    }
    while (getline(d2, card)) {
        players[1]->addToDeck(loadCard(card, players[1], players[0]));
    }

    // shuffle deck
    shuffleDeck(players[0]->getDeck());
    // for (int i = 0; i < players[0]->getDeck().size(); ++i) {
    //     cerr << players[0]->getDeck()[i]->getName() << endl;
    // } 
    shuffleDeck(players[1]->getDeck());
    // for (int i = 0; i < players[1]->getDeck().size(); ++i) {
    //     cerr << players[1]->getDeck()[i]->getName() << endl;
    // } 
    cout << "Decks shuffled successfully!" << endl;

    Op op;
    int curr = 0;
    int next = 1;
    while (true) {
        while (true) {
            string command;

            cout << "Type your command: " << endl;
            cin >> command;
            if (cin.fail()) break;
            if (!convertOp(command, op, testing)) {
                cerr << "Invalid command!" << endl;
                continue;
            }

            if (op == Op::QUIT) {
                cout << "Quitting the game" << endl;
                break;
            }
            
            if (op == Op::END) {
                cout << "Command: end" << endl;
                // trigger all spells and rituals at the end
                players[curr]->notifyAfterTurn();
                players[next]->notifyAfterTurn();

                break; // break out of the "turn" while loop
            }

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

                case Op::DRAW:
                {
                    players[curr]->draw();
                    cout << "Command: Card drawn for player " << curr + 1 << endl;
                    // cerr << "Hand size is: " << players[curr]->getHand().size() << endl;
                    for (int i = 0; i < players[curr]->getHand().size(); i++) {
                        cout << "Card drawn is: " << players[curr]->getHand()[i]->getName() << endl;
                    }
                }
                break;

                case Op::DISCARD:
                {
                    cin >> i;
                    players[curr]->discard(i);
                    cout << "Command: Discarded card " << i << " of player " << curr + 1 << endl;
                }
                break;

                case Op::ATTACK:
                {
                    int j;
                    cin >> i;
                    i -= 1;
                    cin >> j;
                    if (cin.fail()) {
                        cin.clear();
                        attack(players[curr]->getSummonedMinion(i), players[next]);
                        cout << "Command: attack player " << i << endl;
                    } else {
                        j -= 1;
                        attack(players[curr]->getSummonedMinion(i), players[next]->getSummonedMinion(j));
                        cout << "Command: attack minion " << i << j << endl;

                    }
                }
                break;

                case Op::PLAY:
                {
                    int p; // t-th card owned by player
                    cin >> i;
                    i -= 1;
                    cin >> p;
                    if (cin.fail()) {
                        cin.clear();
                        // check if card played is minion, if it's a minion we call all the spells/rituals minion related
                        if (players[curr]->getHand()[i]->getType() == "Minion") { // places ith card in hand
                            Minion* card = dynamic_cast<Minion*>(players[curr]->removeHandCard(i));
                            players[curr]->addToSummoned(card);
                        } else if (players[curr]->getHand()[i]->getType() == "Ritual") { // minion
                            Ritual* card = dynamic_cast<Ritual*>(players[curr]->getHand()[i]);
                            card->attach(players[curr]);
                            players[curr]->placeRitual(i);
                            cout << "Played a ritual" << endl;
                        } else if (players[curr]->getHand()[i]->getName() == "Raise Dead") {
                            dynamic_cast<RaiseDead*>(players[curr]->getHand()[i])->activate(players[curr]);
                        } else if (players[curr]->getHand()[i]->getName() == "Blizzard") {
                            dynamic_cast<Blizzard*>(players[curr]->getHand()[i])->activate(players[curr], players[next]);
                        }
                    } else {
                        char t; // t can only be 30, 31, 32, 33, 34, 114 (= r)
                        cin >> t;
                        p -= 1;
                        if (players[curr]->getHand()[i]->getType() == "Enchantment") {
                            // check if casted on minion type

                            // calls activate function on the enchantment
                            dynamic_cast<Enchantment*>(players[curr]->getHand()[i])->activate(dynamic_cast<Minion*>(players[p-1]->getHand()[t]));
                        } else if (players[curr]->getHand()[i]->getName() == "Banish") {
                            dynamic_cast<Banish*>(players[curr]->getHand()[i])->activate(players[p - 1], t);
                        } else if (players[curr]->getHand()[i]->getName() == "Disenchant") {
                            dynamic_cast<Disenchant*>(players[curr]->getHand()[i])->activate(players[p - 1], t - 1);
                        } else if (players[curr]->getHand()[i]->getName() == "Recharge") {
                            dynamic_cast<Recharge*>(players[curr]->getHand()[i])->activate(players[p - 1], t - 1);
                        } else if (players[curr]->getHand()[i]->getName() == "Unsummon") {
                            dynamic_cast<Unsummon*>(players[curr]->getHand()[i])->activate(players[p - 1], t - 1);
                        } else {
                            cout << "Cannot call command on this card." << endl;
                        }
                    }
                }
                break;

                case Op::USE:
                {
                    int p;
                    cin >> i >> p;
                    i -= 1;
                    if (cin.fail()) {
                        cin.clear();

                    } else {
                        char t; // t can only be 30, 31, 32, 33, 34, 114 (= r)
                        cin >> t;
                        p -= 1;

                    }
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
            } // switch

        } // while--turn loop (commands per turn)

        
        // change active player
        players[curr]->changeState();
        players[next]->changeState();
        swap(curr, next);

        // force end game
        if (op == Op::QUIT || cin.fail()) break;

        // if winning condition -> print win message, break from game loop

    } // while--game loop (switch between players)

    // delete everything created on the stack
} // main
