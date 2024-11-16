#include "../header/Game.hpp"

Game::Game() {
    currGameState = new MenuScreen();
    currTurn = noTurn;
}

Game::~Game() {
    if (gameBoard != nullptr)
        delete gameBoard;
    if (currGameState != nullptr)
        delete currGameState;
    if (currAction != nullptr)
        delete currAction;
}

Board* Game::getGameBoard() {
    return gameBoard;
}

turn Game::getTurn() {
    return currTurn;
}

std::string Game::getOutputString() {
    return outputStr;
}

void Game::updateGameState(GameState* newGameState) {
    delete currGameState;
    currGameState = newGameState;
}

bool Game::updateTurn(bool endingGame = false) {
    if (currTurn = noTurn) {
        return false;
    }
    if (endingGame) {
        currTurn = noTurn;
    }
    else {
        if (currTurn == whiteTurn) {
            currTurn = blackTurn;
        }
        else if (currTurn == blackTurn) {
            currTurn = whiteTurn;
        }
    }
    return true;
}

bool Game::updatePiecePosition(std::string newPosStr) {
    return piecePos.setPositionFromString(newPosStr);
}

bool Game::updateMovePosition(std::string newPosStr) {
    return movePos.setPositionFromString(newPosStr);
}

bool Game::inputToAction(std::string userInput) {
    if (!currGameState)
        return false;
    currAction = currGameState->parseUserInput(userInput);
    return true;
}

bool Game::performCurrAction() {
    if (!currAction)
        return false;
    outputStr = currAction->performAction(this);
    return true;
}