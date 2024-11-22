#include "../header/KnightMove.hpp"

using namespace std;

KnightMove::KnightMove(std::string color, Board* chessBoard) : Move(KNIGHTMOVE, color), chessBoard(chessBoard) {}

vector<string> KnightMove::generatePossibleMoves(int row, int column) {
  if (row+1<8 && column+2<8 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row+1,column+2)->getColor()) {
    possibleMoves.push_back(to_string(row+1)+to_string(column+2));
  }
  if (row+2<8 && column+1<8 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row+2,column+1)->getColor()) {
    possibleMoves.push_back(to_string(row+2)+to_string(column+1));
  }
  if (row+2<8 && column-1>=0 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row+2,column-1)->getColor()) {
    possibleMoves.push_back(to_string(row+2)+to_string(column-1));
  }
  if (row+1<8 && column-2>=0 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row+1,column-2)->getColor()) {
    possibleMoves.push_back(to_string(row+1)+to_string(column-2));
  }
  if (row-1>=0 && column-2>=0 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row-1,column-2)->getColor()) {
    possibleMoves.push_back(to_string(row-1)+to_string(column-2));
  }
  if (row-2>=0 && column-1>=0 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row-2,column-1)->getColor()) {
    possibleMoves.push_back(to_string(row-2) + std::to_string(column-1));
  }
  if (row-2>=0 && column+1<8 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row-2,column+1)->getColor()) {
    possibleMoves.push_back(to_string(row-2)+to_string(column+1));
  }
  if (row-1>=0 && column+2<8 && chessBoard->getPiece(row,column)->getColor() != chessBoard->getPiece(row-1,column+2)->getColor()) {
    possibleMoves.push_back(to_string(row-1) + std::to_string(column+2));
  }

  // if (possibleMoves.size() == 0) {
  //   possibleMoves.push_back("0");
  // }
  return possibleMoves;
}