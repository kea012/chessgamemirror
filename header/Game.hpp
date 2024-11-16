#ifndef GAME_HPP
#define GAME_HPP

#include "../header/Position.hpp"
#include "../header/Board.hpp"
#include "../header/GameState.hpp"
#include <string>

enum turn { whiteTurn, blackTurn, noTurn };

// Game outcomes
const int WHITE_WIN = 0;
const int BLACK_WIN = 1;
const int DRAW = 2;

class Game {
private:
    Position piecePos;
    Position movePos;
    Board* gameBoard = nullptr;
    GameState* currGameState = nullptr;
    GameAction* currAction = nullptr;
    turn currTurn;
    std::string outputStr;
public:
    Game();
    ~Game();
    Board* getGameBoard();
    turn getTurn();
    std::string getOutputString();
    GameState* getGameState();
    void updateGameState(GameState* newGameState);
    bool updateTurn(bool gameEnding = false);
    bool updatePiecePosition(std::string newPosStr);
    bool updateMovePosition(std::string newPosStr);
    bool inputToAction(std::string userInput);
    bool performCurrAction();
    bool moveSelectedPiece();
};

#endif