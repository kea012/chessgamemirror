#include "../header/Queen.hpp"
#include "../header/QueenMove.hpp"

using namespace std;

Queen::Queen(string characterColor) : Character(QUEEN, characterColor) {
    if (characterColor == "w") {
        symbol = "♛";
    }
    else if (characterColor == "b") {
        symbol = "♕";
    }
}

std::vector<std::string> Queen::getSpecificMoveStrings(Position currPosition, Board* gameBoard) {
  QueenMove moveGetter(characterColor, gameBoard);
  return moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
}

Character* Queen::clone() {
    return new Queen(characterColor);
}