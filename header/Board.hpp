#ifndef _BOARD_H_
#define _BOARD_H_

class Character;
class Pawn;
class King;
class Knight;
class Bishop;
class Rook;
class Queen;
class Position;

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
		Board(const Board& rhs);
		Board& operator=(const Board& rhs);
		~Board();
		bool isSpaceOccupied(std::string position);
		bool isSpaceOccupied(Position pos);
		bool colorHasMoves(std::string checkColor);
		bool pieceHasMoves(Position piecePos);
		bool isValidMovement(Position piecePos, Position movePos);
		std::string checkPieceColor(Position piecePos);
		std::string generateBoard();
		void capturePiece();
		bool stalemate();
		void printBoard(std::string boardString);
		Character* getPiece(int row, int column) const;
		void setPiece(int row, int column, Character* insertChar);
		bool movePiece(int initialRow, int initialColumn, int newRow, int newColumn);
		void pawnPromotion(int row, int column, std::string type);
		bool removePieceFromList(Character* pieceToRemove);
		bool generateAllPlayerMoves();
		bool removeAllSelfCheckMoves(std::string color);
		Position getKingPosition(std::string color);
		bool isKingInCheck(std::string color);
		void clearBoard();
};

#endif
