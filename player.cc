#include "player.h"
using namespace std;

Player::Player(string name) : name{name} {}

void Player::changeMagic(int newMagic) { magic += newMagic; }

void Player::changeLife(int newLife) { life += newLife; }

int Player::getLife() const { return life; }

int Player::getMagic() const { return magic; }

string Player::getName() const { return name; }

vector<Card*> getHand() const { return hand; }

vector<Minion*> getMinions() const { return minions; }

Minion* revive() {
    return graveyard.top();
}
bool fullHand() { return hand.size() == 5; }

void draw(); // transfers deck card to hand iff fullHand = false

//observer pattern methods
void notifyCards(vector<Card*>) const;
void attach(Card*);
void detach(Card*);