#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "../header/Game.hpp"
#include "../header/GameAction.hpp"
#include <string>
#include <cctype>

class Game;
class GameAction;

class GameState {
public:
    virtual GameAction* parseUserInput(std::string userInput) = 0;
};

class MenuScreen : public GameState {
public:
    virtual GameAction* parseUserInput(std::string userInput);
};

class EndScreen : public GameState {
public:
    virtual GameAction* parseUserInput(std::string userInput);
};

class TurnStart : public GameState {
public:
    virtual GameAction* parseUserInput(std::string userInput); 
};

class SelectingPiece : public GameState {
public:
    virtual GameAction* parseUserInput(std::string userInput); 
};

class SelectingMove : public GameState {
public:
    virtual GameAction* parseUserInput(std::string userInput); 
};

class ConfirmingMove : public GameState {
public:
    virtual GameAction* parseUserInput(std::string userInput); 
};

#endif