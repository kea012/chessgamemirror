#include "../header/KingMove.hpp"
#include "../header/Board.hpp"
#include "../header/Character.hpp"


using namespace std;

KingMove::KingMove(string color, Board* chessBoard) : Move(KINGMOVE, color), chessBoard(chessBoard) {}

vector<string> KingMove::generatePossibleMoves(int row, int column) {
    for (int i = row + 1; i < 8; ++i) {
        if (chessBoard->getPiece(i, column) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(column));
        }
        else if (chessBoard->getPiece(i, column)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(column));
            break;
        }
        break;
    }

    //down the board
    for (int i = row - 1; (i >=0)&&(i < 8); --i) {
        if (chessBoard->getPiece(i, column) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(column));
        }
        else if (chessBoard->getPiece(i, column)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(column));
            break;
        }
        break;
    }

    //right side of the board
    for (int i = column + 1; i < 8; ++i) {
        if (chessBoard->getPiece(row, i) == nullptr){
            possibleMoves.push_back(to_string(row)+to_string(i));
        }
        else if (chessBoard->getPiece(row, i)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(row)+to_string(i));
            break;
        }
        break;
    }

    //left side of the board;
    for (int i = column - 1; (i >= 0)&&(i < 8); --i) {
        if (chessBoard->getPiece(row, i) == nullptr){
            possibleMoves.push_back(to_string(row)+to_string(i));
        }
        else if (chessBoard->getPiece(row, i)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(row)+to_string(i));
            break;
        }
        break;
    }

    //diagonol down and to the right of the board
    for (int i = row + 1, j = column + 1; (i < 8)&&(j < 8); ++i, ++j) {
        if (chessBoard->getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard->getPiece(i, j)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    }

    //diagnol up and to the right of the board
    for (int i = row - 1, j = column + 1; (i >= 0)&&(j < 8); --i, ++j) {
        if (chessBoard->getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard->getPiece(i, j)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    }

    //diagnol down and to the left of the board
    for (int i = row + 1, j = column - 1; (i < 8)&&(j >= 0); ++i, --j) {
        if (chessBoard->getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard->getPiece(i, j)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    }

    //diagnol up and to the left of the board
    for (int i = row - 1, j = column - 1; (i >= 0)&&(j >= 0); --i, --j) {
        if (chessBoard->getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard->getPiece(i, j)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    }
    
    if (static_cast<King*>(chessBoard->getPiece(row,column))->getMovedStatus()==0) {
        castling(row, column);
    }

    return possibleMoves;
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