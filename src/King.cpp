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

/*std::vector<std::string>* King::generatePossibleMoves(int x, int y) {
    vector<string>* move;
    move->push_back("");
    return move;
}*/

std::vector<std::string> King::getSpecificMoveStrings(Position currPosition, Board* gameBoard) {
  //KingMove moveGetter(characterColor, gameBoard);
  //return moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
  std::vector<std::string> emptyList;
  return emptyList;
}

Character* King::clone() {
    return new King(characterColor);
}