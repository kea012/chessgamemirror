#include "../header/Pawn.hpp"
#include "../header/PawnMove.hpp"

using namespace std;

Pawn::Pawn(string characterColor) : Character(PAWN, characterColor) {
    if (characterColor == "w") {
        symbol = "♟";
    }
    else if (characterColor == "b") {
        symbol = "♙";
    }
}

int Pawn::getMovedStatus() const {
  return this->characterMoved;
}

void Pawn::setMoved() {
  ++this->characterMoved;
}

std::vector<std::string> Pawn::getSpecificMoveStrings(Position currPosition, Board* gameBoard) {
  PawnMove moveGetter(characterColor, gameBoard);
  return moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
}

Character* Pawn::clone() {
    return new Pawn(characterColor);
}