#include "../header/King.hpp"

using namespace std;

King::King(string characterColor) : Character(KING, characterColor) {
    if (characterColor == "w") {
        symbol = "♚";
    }
    else if (characterColor == "b") {
        symbol = "♔";
    }
}

std::vector<std::string>* King::generatePossibleMoves(int x, int y) {
    vector<string>* move;
    move->push_back("");
    return move;
}