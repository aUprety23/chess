#include "Pieces.h"


//INITIALIZE THE SIZE OF THE RECTANGLE
void Pieces::initRectangle()
{
	//size ; 100 * 100
	rectangle.setSize(sf::Vector2f(100, 100));
}


//----------CONSTRUCTORS AND DESTRUCTORS----------//
Pieces::Pieces(bool color, bool diagonal)
{
	pieceColor = color;
	pieceDiagonal = diagonal;
	initRectangle();
}

Pieces:: Pieces(){}

Pieces::~Pieces()
{
}
//------------------------------------------------//



/*

HIGHLIGHT THE SELECTED PIECE------->> IMPLIMENT LATER


void Pieces::highlight()
{
	rectangle.setFillColor(sf::Color(244, 236, 194, 128));
}

*/



void Pieces::isAttacker(bool value)
{
	attacker = value;
}

bool Pieces::getIsAttacker()
{
	return attacker;
}

bool Pieces::getPieceColor()
{
	return pieceColor;
}

void Pieces::remove()
{
	rectangle.setPosition(sf::Vector2f(1000, 1000));
}

void Pieces::updatePieces()
{
}

void Pieces::renderPieces(sf::RenderTarget& target)
{
	target.draw(rectangle);
}
