#include "../header/Character.hpp"
#include "../header/Board.hpp"
#include <iostream>

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

void Character::removeSelfCheckMoves(Position currPosition, Board* gameBoard) {
  std::vector<Position>::iterator it = moveList.begin();
  while (it != moveList.end()) {
    Board* tempGameBoard(gameBoard);
    Position newPosition = *it;
    tempGameBoard->movePiece(currPosition.getRow(), currPosition.getCol(), newPosition.getRow(), newPosition.getCol());
    if (tempGameBoard->isKingInCheck(characterColor)) {
      it = moveList.erase(it);
    }
    else {
      it++;
    }
    delete tempGameBoard;
  }
}