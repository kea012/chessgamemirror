#include "../header/PawnMove.hpp"

using namespace std;

PawnMove::PawnMove(string color, Board* chessBoard) : Move(PAWNMOVE, color), chessBoard(chessBoard) {} 

vector<string> PawnMove::generatePossibleMoves(int row, int column) {

    //if white the piece moves forward up the board
    if (chessBoard->getPiece(row, column)->getColor() == "w") {
        for (int i = row + 1; i < 8; ++i) {
            if (chessBoard->getPiece(i, column) == nullptr){
                possibleMoves.push_back(to_string(i)+to_string(column));
            }
            if (row != 1) {
                break;
            }
        }
    }

    count = 0;

    //if black the piece moves forward up the board
    if (chessBoard->getPiece(row, column)->getColor() == "w") {
        for (int i = row - 1; i < 8; --i) {
            if (chessBoard->getPiece(i, column) == nullptr){
                possibleMoves.push_back(to_string(i)+to_string(column));
            }
            if (row != 6) {
                break;
            }
        }
    }
    
    /*//diagonol up and to the right of the board as well as en passant
    for (int i = x + 1, j = y + 1; (i < 8)&&(j < 8); ++i, ++j) {
        if ((board[i][j-1].getColor() != this->getColor()) && ((j-1) == 3)) {
            if(board[i][j-1].getMovedStatus() == true) {
                move->push_back(to_string(i)+to_string(j)); 
            }
        }
        if (board[i][j].is_empty()){
            break;
        }
        else if (board[i][j].getColor() != this->getColor()) {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    }

    //diagnol up and to the left of the board as well as en passant
    for (int i = x - 1, j = y + 1; (i >= 0)&&(j < 8); --i, ++j) {
        if ((board[i][j-1].getColor() != this->getColor()) && ((j-1) == 3)) {
            if(board[i][j-1].getMovedStatus() == true) {
                move->push_back(to_string(i)+to_string(j)); 
            }
        }
        if (board[i][j].is_empty()){
            break;
        }
        else if (board[i][j].getColor() != this->getColor()) {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    } */
     
    return move; 
}