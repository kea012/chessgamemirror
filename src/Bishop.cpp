#include "../header/Bishop.hpp"

using namespace std;

Bishop::Bishop(string characterColor) : Character(BISHOP, characterColor) {}

std::vector<std::string>* Bishop::generatePossibleMoves(int x, int y) {
  std::vector<std::string>* vec = new std::vector<std::string>();
  std::string move;
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
}