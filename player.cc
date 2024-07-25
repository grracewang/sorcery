#include "player.h"
#include "minion.h"
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

Card* Player::getHandCard(int i) const { return hand[i]; };

Card* Player::removeHandCard(int i) {
    Card* temp = hand[i];
    hand.erase(hand.begin() + i);
    return temp;
}

Minion* Player::getSummonedMinion(int i) const {
    return summoned[i];
}

Minion* Player::removeSummonedMinion(int i) {
    Minion* newMinion = summoned[i];
    Minion* temp = newMinion;
    summoned.erase(summoned.begin() + i);
    notifyMinionLeave();
    while (temp->getMinion() != nullptr) {
       temp = temp->getMinion();
    }
    temp->removeAbilities(); 
    return newMinion;
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
    addToHand(card);
    deck.erase(deck.begin() + (deck.size() - 1));
}

void Player::addToDeck(Card* card) {
    deck.emplace_back(card); 
}

void Player::addToHand(Card* card) {
    if (hand.size() < 5) hand.emplace_back(card);
    else std::cout << "Hand is full." << std::endl;
}

void Player::addToSummoned(Minion *m, Player *opponent) {
    summoned.emplace_back(m);
    while (m->getMinion() != nullptr) {
        m = m->getMinion();
    }
    m->addAbility(this, opponent); // mutating the base minion
    notifyMinionEnter();
}

void Player::placeMinion(int i) { // places minion from hand on board
    Card* temp = hand[i];
    summoned.emplace_back(temp);
    hand.erase(hand.begin() + i);
}

void Player::setSummoned(int i, Minion *newMinion) {
    summoned.erase(summoned.begin() + i);
    summoned.insert(summoned.begin() + i, newMinion);
}

void Player::setRitual(Ritual *r) {
    if (ritual != nullptr) { // delete old ritual, mutate vector
        Ritual* temp = ritual;
        delete temp;
    }
    ritual = r; 
    if (ritual != nullptr) {
        ritual->attach();
    }
}

void Player::discard(int i) {
    Card* temp = hand[i];
    hand.erase(hand.begin() + i);
    delete temp;
}

bool Player::minionDead(Minion *m) {
    if (m->getDef() <= 0) return true;
    return false;
}


void Player::moveToGraveyard(int i) {
    Minion* m = Minion::removeEnchantments(summoned[i]);
    setSummoned(i, m);
    graveyard.push(removeSummonedMinion(i));
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
