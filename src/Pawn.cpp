#include "../header/Pawn.hpp"

using namespace std;

Pawn::Pawn(string characterColor) : Character(PAWN, characterColor) {}

std::vector<std::string>* Pawn::generatePossibleMoves(int x, int y) {
    vector<string>* move;
    move.push_back("");
    return move;
}