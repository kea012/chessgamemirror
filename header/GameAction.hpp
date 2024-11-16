#ifndef GAMEACTION_HPP
#define GAMEACTION_HPP 

#include "../header/Game.hpp"
#include "../header/GameState.hpp"

class GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class InvalidInput : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class CreateGame : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class EndProgram : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class SelectPiece : public GameAction {
    virtual std::string performAction(Game* activeGame);
};

class CheckPiece : public GameAction {
private:
    Position piecePos;
public:
    CheckPiece(Position newPiecePos);
    virtual std::string performAction(Game* activeGame);
};

class SelectMove : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class CheckMove : public GameAction {
private:
    Position movePos;
public:
    CheckMove(Position newMovePos);
    virtual std::string performAction(Game* activeGame);
};

class MovePiece : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class Retire : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

class ReturnToMenu : public GameAction {
public:
    virtual std::string performAction(Game* activeGame);
};

#endif