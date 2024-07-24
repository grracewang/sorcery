#include "player.h"
using namespace std;

Player::Player(string name) : name{name}, ritual{nullptr} {}

Player::~Player() { delete ritual; }

void Player::changeMagic(int newMagic) { magic += newMagic; }

void Player::changeLife(int newLife) { life += newLife; }

void Player::removeRitual() {
    delete this->ritual;
    ritual = nullptr;
}

int Player::getLife() const { return life; }

int Player::getMagic() const { return magic; }

Card* Player::getRitual() const { return ritual; }

string Player::getName() const { return name; }

vector<Card*> Player::getHand() const { return hand; }

vector<Minion*> Player::getSummoned() const { return summoned; }

stack<Minion*> Player::getGraveyard() const { return graveyard; }


vector<Card*>& Player::getDeck() { return deck; }

void Player::addToDeck(Card* card) {
    deck.emplace_back(card); 
}

void Player::addToHand(Card* card) {
    hand.emplace_back(card);
}

void Player::addToSummoned(Minion *m) {
    summoned.emplace_back(m);
    if (m->getTriggered()) 
}

Minion* Player::revive() {
    if (!graveyard.empty()) {
        Minion* temp = graveyard.top();
        graveyard.pop();
        return temp;
    } else {
        return nullptr;
    }
}
bool Player::fullHand() { return hand.size() == 5; }

void Player::draw() { // transfers deck card to hand iff fullHand = false
    
    Card* card = deck[deck.size() - 1]; // take top of deck
    hand.emplace_back(card);
    
    // do i need to delete memory?: call delete on last elem
    // cerr << hand.size() << endl;
    deck.erase(deck.begin() + (deck.size() - 1));
}

void Player::placeMinion(int i) { // places minion from hand on board
    Card* temp = hand[i];
    summoned.emplace_back(temp);
    hand.erase(hand.begin() + i);
}

void Player::placeRitual(int i) {
    if (ritual != nullptr) { // delete old ritual, mutate vector
        Card* temp = ritual;
        ritual = hand[i];
        delete temp;
    } else {
        ritual = hand[i];
    }
    hand.erase(hand.begin() + i);
}


bool Player::playCard(int i, Player* target, char t) { 
    // if (t == 114) { // t = r
    //     this->hand[i]->activate((target->getRitual()));
    // } else {
    //     this->hand[i]->activate((target->getMinions[i]));
    // }
    return true;
}

void Player::discard(int i) {
    Card* temp = hand[i];
    hand.erase(hand.begin() + i);
    delete temp;
}

void Player::moveToGraveyard(int i) {
    graveyard.push(summoned[i]);
    summoned.erase(summoned.begin() + i);
}

// void remove(int i) {
//     deck.erase(i);
// }

//observer pattern methods
bool Player::isPlaying() {
    return playing;
}

// printing
card_template_t Player::display(int player_num) const {
  return display_player_card(player_num, name, life, magic);
}
