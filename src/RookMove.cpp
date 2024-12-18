#include "../header/RookMove.hpp"
#include "../header/Board.hpp"
#include "../header/Character.hpp"

using namespace std;

RookMove::RookMove(string color, Board* chessBoard) : Move(ROOKMOVE, color), chessBoard(chessBoard) {} 

vector<string> RookMove::generatePossibleMoves(int row, int column) {
    //up the board
    
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
    }
    
    return possibleMoves;
}