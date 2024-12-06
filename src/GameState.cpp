#include "../header/GameState.hpp"
#include "../header/Game.hpp"
#include "../header/GameAction.hpp"

// MenuScreen functions

GameAction* MenuScreen::parseUserInput(std::string userInput) {
    if (userInput == "s" || userInput == "S") {
        return new CreateGame();
    }
    if (userInput == "q" || userInput == "Q") {
        return new EndProgram();
    }
    return new InvalidInput();
}

// EndScreen functions

GameAction* EndScreen::parseUserInput(std::string userInput) {
    if (userInput == "s" || userInput == "S") {
        return new CreateGame();
    }
    if (userInput == "q" || userInput == "Q") {
        return new ReturnToMenu();
    }
    return new InvalidInput();
}

// TurnStart functions

GameAction* TurnStart::parseUserInput(std::string userInput) {
    if (userInput == "m" || userInput == "M") {
        return new SelectPiece();
    }
    if (userInput == "q" || userInput == "Q") {
        return new Retire();
    }
    return new InvalidInput();
}

// SelectingPiece functions

GameAction* SelectingPiece::parseUserInput(std::string userInput) {
    Position newPiecePos;
    if (!newPiecePos.setPositionFromString(userInput))
        return new InvalidInput();
    return new CheckPiece(newPiecePos);
}

// SelectingMove functions

GameAction* SelectingMove::parseUserInput(std::string userInput) {
    if (userInput == "r" || userInput == "R") {
        return new SelectPiece();
    }
    Position newMovePos;
    if (!newMovePos.setPositionFromString(userInput))
        return new InvalidInput();
    return new CheckMove(newMovePos);
}

// ConfirmingMove functions

GameAction* ConfirmingMove::parseUserInput(std::string userInput) {
    if (userInput == "c" || userInput == "C") {
        return new MovePiece();
    }
    if (userInput == "r" || userInput == "R") {
        return new SelectMove();
    }
    return new InvalidInput();
}