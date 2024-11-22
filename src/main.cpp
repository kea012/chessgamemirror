#include <iostream>
#include "../header/Game.hpp"
#include "../header/Board.hpp"
#include "../header/Move.hpp"
#include "../header/QueenMove.hpp"

using namespace std;

int main() {

    /*Game newGame = Game();

    string print = newGame.getOutputString();

    cout << print;*/

    Board* testBoard = new Board();
    string printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    //remove pawn in front of queen
    if (testBoard->getPiece(1, 4)->getType() == 0) {
        testBoard->setPiece(1, 4, nullptr);
    }

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

    delete testBoard;
    
    return 0;
}

