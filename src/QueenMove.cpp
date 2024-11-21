#include "../header/QueenMove.hpp"

using namespace std;

QueenMove::QueenMove(string color, Board chessBoard) : Move(QUEENMOVE, color), chessBoard(chessBoard) {} 

vector<string> QueenMove::generatePossibleMoves(int x, int y) {
    //up the board
    for (int i = y + 1; i < 8; ++i) {
        if (chessBoard.getPiece(x, i) == nullptr){
            possibleMoves.push_back(to_string(x)+to_string(i));
        }
        else if (chessBoard.getPiece(x, i)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(x)+to_string(i));
            break;
        }
    }

    //down the board
    for (int i = y - 1; (i >=0)&&(i < 8); --i) {
        if (chessBoard.getPiece(x, i) == nullptr){
            possibleMoves.push_back(to_string(x)+to_string(i));
        }
        else if (chessBoard.getPiece(x, i)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(x)+to_string(i));
            break;
        }
    }

    //right side of the board
    for (int i = x + 1; i < 8; ++i) {
        if (chessBoard.getPiece(i, y) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(y));
        }
        else if (chessBoard.getPiece(i, y)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(y));
            break;
        }
    }

    //left side of the board;
    for (int i = x - 1; (i >= 0)&&(i < 8); --i) {
        if (chessBoard.getPiece(i, y) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(y));
        }
        else if (chessBoard.getPiece(i, y)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(y));
            break;
        }
    }

    //diagonol up and to the right of the board
    for (int i = x + 1, j = y + 1; (i < 8)&&(j < 8); ++i, ++j) {
        if (chessBoard.getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard.getPiece(i, j)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol up and to the left of the board
    for (int i = x - 1, j = y + 1; (i >= 0)&&(j < 8); --i, ++j) {
        if (chessBoard.getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard.getPiece(i, j)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol down and to the right of the board
    for (int i = x + 1, j = y - 1; (i < 8)&&(j >= 0); ++i, --j) {
        if (chessBoard.getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard.getPiece(i, j)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol down and to the left of the board
    for (int i = x - 1, j = y - 1; (i >= 0)&&(j >= 0); --i, --j) {
        if (chessBoard.getPiece(i, j) == nullptr){
            possibleMoves.push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard.getPiece(i, j)->getColor() == chessBoard.getPiece(x, y)->getColor()) {
            break;
        }
        else {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
    }
    return possibleMoves;
}