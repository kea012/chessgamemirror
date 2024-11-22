#ifndef _BOARD_H_
#define _BOARD_H_

#include "../header/Character.hpp"
#include "../header/Pawn.hpp"
#include "../header/King.hpp"
#include "../header/Knight.hpp"
#include "../header/Bishop.hpp"
#include "../header/Rook.hpp"
#include "../header/Queen.hpp"
#include "../header/Position.hpp"

#include <string>
#include <vector>

class Character;

class Board {
	protected:
		Character* chessBoard[8][8] = {nullptr}; 
	private:
		std::vector<Character*> whitePieces;
		std::vector<Character*> blackPieces;
	public:
		Board();
		~Board();
		bool isSpaceOccupied(std::string position);
		bool isSpaceOccupied(Position pos);
		bool hasMoves(Position piecePos);
		bool isValidMovement(Position piecePos, Position movePos);
		std::string checkPieceColor(Position piecePos);
		std::string generateBoard();
		Character* addPiece();
		void movePiece();
		void capturePiece();
		bool stalemate();
		void printBoard(std::string boardString);
		Character* getPiece(int row, int column);
		void setPiece(int row, int column, Character* insertChar);
		void movePiece(int initialRow, int initialColumn, int newRow, int newColumn);
};

#endif
