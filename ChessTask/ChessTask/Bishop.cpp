#include "Bishop.h"

Bishop::Bishop(Player* p, int row, int col, Board* brd) : Piece(p, BISHOP_SIGN, row, col, brd)
{
}

bool Bishop::isLegalMove(int dstRow, int dstCol) const
{
	if (!Piece::isLegalMove(dstRow, dstCol)) return false;
	return std::abs(dstRow - _row) == std::abs(dstCol - _col) && isWayFree(dstRow, dstCol);
}