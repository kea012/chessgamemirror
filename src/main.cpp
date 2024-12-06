#include <iostream>
#include "../header/Game.hpp"
#include "../header/Board.hpp"
#include "../header/Move.hpp"
#include "../header/QueenMove.hpp"
#include "../header/RookMove.hpp"
#include "../header/BishopMove.hpp"
#include "../header/PawnMove.hpp"
#include "../header/Character.hpp"

using namespace std;

int main() {

    /*Game newGame = Game();

    string print = newGame.getOutputString();

    cout << print;*/

    Board* testBoard = new Board();
    string printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

      // try to get all the up moves for pawn
    if (testBoard->getPiece(1, 4)->getType() == 0){
        PawnMove newMove = PawnMove(testBoard->getPiece(1, 4)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(1, 4);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

    testBoard->movePiece(1, 4, 3, 4);

    printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    if (testBoard->getPiece(6, 4)->getType() == 0){
        PawnMove newMove = PawnMove(testBoard->getPiece(6, 4)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(6, 4);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

    testBoard->movePiece(6, 4, 4, 4);

    printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    // try to get all the up moves for queen
    if (testBoard->getPiece(0, 4)->getType() == 5){
        QueenMove newMove = QueenMove(testBoard->getPiece(0, 4)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(0, 4);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

    testBoard->movePiece(0, 4, 2, 4);

    printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    if (testBoard->getPiece(2, 4)->getType() == 5){
        QueenMove newMove = QueenMove(testBoard->getPiece(2, 4)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(2, 4);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

//rook
    if (testBoard->getPiece(1, 0)->getType() == 0) {
        testBoard->setPiece(1, 0, nullptr);
    }

    printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    // try to get all the up moves for rook
    if (testBoard->getPiece(0, 0)->getType() == 4){
        RookMove newMove = RookMove(testBoard->getPiece(0, 0)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(0, 0);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

    testBoard->movePiece(0, 0, 2, 0);

    printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    if (testBoard->getPiece(2, 0)->getType() == 4){
        RookMove newMove = RookMove(testBoard->getPiece(2, 0)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(2, 0);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

//bishop
    // try to get all the up moves for bishop
    if (testBoard->getPiece(0, 5)->getType() == 3){
        BishopMove newMove = BishopMove(testBoard->getPiece(0, 5)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(0, 5);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

    testBoard->movePiece(0, 5, 5, 0);

    printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    if (testBoard->getPiece(5, 0)->getType() == 3){
        BishopMove newMove = BishopMove(testBoard->getPiece(5, 0)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(5, 0);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

    delete testBoard;
    
    return 0;
}


