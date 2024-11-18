#include "../header/Rook.hpp"

using namespace std;

Rook::Rook(string characterColor) : Character(ROOK, characterColor) {}

bool Rook::getMovedStatus() const {
  return this->Character_Moved;
}

void Rook::setMoved() {
  this->Character_Moved = true;
}

std::vector<std::string>* Rook::generatePossibleMoves(int x, int y) { 
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
}