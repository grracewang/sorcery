#include "player.h"
#include "minion.h"

#include <stdexcept>

using namespace std;

Player::Player(string name) : name{name}, ritual{nullptr} {}

Player::~Player() { delete ritual; }

string Player::getName() const { return name; }

void Player::changeMagic(int newMagic) { magic += newMagic; }

void Player::changeLife(int newLife) { life += newLife; }

int Player::getLife() const { return life; }

int Player::getMagic() const { return magic; }

Ritual* Player::getRitual() const { return ritual; }

vector<Card*>& Player::getDeck() { return deck; }

vector<Card*> Player::getHand() const { return hand; }

vector<Minion*> Player::getSummoned() const { return summoned; }

stack<Minion*> Player::getGraveyard() const { return graveyard; }

Card* Player::getHandCard(size_t i) const {
    try { return hand.at(i); }
    catch (out_of_range e) { return nullptr; }
};

Card* Player::removeHandCard(size_t i) {
    try { 
        Card* temp = hand.at(i); 
        hand.erase(hand.begin() + i);
        return temp;
    } catch (out_of_range e) { return nullptr; }
}

Minion* Player::getSummonedMinion(size_t i) const {
    try { return summoned.at(i); }
    catch (out_of_range e) { return nullptr; }
}

Minion* Player::removeSummonedMinion(size_t i) {
    try {
        Minion* newMinion = summoned[i];
        summoned.erase(summoned.begin() + i);
        Minion* temp = newMinion;
        notifyMinionLeave();
        while (temp->getMinion() != nullptr) {
            temp = temp->getMinion();
        }
        temp->removeAbilities(); 
        temp = nullptr;
        return newMinion;
    } catch (out_of_range e) { return nullptr; }
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

bool Player::fullHand() { return hand.size() >= 5; }

void Player::draw() { // transfers deck card to hand iff fullHand = false
    if (!fullHand()) {
        try {
            Card* card = deck.at(deck.size() - 1); // take top of deck
            addToHand(card);
            deck.erase(deck.begin() + (deck.size() - 1));
        } catch (out_of_range e) { cout << "The deck is empty." << endl; }
    } else cout << "Your hand is full." << endl;
}

void Player::addToDeck(Card* card) {
    deck.emplace_back(card); 
}

void Player::addToHand(Card* card) {
    if (!fullHand()) hand.emplace_back(card);
    else std::cout << "Hand is full." << std::endl;
}

void Player::addToSummoned(Minion *m, Player *opponent) {
    summoned.emplace_back(m);
    while (m->getMinion() != nullptr) {
        m = m->getMinion();
    }
    m->addAbility(this, opponent); // mutating the base minion
    notifyMinionEnter(); // if standstill is in effect then the minion is immediattely deleted
}

void Player::placeMinion(size_t i) { // places minion from hand on board
    try {
        Minion *temp = dynamic_cast<Minion*>(hand.at(i));
        summoned.emplace_back(temp);
        hand.erase(hand.begin() + i);
    } catch (out_of_range e) { cout << "Invalid index. Try again." << endl; }
}

void Player::setSummoned(size_t i, Minion *newMinion) {
    summoned.erase(summoned.begin() + i);
    summoned.insert(summoned.begin() + i, newMinion);
}

void Player::setRitual(Ritual *r) {
    // delete old ritual
    if (ritual) {
        Ritual* temp = ritual;
        ritual = nullptr;
        delete temp;
    }

    // mutate vector
    ritual = r; 
    if (ritual) {
        
        ritual->attach();
    }
}

void Player::discard(size_t i) {
    try {
        Card* temp = hand.at(i);
        hand.erase(hand.begin() + i);
        delete temp;
    } catch (out_of_range e) { cout << "Invalid index. Try again." << endl; }
 }


void Player::moveToGraveyard(size_t i) {
    try {
        Minion* m = Minion::removeEnchantments(summoned.at(i));
        setSummoned(i, m);
        graveyard.push(removeSummonedMinion(i));
    } catch (out_of_range e) { cout << "Invalid index." << endl;}
    
}

void Player::discard(Card* spell) {
    delete spell;
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
card_template_t Player::display(size_t player_num) const {
  return display_player_card(player_num, name, life, magic);
}
