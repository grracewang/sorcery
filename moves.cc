#include "card.h"
#include "player.h"
#include "minion.h"
#include "changestat.h"

void attack(Minion *attacker, Minion *target) {
  target = new ChangeStat{target, '+', 0, -1 * attacker->getAtk()};
  attacker = new ChangeStat{attacker, '+', 0, -1 * target->getAtk()};
}

void attack(const Minion *attacker, Player *target) {
  target->changeLife(-1 * attacker->getAtk());
}