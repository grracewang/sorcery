#include "board.h"
#include "ascii_graphics.h"
#include <iostream>
#include <stack>
using namespace std;

Board::Board(vector<Player*> players) : players{players} {}

void printPlayerRow(ostream &out, const Player &player, int playerNum) {
    card_template_t ritual = (player.getRitual()) ? CARD_TEMPLATE_BORDER :
        ritual_display(*player.getRitual());

    card_template_t playerCard = player_display(player, playerNum);

    card_template_t graveyard = (player.getGraveyard().empty()) ?
        CARD_TEMPLATE_BORDER : minion_display(*player.getGraveyard().top());

    card_template_t empty = CARD_TEMPLATE_EMPTY;

    for (int i = 0; i < empty.size(); i++) {
        out << EXTERNAL_BORDER_CHAR_UP_DOWN
            << ritual[i]
            << empty[i]
            << playerCard[i]
            << empty[i]
            << graveyard[i]
            << EXTERNAL_BORDER_CHAR_UP_DOWN
            << endl;
    }
}

void printMinionRow(ostream &out, const vector<Minion*> minions) {
    card_template_t minionCards[5] = {CARD_TEMPLATE_BORDER,
                                      CARD_TEMPLATE_BORDER,
                                      CARD_TEMPLATE_BORDER,
                                      CARD_TEMPLATE_BORDER,
                                      CARD_TEMPLATE_BORDER};

    int i = 0;
    for (const auto &minion : minions) {
        minionCards[i] = minion_display(*minion);
        i++;
    }

    for (i = 0; i < minionCards[0].size(); i++) {
        out << EXTERNAL_BORDER_CHAR_UP_DOWN;
        for (const auto &minionCard : minionCards) out << minionCard[i];
        out << EXTERNAL_BORDER_CHAR_UP_DOWN << endl;
    }
}

ostream &Board::printBoard(ostream &out) {
    // top border
    out << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i < 165; i++) out << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    out << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;

    printPlayerRow(out, *players[0], 1);
    printMinionRow(out, players[0]->getMinions());
    for (const auto &line : CENTRE_GRAPHIC) cout << line << endl;
    printMinionRow(out, players[1]->getMinions());
    printPlayerRow(out, *players[1], 2);
    return out;
}
