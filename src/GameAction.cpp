#include "../header/GameAction.hpp"

// InvalidInput functions

std::string InvalidInput::performAction(Game* activeGame) {
    return "Invalid input";
}

// CreateGame functions

std::string CreateGame::performAction(Game* activeGame) {
    /*
    if (!activeGame->createNewBoard()) {
        activeGame->updateGameState(new MenuScreen);
        activeGame->resetWholeGame();
        return "CRITICAL ERROR: Reseting...\nWELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
    }
    */
    activeGame->updateGameState(new TurnStart);
    activeGame->updateTurn();
    return "Starting new game...\nWhite player's turn\nEnter 'M' to make a move or 'Q' to quit game";
}

// EndProgram functions

std::string EndProgram::performAction(Game* activeGame) {
    activeGame->updateGameState(nullptr);
    return "Ending program...";
}

// SelectPiece functions

std::string SelectPiece::performAction(Game* activeGame) {
    activeGame->updateGameState(new SelectingPiece);
    return "Enter a position to select a piece";
}

// CheckPiece functions

CheckPiece::CheckPiece(Position newPiecePos) {
    piecePos.setPositionFromString(newPiecePos.getPositionString());
}

std::string CheckPiece::performAction(Game* activeGame) {
    /*
    Character* tempChar = activeGame->getGameBoard()->getPiece(piecePos.getRow(), piecePos.getCol());
    turn currTurn = activeGame->getTurn();
    // Case where selected position does not contain one of the current player's pieces
    if (tempChar == nullptr || (currTurn == whiteTurn && tempChar->getColor() == "b")
        || (currTurn == blackTurn && tempChar->getColor() == "w")) {
        activeGame->updateGameState(new SelectingPiece);
        tempChar = nullptr;
        return "Selected position does not contain one of your pieces\nEnter a position to select a piece";
    }
    if (false) { // Case where selected position contains current player's piece but piece has no legal moves
        activeGame->updateGameState(new SelectingPiece);
        tempChar = nullptr;
        return "Selected piece has no legal moves\nEnter a position to select a piece";
    }
    tempChar = nullptr;
    */
    activeGame->updatePiecePosition(piecePos.getPositionString());
    activeGame->updateGameState(new SelectingMove);
    return "Enter a position to move selected piece to or 'R' to select a different piece";
}

// SelectMove functions

std::string SelectMove::performAction(Game* activeGame) {
    activeGame->updateGameState(new SelectingMove);
    return "Enter a position to move selected piece to";
}

// CheckMove functions

CheckMove::CheckMove(Position newMovePos) {
    movePos.setPositionFromString(newMovePos.getPositionString());
}

std::string CheckMove::performAction(Game* activeGame) {
    if (false) { // User selected position that selected piece cannot move to
        activeGame->updateGameState(new SelectingMove);
        return "Select a valid position";
    }
    activeGame->updateMovePosition(movePos.getPositionString());
    activeGame->updateGameState(new ConfirmingMove);
    return "Enter 'C' to confirm movement or 'R' to select a different position";
}

// MovePiece functions

std::string MovePiece::performAction(Game* activeGame) {
    activeGame->moveSelectedPiece();
    std::string initialPos = activeGame->getSelectedPiecePos().getPositionString();
    std::string finalPos = activeGame->getSelectedMovePos().getPositionString();
    activeGame->resetPositions();
    std::string newOutputString = "Moved piece from " + initialPos + " to " + finalPos;
    if (false) { // Check for any game ending conditions
        activeGame->updateGameState(new EndScreen);
        if (false) { // Someone won
            newOutputString += "\nSomeone won the game";
        }
        else { // Draw
            newOutputString += "\nThe game ended in a draw";
        }
        activeGame->updateTurn(true);
        newOutputString += "\nEnter 'S' to start a new game or 'Q' to return to the menu";
        return newOutputString;
    }
    activeGame->updateTurn();
    activeGame->updateGameState(new TurnStart);
    if (activeGame->getTurn() == whiteTurn) {
        newOutputString += "\nWhite player's turn";
    }
    else if (activeGame->getTurn() == blackTurn) {
        newOutputString += "\nBlack player's turn";
    }
    newOutputString += "\nEnter 'M' to make a move or 'Q' to quit";
    return newOutputString;
}

// Retire functions

std::string Retire::performAction(Game* activeGame) {
    std::string newOutputString;
    if (activeGame->getTurn() == whiteTurn) {
        newOutputString = "White has retired, so black has won the game";
    }
    else if (activeGame->getTurn() == blackTurn) {
        newOutputString = "Black has retired, so white has won the game";
    }
    activeGame->updateGameState(new EndScreen);
    activeGame->updateTurn(true);
    newOutputString += "\nEnter 'S' to start a new game or 'Q' to return to the menu";
    return newOutputString;
}

// ReturnToMenu functions

std::string ReturnToMenu::performAction(Game* activeGame) {
    activeGame->updateGameState(new MenuScreen);
    return "WELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
}