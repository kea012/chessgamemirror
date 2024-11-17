#include "../header/Knight.hpp"

Knight::Knight(std::string Character_Color) {
  this->Character_Type = KNIGHT;
  this->Character_Color = Character_Color;
}

std::vector<std::string>* Knight::generatePossibleMoves(int x, int y) {
  std::vector<std::string>* vec = new std::vector<std::string>();
  std::string move;
    if (x+1<8 && y+2<8) {
    move = std::to_string(x+1) + std::to_string(y+2);
    vec->push_back(move);
  }
  if (x+2<8 && y+1<8) {
    move = std::to_string(x+2) + std::to_string(y+1);
    vec->push_back(move);
  }
  if (x+2<8 && y-1>=0) {
    move = std::to_string(x+2) + std::to_string(y-1);
    vec->push_back(move);
  }
  if (x+1<8 && y-2>=0) {
    move = std::to_string(x+1) + std::to_string(y-2);
    vec->push_back(move);
  }
  if (x-1>=0 && y-2>=0) {
    move = std::to_string(x-1) + std::to_string(y-2);
    vec->push_back(move);
  }
  if (x-2>=0 && y-1>=0) {
    move = std::to_string(x-2) + std::to_string(y-1);
    vec->push_back(move);
  }
  if (x-2>=0 && y+1<8) {
    move = std::to_string(x-2) + std::to_string(y+1);
    vec->push_back(move);
  }
  if (x-1>=0 && y+2<8) {
    move = std::to_string(x-1) + std::to_string(y+2);
    vec->push_back(move);
  }
  return vec;
}