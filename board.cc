#include "board.h"
#include "ascii_graphics.h"
#include <iostream>
#include <stack>
using namespace std;

Board::Board(vector<Player*> players) : players{players} {}

// prints 5 card_template_t in a row with the border if border is true
//    and without it otherwise
void printRowCards(ostream &out, const vector<card_template_t> cards, bool border) {
    int numLines = cards[0].size();

    for (int i = 0; i < numLines; i++) {
        if (border) out << EXTERNAL_BORDER_CHAR_UP_DOWN;

        for (const auto &card : cards) {
            out << card[i];
        }

        if (border) out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        out << endl;
    }
}

void printPlayerRow(ostream &out, const Player &player, int playerNum) {
    // ritual into printable format
    card_template_t ritual = (player.getRitual()) ? CARD_TEMPLATE_BORDER :
        player.getRitual()->display();

    // graveyard into printable format
    card_template_t graveyard = (player.getGraveyard().empty()) ?
        CARD_TEMPLATE_BORDER : player.getGraveyard().top()->display();

    // convert cards into a card_template_t[5]
    vector<card_template_t> cards = {ritual,
                                    CARD_TEMPLATE_EMPTY,
                                    player.display(playerNum),
                                    CARD_TEMPLATE_EMPTY,
                                    graveyard};

    // print the row
    printRowCards(out, cards, true);
}

void printMinionRow(ostream &out, const vector<Card*> minions) {
    vector<card_template_t> minionCards;

    int i = 0;
    // all possible minions into printable format
    for (const auto &minion : minions) {
        minionCards.emplace_back(minion->display());
        i++;
    }
    // fill remaining spots with empty squares
    for ( ; i < 5; i++) {
        minionCards.emplace_back(CARD_TEMPLATE_BORDER);
    }

    printRowCards(out, minionCards, true);
}

ostream &Board::printBoard(ostream &out) {
    // top border
    out << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i < 165; i++) out << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    out << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;

    // player 1's rows
    printPlayerRow(out, *players[0], 1);
    printMinionRow(out, players[0]->getMinions());

    // centre graphic
    for (const auto &line : CENTRE_GRAPHIC) cout << line << endl;

    // player 2's rows
    printMinionRow(out, players[1]->getMinions());
    printPlayerRow(out, *players[1], 2);

    // bottom border
    out << EXTERNAL_BORDER_CHAR_BOTTOM_LEFT;
    for (int i = 0; i < 165; i++) out << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    out << EXTERNAL_BORDER_CHAR_BOTTOM_RIGHT << endl;

    return out;
}

ostream &Board::printHand(ostream &out, int playerNum) {
    vector<card_template_t> cards;

    int i = 0;
    // all possible minions into printable format
    for (const auto &card : players[playerNum]->getHand()) {
        cards.emplace_back(card->display());
        i++;
    }
    // fill remaining spots with empty squares
    for ( ; i < 5; i++) {
        cards.emplace_back(CARD_TEMPLATE_BORDER);
    }

    printRowCards(out, cards, true);

    return out;
}
