#include "../header/King.hpp"

using namespace std;

King::King(string characterColor, string symbol) : Character(KING, characterColor, symbol) {}

std::vector<std::string>* King::generatePossibleMoves(int x, int y) {
    vector<string>* move;
    move->push_back("");
    return move;
}