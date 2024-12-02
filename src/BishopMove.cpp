#include "../header/BishopMove.hpp"

using namespace std;

BishopMove::BishopMove(string color, Board* chessBoard) : Move(BISHOPMOVE, color), chessBoard(chessBoard) {} 

vector<string> BishopMove::generatePossibleMoves(int row, int column) {

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