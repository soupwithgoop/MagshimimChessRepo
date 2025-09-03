#pragma once

#include "Piece.h"

#define NULLPIECE_SIGN '#'

class NullPiece : public Piece
{
public:
	NullPiece(int row, int col);

	virtual bool isLegalMove(int, int) const;
private:
};