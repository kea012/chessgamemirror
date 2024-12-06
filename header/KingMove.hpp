#ifndef KINGMOVE_HPP
#define KINGMOVE_HPP

#include "../header/Move.hpp"
#include "../header/Board.hpp"
#include "../header/Character.hpp"
#include "../header/King.hpp"
#include "../header/Rook.hpp"

class Board;

class KingMove : public Move {
  private: 
    Board* chessBoard;
  public:
    KingMove(std::string color, Board* chessBoard);
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
    void castling(int row, int column);
};

#endif // KINGMOVE_HPP