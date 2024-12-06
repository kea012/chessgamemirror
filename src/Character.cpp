#include "../header/Character.hpp"
#include "../header/Board.hpp"

using namespace std; 

Character::Character(CharacterType type, string characterColor) : type(type), characterColor(characterColor) {}

CharacterType Character::getType() const {
  return this->type;
}

bool Character::setAliveStatus() {
  this->alive = false;
  return this->alive;
}

bool Character::getAliveStatus() const {
  return this->alive;
}

std::string Character::getColor() const {
  return this->characterColor;
}

std::string Character::getSymbol() const {
  return this->symbol;
} 

std::vector<Position> Character::getMoveList() const {
  return this->moveList;
}

void Character::updateMoves(Position currPosition, Board* gameBoard) {
  moveList.clear();
  std::vector<std::string> moveStrings = getSpecificMoveStrings(currPosition, gameBoard);
  for (auto i = moveStrings.begin(); i < moveStrings.end(); i++) {
    Position newMove;
    if (newMove.setPositionFromInts(i->front() - '0', i->back() - '0')) {
      moveList.push_back(newMove);
    }
  }
}

void Character::removeSelfCheckMoves(Position currPosition, Board* gameBoard) {
  std::vector<Position>::iterator it = moveList.begin();
  while (it < moveList.end()) {
    Board* tempGameBoard = new Board(*gameBoard);
    tempGameBoard->movePiece(currPosition.getRow(), currPosition.getCol(), it->getRow(), it->getCol());
    tempGameBoard->generateAllPlayerMoves();
    if (tempGameBoard->isKingInCheck(characterColor)) {
      it = moveList.erase(it);
    }
    else {
      it++;
    }
    delete tempGameBoard;
  }
}