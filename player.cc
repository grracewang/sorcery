#include "player.h"
#include "card.h"
using namespace std;

Player::Player(string name) : name{name}, ritual{nullptr} {}

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

// vector<Card*> getDeck() const { return deck };

void Player::addToDeck(Card* card) {
    deck.emplace_back(card); 
}

Minion* Player::revive() {
    return graveyard.top();
}
bool Player::fullHand() { return hand.size() == 5; }

void Player::draw() { // transfers deck card to hand iff fullHand = false
    Card* card = deck[deck.size() - 1]; // take top of deck
    hand.emplace_back(card);
    // do i need to delete memory?: call delete on last elem
    deck.erase(hand.begin() + deck.size() - 1);
}

void Player::placeCard(int i) {
    Card* temp = hand[i];
    minions.emplace_back(temp);
    hand.erase(hand.begin() + i);
}

bool Player::playCard(int i) { // places down i-th card in hand
    Card* card = hand[i];
    if (card->getType() == "Minion") {
        placeCard(i);
        return true;
    } else { // minion
        placeCard(i);
        return card->activate(i); // idk what type it takes
    }
}

// void remove(int i) {
//     deck.erase(i);
// }



//observer pattern methods
void Player::notifyCards(vector<Card*>) const {}
void Player::attach(Card*) {}
void Player::detach(Card*) {}