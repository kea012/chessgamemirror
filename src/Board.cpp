#include "../header/Board.hpp"
#include "../header/Character.hpp"
#include "../header/Pawn.hpp"
#include "../header/King.hpp"
#include "../header/Knight.hpp"
#include "../header/Bishop.hpp"
#include "../header/Rook.hpp"
#include "../header/Queen.hpp"
#include "../header/Position.hpp"
#include <iostream>

using namespace std;

//Sets up the piece color vectors and sets up pieces on the board
//all indices without pieces are set to nullptr - check if that works in a character pointer class
//tests: check that the pieces are placed properly
//make sure that the piece vectors are set up correctly
Board::Board(){
    // Pawn WP1(w), WP2(w), WP3(w), WP4(w), WP5(w), WP6(w), WP7(w), WP8(w);
    // Pawn BP1, BP2, BP3, BP4, BP5, BP6, BP7, BP8;
    // Rook WR1, WR2, BR1, BR2;
    // King BK, WK;
    // Queen BQ, WQ;
    // Bishop BB1, BB2, WB1, WB2;
    // Knight BN1, BN2, WN1, WN2;
    //whitePiece(0) = WP1;
    int row = 0;
    int column = 0;

    //Push back all white pieces into white piece vector Z
    whitePieces.push_back(new Rook("w"));
    whitePieces.push_back(new Knight("w"));
    whitePieces.push_back(new Bishop("w"));
    whitePieces.push_back(new King("w"));
    whitePieces.push_back(new Queen("w"));
    whitePieces.push_back(new Bishop("w"));
    whitePieces.push_back(new Knight("w"));
    whitePieces.push_back(new Rook("w"));
    for (unsigned int i = 0; i < 8; i++){
        whitePieces.push_back(new Pawn("w"));
    }
    blackPieces.push_back(new Rook("b"));
    blackPieces.push_back(new Knight("b"));
    blackPieces.push_back(new Bishop("b"));
    blackPieces.push_back(new Queen("b"));
    blackPieces.push_back(new King("b"));
    blackPieces.push_back(new Bishop("b"));
    blackPieces.push_back(new Knight("b"));
    blackPieces.push_back(new Rook("b"));
    for (unsigned int i = 0; i < 8; i++){
        blackPieces.push_back(new Pawn("b"));
    }

    row = 0;
    column = 0;
    //set back pieces first then pawns for white
    for (unsigned int i = 0; i < whitePieces.size(); ++i){
        chessBoard[row][column] = whitePieces.at(i);
        column++;
        if (column == 8){
            row++;
            column = 0;
        }
    }
    row = 7;
    column = 0;
    for (unsigned int i = 0; i < blackPieces.size(); ++i){
        chessBoard[row][column] = blackPieces.at(i);
        column++;
        if (column == 8){
            row--;
            column = 0;
        }
    }

    row = 2;
    column = 0;
    for (unsigned int i = 0; i < 32; ++i){ 
        chessBoard[row][column] = nullptr;
        column++;
        if (column == 8){
            row++;
            column = 0;
        }
    }
}

Board::Board(const Board& rhs) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Character* currRhsPiece = rhs.getPiece(row, col);
            if (currRhsPiece == nullptr) {
                continue;
            }
            Character* currPiece = currRhsPiece->clone();
            chessBoard[row][col] = currPiece;
            if (currRhsPiece->getColor() == "w") {
                whitePieces.push_back(currPiece);
            }
            currRhsPiece = nullptr;
            currPiece = nullptr;
        }
    }
}

Board& Board::operator=(const Board& rhs) {
    whitePieces.clear();
    blackPieces.clear();
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            delete chessBoard[row][col];
            chessBoard[row][col] = nullptr;
            Character* currRhsPiece = rhs.getPiece(row, col);
            if (currRhsPiece == nullptr) {
                continue;
            }
            Character* currPiece = currRhsPiece->clone();
            chessBoard[row][col] = currPiece;
            if (currRhsPiece->getColor() == "w") {
                whitePieces.push_back(currPiece);
            }
            currRhsPiece = nullptr;
            currPiece = nullptr;
        }
    }
    return *this;
}

//destructor
Board::~Board() {
    whitePieces.clear();
    blackPieces.clear();
    for (unsigned int row = 0; row < 8; ++row){
        for (unsigned int column = 0; column < 8; ++column){
            delete chessBoard[row][column];
        }
    }
}

bool Board::isSpaceOccupied(std::string position) {
     char column = position.at(0) - '0';
     char row = position.at(1) - '0';
    if (chessBoard[column][row] == nullptr){
        return true;
    }
    return false;
}

bool Board::isSpaceOccupied(Position pos) {
    // Complete function will check if there is a Character at pos
    if (chessBoard[pos.getRow()][pos.getCol()] ==  nullptr){
        return false;
    }
    return true;
}

bool Board::hasMoves(Position piecePos) {
    Character* currPiece = chessBoard[piecePos.getRow()][piecePos.getCol()];
    if (currPiece == nullptr) {
        return false;
    }
    std::vector<Position> currPieceMoveList = currPiece->getMoveList();
    currPiece = nullptr;
    if (currPieceMoveList.empty()) {
        return false;
    }
    return true;
}

bool Board::isValidMovement(Position piecePos, Position movePos) {
    if (!(hasMoves(piecePos))) {
        return false;
    }
    Character* currPiece = chessBoard[piecePos.getRow()][piecePos.getCol()];
    std::vector<Position> currPieceMoveList = currPiece->getMoveList();
    currPiece = nullptr;
    for (int i = 0; i < currPieceMoveList.size(); i++) {
        if (currPieceMoveList.at(i) == movePos) {
            return true;
        }
    }
    return false;
}

string Board::checkPieceColor(Position piecePos) {
    // Complete function will return color of the Character at piecePos
    if (chessBoard[piecePos.getRow()][piecePos.getCol()] == nullptr) {
        return "No piece at position";
    }
    return chessBoard[piecePos.getRow()][piecePos.getCol()]->getColor();
}

void Board::capturePiece(){
    return;
}

bool Board::stalemate(){
    return false;
}

string Board::generateBoard(){
    string board = "";
    for (unsigned int row = 0; row < 8; ++row){
         board += to_string(row+1);
        for (unsigned int column = 0; column < 8; ++column){
            board += "|";
            if (chessBoard[row][column] == nullptr){
                board += " ";
            }
            else{
                board += chessBoard[row][column]->getSymbol();
            }
            board += "|";
        }
        board += "\n";
        board + "  ";
    }
    board += "  A  B  C  D  E  F  G  H";
    return board;
}

void Board::printBoard(string boardString){
    cout << boardString << endl;
}

Character* Board::getPiece(int row, int column) const {
    return chessBoard[row][column];
}

void Board::setPiece(int row, int column, Character* insertChar) {
    Character* temp = chessBoard[row][column];
    if (temp != nullptr) {
        removePieceFromList(temp);
    }
    chessBoard[row][column] = insertChar;
    delete temp;
}

void Board::pawnPromotion(int row, int column, string type) {
    Character* temp = chessBoard[row][column];
    if (temp->getType() == 0) {
        if ((row == 7) && (chessBoard[row][column]->getColor() == "w")) {
            if ("KNIGHT") {
                chessBoard[row][column] = new Knight("w");
            }
            else if ("BISHOP") {
                chessBoard[row][column] = new Bishop("w");
                }
            else if ("ROOK") {
                chessBoard[row][column] = new Rook("w");
            }
            else if ("QUEEN") {
                chessBoard[row][column] = new Queen("w");
            }
            whitePieces.push_back(chessBoard[row][column]);
        }
        else if ((row == 0) && (chessBoard[row][column]->getColor() == "b")) {
            if ("KNIGHT") {
                chessBoard[row][column] = new Knight("b");
            }
            else if ("BISHOP") {
                chessBoard[row][column] = new Bishop("b");
                }
            else if ("ROOK") {
                chessBoard[row][column] = new Rook("b");
            }
            else if ("QUEEN") {
                chessBoard[row][column] = new Queen("b");
            }
            blackPieces.push_back(chessBoard[row][column]);
        }
        removePieceFromList(temp);
        delete temp;
    }
}

void Board::movePiece(int initialRow, int initialColumn, int newRow, int newColumn) {
    Character* temp = chessBoard[initialRow][initialColumn];
    if (chessBoard[newRow][newColumn]) {
        delete chessBoard[newRow][newColumn];
        chessBoard[newRow][newColumn] = nullptr;
    }
    chessBoard[newRow][newColumn] = temp;
    chessBoard[initialRow][initialColumn] = nullptr;
}

bool Board::removePieceFromList(Character* pieceToRemove) {
    if (pieceToRemove->getColor() == "w") {
        for (int i = 0; i < whitePieces.size(); i++) {
            if (whitePieces.at(i) == pieceToRemove) {
                whitePieces.erase(whitePieces.begin() + i);
            }
        }
        return true;
    }
    if (pieceToRemove->getColor() == "b") {
        for (int i = 0; i < blackPieces.size(); i++) {
            if (blackPieces.at(i) == pieceToRemove) {
                blackPieces.erase(blackPieces.begin() + i);
            }
        }
        return true;
    }
    return false;
}

bool Board::generateAllPlayerMoves(std::string color) {
    if (color != "b" && color != "w")
        return false;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Character* currPiece = chessBoard[row][col];
            if (currPiece != nullptr && currPiece->getColor() == color) {
                currPiece->updateMoves(Position(row, col), this);
            }
            currPiece = nullptr;
        }
    }
    removeAllSelfCheckMoves(color);
    return true;
}

bool Board::removeAllSelfCheckMoves(std::string color) {
    if (color != "b" && color != "w") {
        return false;
    }
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Character* currPiece = chessBoard[row][col];
            if (currPiece != nullptr) {
                if (currPiece->getColor() == color) {
                    currPiece->removeSelfCheckMoves(Position(row, col), this);
                }
                currPiece = nullptr;
            }
        }
    }
    return true;
}

Position Board::getKingPosition(std::string color) {
    Position kingPosition;
    if (color != "w" && color != "b") {
        return kingPosition;
    }
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Character* currPiece = chessBoard[row][col];
            if (currPiece != nullptr) {
                if (currPiece->getColor() == color && currPiece->getType() == KING) {
                    currPiece = nullptr;
                    kingPosition.setPositionFromInts(row, col);
                    return kingPosition;
                }
                currPiece = nullptr;
            }
        }
    }
    return kingPosition;
}

bool Board::isKingInCheck(std::string color) {
    Position kingPosition = getKingPosition(color);
    if (kingPosition.isEmptyPosition())
        return false;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Character* currPiece = chessBoard[row][col];
            if (currPiece == nullptr)
                continue;
            std::vector<Position> currPieceMoveList;
            if (color == "w" && currPiece->getColor() == "b") {
                currPieceMoveList = currPiece->getMoveList();
            }
            if (color == "b" && currPiece->getColor() == "w") {
                currPieceMoveList = currPiece->getMoveList();
            }
            currPiece == nullptr;
            for (int i = 0; i < currPieceMoveList.size(); i++) {
                if (currPieceMoveList.at(i) == kingPosition)
                    return true;
            }
        }
    }
    return false;
}

void Board::clearBoard() {
    whitePieces.clear();
    blackPieces.clear();
    for (unsigned int row = 0; row < 8; ++row){
        for (unsigned int column = 0; column < 8; ++column){
            delete chessBoard[row][column];
            chessBoard[row][column] = nullptr;
        }
    }
}