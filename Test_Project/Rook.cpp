#include "Rook.h"

void Rook::initTextureRook()
{
		if (!texture_blackRook.loadFromFile("images/blackRook.png"))
			std::cout << "ERROR::ROOK::initTEXTURE ROOK::COULD NOT LOAD 'BLACK ROOK' TEXTURE FROM FILE " << std::endl;


		if (!texture_whiteRook.loadFromFile("images/whiteRook.png"))
			std::cout << "ERROR::ROOK::initTEXTUREROOK::COULD NOT LOAD 'WHITE ROOK' TEXTURE FORM FILE " << std::endl;


		texture_blackRook.setSmooth(true);
		texture_whiteRook.setSmooth(true);
	
}

void Rook::initPosition()
{
		//position ; depends on diagonal of bishop and color of the piece;
		if (pieceColor == BLACK && pieceDiagonal == WHITE)
		{
			rectangle.setPosition(sf::Vector2f(0, 0));
		}

		else if (pieceColor == BLACK && pieceDiagonal == BLACK)
		{
			rectangle.setPosition(sf::Vector2f(700, 0));
		}
		else if (pieceColor == WHITE && pieceDiagonal == WHITE)
		{
			rectangle.setPosition(sf::Vector2f(700, 700));
		}
		else if (pieceColor == WHITE && pieceDiagonal == BLACK)
		{
			rectangle.setPosition(sf::Vector2f(0, 700));
		}


		// texture; depends on the color of piece;
		if (pieceColor == BLACK)
			rectangle.setTexture(&texture_blackRook);
		if (pieceColor == WHITE)
			rectangle.setTexture(&texture_whiteRook);
	
}

Rook::Rook(bool color, bool diagonal)
{
	pieceColor = color;
	pieceDiagonal = diagonal;

	initTextureRook();
	initRectangle();
	initPosition();
	initGetPosition();
}

Rook::~Rook()
{
}

void Rook::initGetPosition()
{
	currentPosition = rectangle.getPosition();
}

void Rook::move(sf::Vector2f destination_Position)
{
	rectangle.setPosition(sf::Vector2f(destination_Position.x, destination_Position.y));
}

bool Rook::isLegal(sf::Vector2f destination_Position)
{
	float fileDiff = abs(destination_Position.x - currentPosition.x);
	float rankDiff = abs(destination_Position.y - currentPosition.y);

	if (fileDiff == 0 || rankDiff == 0)
		return true;
	else
		return false;
}

void Rook::updateRook()
{
	this->initGetPosition();
}

void Rook::renderRook(sf::RenderTarget& target)
{
	target.draw(rectangle);
}
