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
  this->characterMoved = true;
}

/*std::vector<std::string>* Rook::generatePossibleMoves(int x, int y) { 
  std::vector<std::string>* vec = new std::vector<std::string>();
  std::string move;
  // Horizontal Moves
    for (int i=x+1; i<8; i++) {
    move = std::to_string(i) + std::to_string(y);
    vec->push_back(move);
  }
  for (int i=x-1; i>=0; i--) {
    move = std::to_string(i) + std::to_string(y);
    vec->push_back(move);
  }
  // Vertical Moves
  for (int i=y+1; i<8; i++) {
    move = std::to_string(x) + std::to_string(i);
    vec->push_back(move);
  }
  for (int i=y-1; i>=0; i--) {
    move = std::to_string(x) + std::to_string(i);
    vec->push_back(move);
  }

  return vec;
}*/

void Rook::updateMoves(Position currPosition, Board* gameBoard) {
    moveList.clear();
    RookMove moveGetter(characterColor, gameBoard);
    std::vector<std::string> moveStrings = moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
    for (int i = 0; i < moveStrings.size(); i++) {
        moveList.push_back(Position(moveStrings.at(i)));
    }
}

Character* Rook::clone() {
  return new Rook(characterColor);
}