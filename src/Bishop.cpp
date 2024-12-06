#include "../header/Bishop.hpp"
#include "../header/BishopMove.hpp"

using namespace std;

Bishop::Bishop(string characterColor) : Character(BISHOP, characterColor) {
    if (characterColor == "w") {
        symbol = "♝";
    }
    else if (characterColor == "b") {
        symbol = "♗";
    }
}

std::vector<std::string> Bishop::getSpecificMoveStrings(Position currPosition, Board* gameBoard) {
  BishopMove moveGetter(characterColor, gameBoard);
  return moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
}

Character* Bishop::clone() {
  return new Bishop(characterColor);
}