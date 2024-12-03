#include "../header/Bishop.hpp"

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

void Bishop::updateMoves(Position currPosition, Board* gameBoard) {
    moveList.clear();
    BishopMove moveGetter(characterColor, gameBoard);
    std::vector<std::string> moveStrings = moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
    for (int i = 0; i < moveStrings.size(); i++) {
        moveList.push_back(Position(moveStrings.at(i)));
    }
}