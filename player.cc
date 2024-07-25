#include "player.h"
using namespace std;

Player::Player(string name) : name{name}, ritual{nullptr} {}

Player::~Player() { delete ritual; }

string Player::getName() const { return name; }

void Player::changeMagic(int newMagic) { magic += newMagic; }

void Player::changeLife(int newLife) { life += newLife; }

int Player::getLife() const { return life; }

int Player::getMagic() const { return magic; }

Ritual* Player::getRitual() const { return ritual; }

void Player::removeRitual() {
    delete this->ritual;
    ritual = nullptr;
}

vector<Card*>& Player::getDeck() { return deck; }

vector<Card*> Player::getHand() const { return hand; }

vector<Minion*> Player::getSummoned() const { return summoned; }

stack<Minion*> Player::getGraveyard() const { return graveyard; }

Card* Player::getHandCard(int i) const { return hand[i] };

Card* Player::removeHandCard(int i) {
    Card* temp = hand[i];
    hand.erase(hand.begin() + i);
    return temp;
}

Minion* Player::getSummonedMinion(int i) const {
    return summoned[i];
}

Minion* Player::removeSummonedMinion(int i) {
    Minion* temp = summoned[i];
    summoned.erase(summoned.begin() + i);
    return temp;
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

void Player::addToDeck(Card* card) {
    deck.emplace_back(card); 
}

void Player::addToHand(Card* card) {
    hand.emplace_back(card);
}

void Player::addToSummoned(Minion *m) {
    summoned.emplace_back(m);
    for (Ritual *r: m->getRituals()) {
        r->attach();
    }
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

void Player::discard(int i) {
    Card* temp = hand[i];
    hand.erase(hand.begin() + i);
    delete temp;
}

void Player::moveToGraveyard(int i) {
    graveyard.push(summoned[i]);
    summoned.erase(summoned.begin() + i);
}


//observer pattern methods
bool Player::isPlaying() {
    return playing;
}

void Player::changeState() {
    if (playing) playing = false;
    else playing = true;
}

// printing
card_template_t Player::display(int player_num) const {
  return display_player_card(player_num, name, life, magic);
}
