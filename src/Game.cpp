#include "../header/Game.hpp"

Game::Game() {
    currGameState = new MenuScreen();
    currTurn = noTurn;
    outputString = "WELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
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

Position Game::getSelectedPiecePos() {
    return piecePos;
}

Position Game::getSelectedMovePos() {
    return movePos;
}

std::string Game::getOutputString() {
    return outputString;
}

GameState* Game::getGameState() {
    return currGameState;
}

void Game::updateGameState(GameState* newGameState) {
    delete currGameState;
    currGameState = newGameState;
}

bool Game::updateTurn(bool gameEnding) {
    if (gameEnding) {
        if (currTurn == noTurn)
            return false;
        else
            currTurn = noTurn;
    }
    else {
        switch(currTurn) {
            case(noTurn):
                currTurn = whiteTurn;
                break;
            case(whiteTurn):
                currTurn = blackTurn;
                break;
            case(blackTurn):
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

void Game::resetPositions() {
    piecePos.resetPosition();
    movePos.resetPosition();
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
    outputString = currAction->performAction(this);
    return true;
}

bool Game::moveSelectedPiece() {
    return true;
}