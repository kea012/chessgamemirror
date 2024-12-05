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
  
  if (static_cast<King*>(chessBoard->getPiece(row,column))->getMovedStatus()==0) {
    castling(row, column);
  }
}

void KingMove::castling(int row, int column ) {
  if (chessBoard->getPiece(row,0) != nullptr) {
    if (chessBoard->getPiece(row,0)->getType() == ROOK && chessBoard->getPiece(row,1) == nullptr && chessBoard->getPiece(row,2) == nullptr && chessBoard->getPiece(row,3) == nullptr) {
      if (static_cast<Rook*>(chessBoard->getPiece(row,0))->getMovedStatus()==0) {
        possibleMoves.push_back(to_string(row)+to_string(2));
      }
    }
  }
  if (chessBoard->getPiece(row,7) != nullptr) {
    if (chessBoard->getPiece(row,7)->getType() == ROOK && chessBoard->getPiece(row,5) == nullptr && chessBoard->getPiece(row,6) == nullptr) {
      if (static_cast<Rook*>(chessBoard->getPiece(row,7))->getMovedStatus()==0) {
        possibleMoves.push_back(to_string(row)+to_string(6));
      }
    }
  }
  // King cannot be in check
  // King cannot be moved through a square that is under attack
}