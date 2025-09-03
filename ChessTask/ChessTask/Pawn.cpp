#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(Player* p, int row, int col, Board* brd) : Piece(p, PAWN_SIGN, row, col, brd)
{
}

bool Pawn::isLegalMove(int dstRow, int dstCol) const
{
    if (!Piece::isLegalMove(dstRow, dstCol)) return false;
    Team dstTeam = _brd->getTeam(dstRow, dstCol);
    if (dstCol == _col) //no capture
    {
        if (this->getPlayer()->getTeam() == WHITE)
            return dstTeam == NONE && (dstRow == _row - 1 || (_row == 6 && dstRow == 4));
        else
            return dstTeam == NONE && (dstRow == _row + 1 || (_row == 1 && dstRow == 3));
    }
    else if (std::abs(dstCol - _col) == 1) //capture
    {
        if (this->getPlayer()->getTeam() == WHITE)
            return dstTeam == BLACK && dstRow == _row - 1;
        else
            return dstTeam == WHITE && dstRow == _row + 1;
    }
    return false;
}