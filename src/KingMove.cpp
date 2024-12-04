#include "../header/KingMove.hpp"

using namespace std;

KingMove::KingMove(string color, Board* chessBoard) : Move(KINGMOVE, color), chessBoard(chessBoard) {}

vector<string> KingMove::generatePossibleMoves(int row, int column) {
  // Regular Moves
  for (int hor_move = -1; hor_move <= 1; hor_move++) {
    for (int ver_move = -1; ver_move <= 1; ver_move++) {
      if (hor_move == 0 && ver_move == 0) {
        continue;
      }
      if ((row+hor_move>=0 && column+ver_move>=0 && row+hor_move<8 && column+ver_move<8) && 
      (chessBoard->getPiece(row+hor_move,column+ver_move) != nullptr || 
      color != chessBoard->getPiece(row+hor_move,column+ver_move)->getColor())) {
        possibleMoves.push_back(to_string(row+hor_move)+to_string(column+ver_move));
      }
    }
  }
}