#include "../header/Board.hpp"
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

bool hasMoves(Position piecePos) {
    // Complete function will check if the Character at piecePos has available moves
    return false;
}

bool isValidMovement(Position piecePos, Position movePos) {
    // Complete function will check if the position in movePos exists in the list of possible moves of the Character at piecePos
    return false;
}

string checkPieceColor(Position piecePos) {
    // Complete function will return color of the Character at piecePos
    return "black";
}

Character* Board::addPiece(){
    return nullptr;
}

void Board::movePiece(){
    return;
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

Character* Board::getPiece(int row, int column) {
    return chessBoard[row][column];
}

void Board::setPiece(int row, int column, Character* insertChar) {
    Character* temp = chessBoard[row][column];
    chessBoard[row][column] = insertChar;
    delete temp;
}

void Board::movePiece(int initialRow, int initialColumn, int newRow, int newColumn) {
    Character* temp = chessBoard[initialRow][initialColumn];
    chessBoard[newRow][newColumn] = temp;
    chessBoard[initialRow][initialColumn] = nullptr;
}

