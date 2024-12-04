#include "../header/QueenMove.hpp"
#include "../header/Board.hpp"
#include "../header/Character.hpp"

using namespace std;

QueenMove::QueenMove(string color, Board* chessBoard) : Move(QUEENMOVE, color), chessBoard(chessBoard) {} 

vector<string> QueenMove::generatePossibleMoves(int row, int column) {
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
    }
    if (possibleMoves.size() == 0) {
        possibleMoves.push_back("0");
    }
    return possibleMoves;
}