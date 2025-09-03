#pragma once

#include <vector>
#include "Piece.h"
#include "Team.h"

class Piece;
class King;

class Player
{
public:
	Player(bool isWhite);
	Player(bool isWhite, bool isUp);
	~Player();
	void setKing(King*);
	King* getKing() const;
	Team getTeam() const;
	bool isGoingUp() const;
	bool isCheckingKing(King*) const;
	void addPiece(Piece*);
	void removePiece(Piece*);
private:
	King* _myKing;
	Team _team;
	bool _isGoingUp;
	std::vector<Piece*>* _pieces;
};

