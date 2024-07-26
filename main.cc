#include "player.h"
#include "card.h"
#include "minion.h"
#include "ritual.h"
#include "enchantment.h"
#include "spell.h"
#include "loaddeck.h"
#include "board.h"

// concretes
#include "concrete_spells/blizzard.h"
#include "concrete_spells/raisedead.h"

#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

    // ifstream setup
    ifstream fileStream;
    istream *in = &cin;

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
            fileStream.open(initFile);
            if(!fileStream.is_open()) {
                cerr << "Cannot open init file" << endl;
                return 1;
            }
            in = &fileStream;

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
    Board *board = new Board{players};

    // getting both player's names if not provided (but didn't implement the if not provided part)
    for (i = 1; i <= NUM_PLAYERS; i++) {
        string name;
        cout << "What's player " << i << "'s name?" << endl;
        *in >> name;
        if (in->eof() && init) {
            fileStream.close();
            in = &cin;
            init = false;
            cin.clear();
            cout << "Switching to standard input" << endl;
        }
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
        d2.open(deck2);
    } else {
        d2.open("default.deck");
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
    shuffleDeck(players[1]->getDeck());
    cout << "Decks shuffled successfully!" << endl;

    Op op;
    int curr = 0;
    int next = 1;
    while (true) {

        cerr << "Active player: " << players[curr]->getName() << endl;

        players[curr]->notifyPreTurn();

        players[curr]->changeMagic(1);
        players[curr]->draw();
        for (auto minion : players[curr]->getSummoned()) {
            minion->resetAction();
        }

        while (true) {
            string command;

            if (in->eof() && init) {
                fileStream.close();
                in = &cin;
                init = false;
                cin.clear();
                cout << "Switching to standard input" << endl;
            }

            cout << "Type your command: " << endl;
            *in >> command;
            

            if (in->fail()) break;
            if (!convertOp(command, op, testing)) {
                cerr << "Invalid command!" << endl;
                continue;
            }

            if (op == Op::QUIT) {
                cout << "Quitting the game" << endl;
                break;
            }
            
            if (op == Op::END) {
                cout << "Player " << players[curr]->getName() << "'s turn has ended." << endl;
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
                    *in >> i;
                    players[curr]->discard(i);
                    cout << "Command: Discarded card " << i << " of player " << curr + 1 << endl;
                }
                break;

                case Op::ATTACK:
                {
                    string args;
                    getline(*in, args);
                    stringstream ss{args};
                    int j;
                    ss >> i >> j;
                    i--;
                    Minion *cur_minion = players[curr]->getSummonedMinion(i);
                    cout << "Player " << players[curr]->getName() << " used " << cur_minion->getName() << endl;
                    if (ss.fail()) {
                        in->clear();
                        if (cur_minion->useAction()) {
                            cur_minion->attack(players[next]);
                            cout << "Attacked player " << players[next]->getName() << endl;
                            // change actions to 0
                            if (players[next]->getLife() <= 0) {
                                cout << players[curr]->getName() << "has won!" << endl;
                                op = Op::QUIT;
                                break;
                            } 
                        } else {
                            cout << "Minion " << i + 1 << " has no more actions this turn. " << endl;
                        }
                        
                    } else {
                        j--;
                        if (cur_minion->useAction()) {
                            Minion *opp_minion = players[next]->getSummonedMinion(j);
                            players[next]->setSummoned(j, cur_minion->attack(opp_minion));
                            players[curr]->setSummoned(i, opp_minion->attack(cur_minion));
                            cout << "Player " << curr + 1 << "'s " << i << "th minion attacked Player" << next + 1 << "'s " << j << "th minion." << endl;

                            // if minion is dead mv to graveyard, enchantments removed in moveToGraveyard()
                            if (players[next]->minionDead(opp_minion)) players[next]->moveToGraveyard(j);
                            if (players[curr]->minionDead(cur_minion)) players[curr]->moveToGraveyard(i);
                        } else {
                            cout << "Minion " << i + 1 << " has no more actions this turn. " << endl;
                        }
                    }
                }
                break;

                case Op::PLAY:
                {
                    string args;
                    getline(*in, args);
                    stringstream ss{args};
                    int p; // t-th card owned by player
                    ss >> i >> p;
                    i--;
                    Card *playedCard = players[curr]->getHandCard(i);

                    // make sure card is value/index is in scope
                    if (!playedCard) {
                        cout << "You do not have a card at this position in your hand. Please try another command." << endl;
                        continue;
                    }

                    if (ss.fail()) {
                        // check if card played is minion, if it's a minion we call all the spells/rituals minion related

                        if (playedCard->getType() == "Ritual") { 
                            Ritual *ritual = dynamic_cast<Ritual*>(playedCard);
                            cout << ritual->getName() << endl;
                            players[curr]->setRitual(ritual); // automatically attaches (resource managed), error here
                            players[curr]->changeMagic(-ritual->getCost()); // subtract ritual cost
                            cout << "Played a ritual " << ritual->getName() << endl;
                            ritual = nullptr;

                        } else if (playedCard->getType() == "Spell") {
                            Spell* spell = dynamic_cast<Spell*>(players[curr]->removeHandCard(i));
                            players[curr]->changeMagic(-spell->getCost());
                            if (spell->activate(players[curr], players[next], -1)) {
                                cout << "Played a spell " << spell->getName() << endl;
                                players[curr]->discard(spell);
                            } else {
                                cout << "Cannot play spell." << endl;
                            }
                            spell = nullptr;
                            

                        } else if (playedCard->getType() == "Enchantment") {
                            cout << "You cannot use command play i for enchantments. Please try another command." << endl;
                            continue;

                        } else { // case where card is minion
                            Minion* card = dynamic_cast<Minion*>(players[curr]->removeHandCard(i));
                            players[curr]->addToSummoned(card, players[next]); // already notifies
                            players[curr]->changeMagic(-card->getCost());
                            card->resetAction(); // add an action when summoning a minion
                            cout << "Player " << players[curr]->getName() << " summoned " << card->getName() << endl;
                            card = nullptr;
                        }

                    } else {
                        char t; // t can only be 49, 50, 51, 52, 53, 114 (= r) (ascii)
                        ss >> t;
                        p--;

                        if (players[curr]->getHand()[i]->getType() == "Enchantment") {
                            // if we use enchantments then t must be a minion
                            t -= 49;
                            if (players[p]->getSummoned().size() <= t || t < 0) {
                                cout << "Target card is invalid. Try another command." << endl;
                                continue;
                            }
                            Enchantment* e = dynamic_cast<Enchantment*>(players[curr]->removeHandCard(i));
                            Minion* target = players[p]->getSummonedMinion(t);
                            players[p]->setSummoned(t, e->activate(target));
                            players[curr]->changeMagic(-e->getCost());
                            cout << "Player " << players[curr]->getName() << " used " << e->getName() << " on " << target->getName() << endl;
                            target = nullptr;
                            e = nullptr;

                        } else if (players[curr]->getHand()[i]->getType() == "Spell") {
                            Spell* spell = dynamic_cast<Spell*>(players[curr]->removeHandCard(i));
                            players[curr]->changeMagic(-spell->getCost());
                            if (p == 1) {
                                if (spell->activate(players[0], players[1], t)) {
                                    cout << "Player " << players[curr]->getName() << " played " << spell->getName() << endl;
                                    players[curr]->discard(spell);
                                } else {
                                    cout << "Cannot play spell." << endl;
                                }
                            } else if (p == 2) { // p = 1
                                if (spell->activate(players[1], players[0], t)) {
                                    cout << "Player " << players[curr]->getName() << " played " << spell->getName() << endl;
                                    players[curr]->discard(spell);
                                } else {
                                    cout << "Cannot play spell." << endl;
                                }
                            } else {
                                cout << "Cannot call command on this player." << endl;
                            }
                            spell = nullptr;
                        } else {
                            cout << "Cannot call command on this card." << endl;
                        }
                    }
                }
                break;

                case Op::USE:
                {
                    string args;
                    getline(*in, args);
                    stringstream ss{args};
                    ss >> i;
                    if (ss.fail()) {
                        cout << "Invalid parameters for use, try command again" << endl;
                        continue;
                    }

                    i--;
                    cout << "use"<< endl;
                    Spell *spell = players[curr]->getSummonedMinion(i)->getSpells()[0];

                    int p;
                    ss >> p;
                    if (ss.fail()) {
                        if (spell->activate(players[curr], players[next], -1)) {
                            delete players[curr]->removeHandCard(i);
                        }

                    } else {
                        char t; // t can only be 49, 50, 51, 52, 53, 114 (= r)
                        *in >> t;
                        p--;
                        if (p == 1) {
                            if (spell->activate(players[0], players[1], t)) {
                                delete players[curr]->removeHandCard(i);
                            }
                        } else if (p == 2) {
                            if (spell->activate(players[1], players[0], t)) {
                                delete players[curr]->removeHandCard(i);
                            }
                        } else {
                            cout << "Invalid player index" << endl;
                        }
                    }
                    cout << "Command: use" << i << endl;  
                }
                break;


                case Op::INSPECT:
                {
                    *in >> i;
                    cout << "Command: inspect" << i << endl;

                }
                break;

                case Op::HAND:
                {
                    cout << "Command: hand" << endl;
                    board->printHand(cout, curr); 
                }
                break;

                case Op::BOARD:
                {
                    cout << "Command: board" << endl;
                    board->printBoard(cout);
                } 
                break;
            } // switch

        } // while--turn loop (commands per turn)

        
        // change active player
        players[curr]->changeState();
        players[next]->changeState();
        swap(curr, next);

        // force end game
        if (op == Op::QUIT || in->fail()) break;

        // if winning condition -> print win message, break from game loop

    } // while--game loop (switch between players)

    // delete everything created on the stack
    
} // main
