#include "../header/King.hpp"
#include "../header/KingMove.hpp"

using namespace std;

King::King(string characterColor) : Character(KING, characterColor) {
    if (characterColor == "w") {
        symbol = "♚";
    }
    else if (characterColor == "b") {
        symbol = "♔";
    }
}

int King::getMovedStatus() const {
  return this->characterMoved;
}

void King::setMoved() {
  ++this->characterMoved;
}

/*std::vector<std::string>* King::generatePossibleMoves(int x, int y) {
    vector<string>* move;
    move->push_back("");
    return move;
}*/

std::vector<std::string> King::getSpecificMoveStrings(Position currPosition, Board* gameBoard) {
  KingMove moveGetter(characterColor, gameBoard);
  return moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
}

Character* King::clone() {
    return new King(characterColor);
}