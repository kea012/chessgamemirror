#include <iostream>
#include "../header/Board.hpp"

using namespace std;

int main() {

    Board testBoard;
    string printBoard = testBoard.generateBoard();
    testBoard.printBoard(printBoard);
    
    return 0;
}