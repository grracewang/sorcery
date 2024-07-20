#include "board.h"
#include "ascii_graphics.h"
#include <iostream>
#include <stack>
using namespace std;

Board::Board(vector<Player*> players) : players{players} {}

void printPlayerRow(ostream &out, const Player &player, int playerNum) {
    card_template_t ritual;
    if (player.getRitual()) ritual = CARD_TEMPLATE_BORDER;
    else ritual = ritual_display(*player.getRitual());

    card_template_t playerCard = player_display(player, playerNum);

    card_template_t graveyard;
    if (player.getGraveyard().empty()) graveyard = CARD_TEMPLATE_BORDER;
    else graveyard = minion_display(*player.getGraveyard().top());

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

ostream &Board::printBoard(ostream &out) {
    // top border
    out << EXTERNAL_BORDER_CHAR_TOP_LEFT;
    for (int i = 0; i < 165; i++) out << EXTERNAL_BORDER_CHAR_LEFT_RIGHT;
    out << EXTERNAL_BORDER_CHAR_TOP_RIGHT << endl;

    printPlayerRow(out, *players[0], 1);
    // print minion row
    for (const auto &line : CENTRE_GRAPHIC) cout << line << endl;
    // print minion row
    printPlayerRow(out, *players[1], 2);


}
