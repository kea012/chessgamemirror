#ifndef GAME_HPP
#define GAME_HPP

class Character;
class Board;
class GameState;
class GameAction;


#include "../header/Position.hpp"
#include "../header/Board.hpp"
#include "../header/GameState.hpp"
#include "../header/GameAction.hpp"


#include <string>
#include "../header/Position.hpp"

enum turn { whiteTurn, blackTurn, noTurn };

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