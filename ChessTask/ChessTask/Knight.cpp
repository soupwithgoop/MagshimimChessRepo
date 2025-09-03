#include "Knight.h"

Knight::Knight(Player* p , int row, int col, Board* brd) : Piece(p, KNIGHT_SIGN, row, col, brd)
{
}

bool Knight::isLegalMove(int dstRow, int dstCol) const
{
    if (!Piece::isLegalMove(dstRow, dstCol)) return false;
    int rowDiff = std::abs(dstRow - _row);
    int colDiff = std::abs(dstCol - _col);
    return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}