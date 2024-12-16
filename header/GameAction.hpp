#ifndef GAMEACTION_HPP
#define GAMEACTION_HPP 

#include <string>
#include <vector>
#include "../header/Position.hpp"

class Game;

class GameAction {
public:
    virtual std::string performAction(Game* activeGame) = 0;  
    virtual ~GameAction() = default;
};

class InvalidInput : public GameAction {
public:
    virtual ~InvalidInput() = default;
    virtual std::string performAction(Game* activeGame);
};

class CreateGame : public GameAction {
public:
    virtual ~CreateGame() = default;
    virtual std::string performAction(Game* activeGame);
};

class EndProgram : public GameAction {
public:
    virtual ~EndProgram() = default;
    virtual std::string performAction(Game* activeGame);
};

class SelectPiece : public GameAction {
    virtual ~SelectPiece() = default;
    virtual std::string performAction(Game* activeGame);
};

class CheckPiece : public GameAction {
private:
    Position piecePos;
public:
    virtual ~CheckPiece() = default;
    CheckPiece(Position newPiecePos);
    virtual std::string performAction(Game* activeGame);
    std::vector<std::string> userDisplayMovements(std::vector<Position> moveList);
};

class SelectMove : public GameAction {
public:
    virtual ~SelectMove() = default;
    virtual std::string performAction(Game* activeGame);
};

class CheckMove : public GameAction {
private:
    Position movePos;
public:
    virtual ~CheckMove() = default;
    CheckMove(Position newMovePos);
    virtual std::string performAction(Game* activeGame);
    
};

class MovePiece : public GameAction {
public:
    virtual ~MovePiece() = default;
    virtual std::string performAction(Game* activeGame);
};

class Retire : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class ReturnToMenu : public GameAction {
public:
    virtual ~ReturnToMenu() = default;
    virtual std::string performAction(Game* activeGame);
};

#endif