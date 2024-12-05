#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include "../header/Position.hpp"

class Position;
class Board;
class GameState;
class GameAction;

enum turn { whiteTurn, blackTurn, noTurn };

/*
// Game outcomes
const int WHITE_WIN = 0;
const int BLACK_WIN = 1;
const int DRAW = 2;
*/

class Game {
private:
    Position piecePos;
    Position movePos;
    Board* gameBoard = nullptr;
    GameState* currGameState = nullptr;
    GameAction* currAction = nullptr;
    turn currTurn;
    std::string outputString;
public:
    Game();
    ~Game();
    Board* getGameBoard();
    turn getTurn();
    Position getSelectedPiecePos();
    Position getSelectedMovePos();
    std::string getOutputString();
    GameState* getGameState();
    bool createNewBoard();
    bool setBoard(Board* newGameBoard);
    void updateGameState(GameState* newGameState);
    bool updateTurn(bool gameEnding = false);
    bool updatePiecePosition(std::string newPosStr);
    bool updateMovePosition(std::string newPosStr);
    void resetPositions();
    void resetWholeGame();
    bool inputToAction(std::string userInput);
    bool performCurrAction();
    bool moveSelectedPiece();
    bool getNewMoves(std::string color);
};

#endif