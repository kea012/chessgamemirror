#include "../header/PawnMove.hpp"

using namespace std;

PawnMove::PawnMove(string color, Board* chessBoard) : Move(PAWNMOVE, color), chessBoard(chessBoard) {} 

vector<string> PawnMove::generatePossibleMoves(int row, int column) {

    //if white the piece moves forward down the board
    //if (chessBoard->getPiece(row, column)->getColor() == "w") {
        for (int i = row + 1; i < 8; ++i) {
            if (chessBoard->getPiece(i, column) == nullptr){
                possibleMoves.push_back(to_string(i)+to_string(column));
            }
            if (row != 1) {
                break;
            }
        }
    //}

    //diagonol down and to the right of the board
    //if (chessBoard->getPiece(row, column)->getColor() == "w") {
        for (int i = row + 1, j = column + 1; (i < 8)&&(j < 8); ++i, ++j) {
            if (chessBoard->getPiece(i, j)->getColor() != chessBoard->getPiece(row, column)->getColor()) {
                possibleMoves.push_back(to_string(i)+to_string(j));
                break;
            }
        }
    //}

    //diagonol down and to the left of the board
    //if (chessBoard->getPiece(row, column)->getColor() == "w") {
        for (int i = row + 1, j = column - 1; (i < 8)&&(j >= 8); ++i, --j) {
            if (chessBoard->getPiece(i, j)->getColor() != chessBoard->getPiece(row, column)->getColor()) {
                possibleMoves.push_back(to_string(i)+to_string(j));
                break;
            }
        }
    //}


    //if black the piece moves forward up the board
    //if (chessBoard->getPiece(row, column)->getColor() == "b") {
        for (int i = row - 1; (i >=0)&&(i < 8); --i) {
            if (chessBoard->getPiece(i, column) == nullptr){
                possibleMoves.push_back(to_string(i)+to_string(column));
            }
            if (row != 6) {
                break;
            }
        }
    //}

    //diagnol up and to the right of the board
    //if (chessBoard->getPiece(row, column)->getColor() == "b") {
        for (int i = row - 1, j = column + 1; (i >= 0)&&(j < 8); --i, ++j) {
            if (chessBoard->getPiece(i, j)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
                possibleMoves.push_back(to_string(i)+to_string(j));
                break;
            }
        }
    //}

    //diagnol up and to the left of the board
    for (int i = row - 1, j = column - 1; (i >= 0)&&(j >= 0); --i, --j) {
        if (chessBoard->getPiece(i, j)->getColor() == chessBoard->getPiece(row, column)->getColor()) {
            possibleMoves.push_back(to_string(i)+to_string(j));
            break;
        }
    }

    return possibleMoves; 

}