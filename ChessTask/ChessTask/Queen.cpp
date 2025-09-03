#include "Queen.h"

Queen::Queen(Player* p, int row, int col, Board* brd) : Piece(p, QUEEN_SIGN, row, col, brd)
{
}

bool Queen::isLegalMove(int dstRow, int dstCol) const
{
	if (!Piece::isLegalMove(dstRow, dstCol)) return false;
	return (dstRow == _row || dstCol == _col || std::abs(dstRow - _row) == std::abs(dstCol - _col)) && isWayFree(dstRow, dstCol);
}