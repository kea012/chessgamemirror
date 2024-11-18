#include "../header/Queen.hpp"

using namespace std;

Queen::Queen(string characterColor) : Character(QUEEN, characterColor) {}

std::vector<std::string>* Queen::generatePossibleMoves(int x, int y) {
    vector<string> move;
    move.push_back("");
    return move;
}