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

/*std::vector<std::string>* Bishop::generatePossibleMoves(int x, int y) {
  std::vector<std::string>* vec = new std::vector<std::string>();
  /*std::string move;
  for (int i=1; i<8; i++) {
    if (x+i<8 && y+i<8) {
      move = std::to_string(x+i) + std::to_string(y+i);
      vec->push_back(move);
    }
    if (x+i<8 && y-i>=0) {
      move = std::to_string(x+i) + std::to_string(y-i);
      vec->push_back(move);
    }
    if (x-i>=0 && y+i<8) {
      move = std::to_string(x-i) + std::to_string(y+i);
      vec->push_back(move);
    } 
    if (x-i>=0 && y-i>=0) {
      move = std::to_string(x-i) + std::to_string(y-i);
      vec->push_back(move);
    }
  }
  return vec;
}*/

std::vector<std::string> Bishop::getSpecificMoveStrings(Position currPosition, Board* gameBoard) {
  BishopMove moveGetter(characterColor, gameBoard);
  return moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
}

Character* Bishop::clone() {
  return new Bishop(characterColor);
}