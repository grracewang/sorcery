#include "subject.h"

Subject::Subject() {}
Subject::~Subject() {}

void Subject::attachPreTurn(Ritual* r) {
    preTurn.emplace_back(r);
}
void Subject::attachAfterTurn(Ritual* r) {
    afterTurn.emplace_back(r);
}
void Subject::attachMinionEnter(Ritual* r) {
    minionEnter.emplace_back(r);
}
void Subject::attachMinionLeave(Ritual* r) {
    minionLeave.emplace_back(r);
}

void Subject::detachPreTurn(Ritual *r) {
  for (auto it = preTurn.begin(); it != preTurn.end(); ++it) {
    if (*it == r) {
      preTurn.erase(it);
      break;
    }
  }
}

void Subject::detachAfterTurn(Ritual *r) {
  for (auto it = afterTurn.begin(); it != afterTurn.end(); ++it) {
    if (*it == r) {
      afterTurn.erase(it);
      break;
    }
  }
}

void Subject::detachMinionEnter(Ritual *r) {
  for (auto it = minionEnter.begin(); it != minionEnter.end(); ++it) {
    if (*it == r) {
      minionEnter.erase(it);
      break;
    }
  }
}

void Subject::detachMinionLeave(Ritual *r) {
  for (auto it = minionLeave.begin(); it != minionLeave.end(); ++it) {
    if (*it == r) {
      minionLeave.erase(it);
      break;
    }
  }
}

// void Subject::notify() const {
//     // if preturn
//     for (auto ritual : preTurn) ritual->notify();
//     // if after turn
//     for (auto ritual : afterTurn) ritual->notify();
//     // if minion enters
//     for (auto ritual : minionEnter) ritual->notify();
//     // if minion leaves
//     for (auto ritual : minionLeave) ritual->notify();
// }

void Subject::notifyPreTurn() const {
    for (auto ritual : preTurn) ritual->notify();
}

void Subject::notifyAfterTurn() const {
    for (auto ritual : afterTurn) ritual->notify();
}
void Subject::notifyMinionEnter() const {
    for (auto ritual : minionEnter) ritual->notify();
}
void Subject::notifyMinionLeave() const {
    for (auto ritual : minionLeave) ritual->notify();
}