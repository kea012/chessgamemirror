#include "../header/Game.hpp"
#include <iostream>

using namespace std;

int main() {
    Game chessGame;
    string userInput;

    while (chessGame.getGameState()) {
        cout << chessGame.getOutputString() << endl;
        cin >> userInput;
        chessGame.inputToAction(userInput);
        chessGame.performCurrAction();
    }

    return 0;
}