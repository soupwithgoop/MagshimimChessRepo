#include "Player.h"
#include "King.h"

Player::Player(bool isWhite) : Player(isWhite, isWhite)
{
}

Player::Player(bool isWhite, bool isUp) 
{
	_pieces = new std::vector<Piece*>();
	_team = isWhite ? WHITE : BLACK;
	_myKing = NULL;
	_isGoingUp = isUp;
}
Player::~Player()
{
}

Team Player::getTeam() const
{
	return _team;
}

void Player::setKing(King* myKing)
{
	_myKing = myKing;
}

King* Player::getKing() const
{
	return _myKing;
}

bool Player::isGoingUp() const
{
	return _isGoingUp;
}

bool Player::isCheckingKing(King* opponentKing) const
{
	for (Piece* piece : *_pieces)
	{
		if (piece->isLegalMove(opponentKing->getRow(), opponentKing->getColumn()))
		{
			return true;
		}
	}
	return false;
}

void Player::addPiece(Piece* piece)
{
	_pieces->push_back(piece);
}

void Player::removePiece(Piece* piece)
{
	auto it = std::find(_pieces->begin(), _pieces->end(), piece);
	if (it != _pieces->end())
	{
		_pieces->erase(it);
	}
}
