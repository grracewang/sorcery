#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "ritual.h"

class Subject {
    std::vector<Ritual*> preTurn;
    std::vector<Ritual*> afterTurn;
    std::vector<Ritual*> minionEnter;
    std::vector<Ritual*> minionLeave;

    public:
        Subject();
        void attachPreTurn(Ritual*);
        void attachAfterTurn(Ritual*);
        void attachMinionEnter(Ritual*);
        void attachMinionLeave(Ritual*);
        void detachPreTurn(Ritual*);
        void detachAfterTurn(Ritual*);
        void detachMinionEnter(Ritual*);
        void detachMinionLeave(Ritual*);
        // void notify() const;
        void notifyPreTurn() const;
        void notifyAfterTurn() const;
        void notifyMinionEnter() const;
        void notifyMinionLeave() const;
        virtual ~Subject() = 0;
};

#endif
