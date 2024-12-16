#include "../header/PawnMove.hpp"
#include "../header/Board.hpp"
#include "../header/Character.hpp"

using namespace std;

PawnMove::PawnMove(string color, Board* chessBoard) : Move(PAWNMOVE, color), chessBoard(chessBoard) {} 

vector<string> PawnMove::generatePossibleMoves(int row, int column) {


    possibleMoves.clear();

    //if white the piece moves forward down the board
    if (chessBoard->getPiece(row, column)->getColor() == "w") {
        if (row + 1 < 8 && chessBoard->getPiece(row + 1, column) == nullptr){
            possibleMoves.push_back(to_string(row + 1)+to_string(column));

            if (row == 1 && chessBoard->getPiece(row + 2, column) == nullptr){
                possibleMoves.push_back(to_string(row + 2) + to_string(column));
            }
        }

        
    }

    //diagonol down and to the right of the board
    if (row + 1 < 8 && column + 1 < 8) {
        Character* targetPiece = chessBoard->getPiece(row + 1, column + 1);
        if (targetPiece != nullptr && targetPiece->getColor() != chessBoard->getPiece(row, column)->getColor()) {
            possibleMoves.push_back(to_string(row + 1) + to_string(column + 1));
        }
    }

    //diagonal down and to the left of the board
    if (row + 1 < 8 && column - 1 >= 0) {
    Character* targetPiece = chessBoard->getPiece(row + 1, column - 1);
    if (targetPiece != nullptr && targetPiece->getColor() != chessBoard->getPiece(row, column)->getColor()) {
        possibleMoves.push_back(to_string(row + 1) + to_string(column - 1));
    }
}

    //diagonol down and to the left en passant
    if (row == 4 && column - 1 >= 0) {
        Character* adjacentPiece = chessBoard->getPiece(row, column - 1);
        if (adjacentPiece != nullptr && adjacentPiece->getType() == PAWN &&
         adjacentPiece->getColor() != chessBoard->getPiece(row, column)->getColor() && adjacentPiece->getMovedStatus() == 1) {
            possibleMoves.push_back(to_string(row + 1) + to_string(column - 1));
        }
    }

    //    if (chessBoard->getPiece(row, column)->getColor() == "w") {
    //     for (int i = row + 1, j = column + 1; (i < 8)&&(j < 8); ++i, ++j) {
    //         if (chessBoard->getPiece(i, j) == nullptr){
    //             if (chessBoard->getPiece(row, j) != nullptr && row == 4) {
    //                 if ((chessBoard->getPiece(row, j)->getType() == 0) && (chessBoard->getPiece(row, j)->getColor() != chessBoard->getPiece(row, column)->getColor())) {
    //                     if (chessBoard->getPiece(row, j)->getMovedStatus() == 1) {
    //                         possibleMoves.push_back(to_string(i)+to_string(j));
    //                     }
    //                 }
    //             }
    //             break;
    //         }
    //         else if (chessBoard->getPiece(i, j)->getColor() != chessBoard->getPiece(row, column)->getColor()) {
    //             possibleMoves.push_back(to_string(i)+to_string(j));
    //             break;
    //         }
    //     }
    // }
    // //diagonol down and to the left of the board and en passant
    // if (chessBoard->getPiece(row, column)->getColor() == "w") {
    //     for (int i = row + 1, j = column - 1; (i < 8)&&(j >= 0); ++i, --j) {
    //         if (chessBoard->getPiece(i, j) == nullptr){
    //             if (chessBoard->getPiece(row, j) != nullptr && row == 4) {
    //                 if ((chessBoard->getPiece(row, j)->getType() == 0) && (chessBoard->getPiece(row, j)->getColor() != chessBoard->getPiece(row, column)->getColor())) {
    //                     if (chessBoard->getPiece(row, j)->getMovedStatus() == 1) {
    //                         possibleMoves.push_back(to_string(i)+to_string(j));
    //                     }
    //                 }
    //             }
    //             break;
    //         }
    //         else if (chessBoard->getPiece(i, j)->getColor() != chessBoard->getPiece(row, column)->getColor()) {
    //             possibleMoves.push_back(to_string(i)+to_string(j));
    //             break;
    //         }
    //     }
    // }

    //white en passant right
    if (row == 4 && column + 1 < 8) {
        Character* adjacentPiece = chessBoard->getPiece(row, column + 1);
        if (adjacentPiece != nullptr && adjacentPiece->getType() == PAWN && adjacentPiece->getColor() != chessBoard->getPiece(row, column)->getColor() && adjacentPiece->getMovedStatus() == 1 ){
            possibleMoves.push_back(to_string(row + 1) + to_string(column + 1));
        }
    }


    //if black the piece moves forward up the board
    if (chessBoard->getPiece(row, column)->getColor() == "b") {
        if (row - 1 >= 0 && chessBoard->getPiece(row - 1, column) == nullptr){
            possibleMoves.push_back(to_string(row - 1)+to_string(column));

            if (row == 6 && row - 2 >= 0 && chessBoard->getPiece(row - 2, column) == nullptr){
                possibleMoves.push_back(to_string(row - 2) + to_string(column));
            }
        }

        
    }

    //diagnol up and to the right of the board
    if (row - 1 >= 0 && column + 1 < 8) {
        Character* targetPiece = chessBoard->getPiece(row - 1, column + 1);
        if (targetPiece != nullptr && targetPiece->getColor() != chessBoard->getPiece(row, column)->getColor()) {
            possibleMoves.push_back(to_string(row - 1) + to_string(column + 1));
        }
    }

    //diagnol up and to the left of the board
    if (row - 1 >= 0 && column - 1 >= 0) {
        Character* targetPiece = chessBoard->getPiece(row - 1, column - 1);
        if (targetPiece != nullptr && targetPiece->getColor() != chessBoard->getPiece(row, column)->getColor()) {
            possibleMoves.push_back(to_string(row - 1) + to_string(column - 1));
        }
    }

    // black en passant right
    if (row == 3 && column + 1 < 8) {
        Character* adjacentPiece = chessBoard->getPiece(row, column + 1);
        if (adjacentPiece != nullptr && adjacentPiece->getType() == PAWN && adjacentPiece->getColor() != chessBoard->getPiece(row, column)->getColor() && adjacentPiece->getMovedStatus() == 1) {
            possibleMoves.push_back(to_string(row - 1) + to_string(column + 1));
        }
    }

    // black en passant left
    if (row == 3 && column - 1 >= 0) {
        Character* adjacentPiece = chessBoard->getPiece(row, column - 1);
        if (adjacentPiece != nullptr && adjacentPiece->getType() == PAWN && adjacentPiece->getColor() != chessBoard->getPiece(row, column)->getColor() && adjacentPiece->getMovedStatus() == 1) {
            possibleMoves.push_back(to_string(row - 1) + to_string(column - 1));
        }
    }

    return possibleMoves; 
}