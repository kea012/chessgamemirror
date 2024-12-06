#include "../header/KnightMove.hpp"

using namespace std;

KnightMove::KnightMove(std::string color, Board* chessBoard) : Move(KNIGHTMOVE, color), chessBoard(chessBoard) {}

vector<string> KnightMove::generatePossibleMoves(int row, int column) {
  int newRow = row+1;
  int newColumn = column+2;
  if (newRow<8 && newColumn<8) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  newRow = row+2;
  newColumn = column+1;
  if (newRow<8 && newColumn<8) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  newRow = row+2;
  newColumn = column-1;
  if (newRow<8 && newColumn>=0) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  newRow = row+1;
  newColumn = column-2;
  if (newRow<8 && newColumn>=0) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  newRow = row-1;
  newColumn = column-2;
  if (newRow>=0 && newColumn>=0) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  newRow = row-2;
  newColumn = column-1;
  if (newRow>=0 && newColumn>=0) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  newRow = row-2;
  newColumn = column+1;
  if (newRow>=0 && newColumn<8) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  newRow = row-1;
  newColumn = column+2;
  if (newRow>=0 && newColumn<8) {
    if (chessBoard->getPiece(newRow,column+2) != nullptr) {
      if (color != chessBoard->getPiece(newRow,newColumn)->getColor())
        possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
    }
    else
      possibleMoves.push_back(to_string(newRow)+to_string(newColumn));
  }

  return possibleMoves;
}