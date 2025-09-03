#include "King.h"

King::King(Player* p, int row, int col, Board* brd) : Piece(p, KING_SIGN, row, col, brd)
{
}

bool King::isLegalMove(int dstRow, int dstCol) const
{
    if (!Piece::isLegalMove(dstRow, dstCol)) return false;
    return std::abs(dstRow - _row) <= 1 && std::abs(dstCol - _col) <= 1;
}
