#include "player.h"
using namespace std;

Player::Player(string name) : name{name}, ritual{nullptr} {}

Player::~Player() { delete ritual; }

void Player::changeMagic(int newMagic) { magic += newMagic; }

void Player::changeLife(int newLife) { life += newLife; }

void Player::changeRitual(Card *ritual) {
    delete this->ritual;
    this->ritual = ritual;
}

int Player::getLife() const { return life; }

int Player::getMagic() const { return magic; }

Card *Player::getRitual() const { return ritual; }

string Player::getName() const { return name; }

vector<Card*> Player::getHand() const { return hand; }

vector<Card*> Player::getMinions() const { return summoned; }

Card* Player::getGraveyard() { 
    if (!graveyard.empty()) {
        Card* temp = graveyard.top();
        graveyard.pop();
        return temp;
    } else {
        return nullptr;
    }
}

vector<Card*>& Player::getDeck() { return deck; }

void Player::addToDeck(Card* card) {
    deck.emplace_back(card); 
}

Card* Player::revive() {
    return graveyard.top();
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
    playedMinions.emplace_back(temp);
    hand.erase(hand.begin() + i);
}

void Player::placeRitual(int i) {
    if (ritual != nullptr) { // delete old ritual
        Card* temp = ritual;
        ritual = hand[i];
        delete temp;
    } else {
        ritual = hand[i];
    }
    hand.erase(hand.begin() + i);
}

bool Player::playCard(int i) { // places down i-th card in hand
    Card* card = hand[i];
    if (card->getType() == "Minion") {
        placeMinion(i);
        return true;
    } else { // minion
        placeMinion(i);
        //return card->activate(i); // idk what type it takes
        return true;
    }
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
    graveyard.push(hand[i]);
    hand.erase(hand.begin() + i);
}

// void remove(int i) {
//     deck.erase(i);
// }

//observer pattern methods
void Player::notifyCards(vector<Card*>) const {}
void Player::attach(Card*) {}
void Player::detach(Card*) {}

// printing
card_template_t Player::display(int player_num) const {
  return display_player_card(player_num, name, life, magic);
}
