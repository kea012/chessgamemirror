#include "../header/Pawn.hpp"

using namespace std;

Pawn::Pawn(string characterColor, string symbol) : Character(PAWN, characterColor, symbol) {}

std::vector<std::string>* Pawn::generatePossibleMoves(int x, int y) {
    vector<string>* move;
    move->push_back("");
    return move;
}