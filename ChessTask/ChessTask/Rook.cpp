#include "Rook.h"

Rook::Rook(Player* p, int row, int col, Board* brd) : Piece(p, ROOK_SIGN, row, col, brd)
{
}

bool Rook::isLegalMove(int dstRow, int dstCol) const
{
	if (!Piece::isLegalMove(dstRow, dstCol)) return false;
	return (dstRow == _row || dstCol == _col) && isWayFree(dstRow, dstCol);
}