#include "../header/Rook.hpp"
#include "../header/RookMove.hpp"

using namespace std;

Rook::Rook(string characterColor) : Character(ROOK, characterColor) {
    if (characterColor == "w") {
        symbol = "♜";
    }
    else if (characterColor == "b") {
        symbol = "♖";
    }
}

int Rook::getMovedStatus() const {
  return this->characterMoved;
}

void Rook::setMoved() {
  ++this->characterMoved;
}

std::vector<std::string> Rook::getSpecificMoveStrings(Position currPosition, Board* gameBoard) {
  RookMove moveGetter(characterColor, gameBoard);
  return moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
}

Character* Rook::clone() {
  return new Rook(characterColor);
}