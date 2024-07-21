#ifndef BANISH_H
#define BANISH_H

#include "../spell.h"
using namespace std;

class Banish: public Spell {
    public:
        explicit Banish(): Spell{"Banish", "banish.txt", 2} {}
        bool activate(Card *t) override {
            if (t) {
                if (t->getType() == "Ritual") {
                    delete t;
                } else if (t->getType() == "Minion") {
                    delete t;
                } else {
                    cerr << "The target card must be a minion or ritual." << endl;
                }
            } else {
                cerr << "Banish requires a target player and target card." << endl;
            }
        }
};

#endif