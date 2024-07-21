#include "player.h"
using namespace std;

Player::Player(string name) : name{name} {}

void Player::changeMagic(int newMagic) { magic += newMagic; }

void Player::changeLife(int newLife) { life += newLife; }

void Player::changeRitual(Ritual *ritual) {
    delete this->ritual;
    this->ritual = ritual;
}

int Player::getLife() const { return life; }

int Player::getMagic() const { return magic; }

Ritual *Player::getRitual() const { return ritual; }

string Player::getName() const { return name; }

vector<Card*> Player::getHand() const { return hand; }

vector<Minion*> Player::getMinions() const { return minions; }

stack<Minion*> Player::getGraveyard() const { return graveyard; }

Minion* Player::revive() {
    return graveyard.top();
}
bool Player::fullHand() { return hand.size() == 5; }

void Player::draw(); // transfers deck card to hand iff fullHand = false

//observer pattern methods
void Player::notifyCards(vector<Card*>) const;
void Player::attach(Card*);
void Player::detach(Card*);