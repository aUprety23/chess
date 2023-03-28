#include "King.h"


void King::initTextureKing()
{
	if (!texture_blackKing.loadFromFile("images/blackKing.png"))
		std::cout << "ERROR::KING::initTEXTUREKING::COULD NOT LOAD 'BLACK KING' TEXTURE FROM FILE " << std::endl;


	if (!texture_whiteKing.loadFromFile("images/whiteKing.png"))
		std::cout << "ERROR::KING::initTEXTUREKING::COULD NOT LOAD 'WHITE KING' TEXTURE FORM FILE " << std::endl;


	texture_blackKing.setSmooth(true);
	texture_whiteKing.setSmooth(true);
}

void King::initPosition()
{
	//position ; depends on diagonal of bishop and color of the piece;
	if (pieceColor == BLACK) //&& pieceDiagonal == WHITE)
	{
		rectangle.setPosition(sf::Vector2f(400, 0));
	}


	else if (pieceColor == WHITE)// && pieceDiagonal == WHITE)
	{
		rectangle.setPosition(sf::Vector2f(400, 700));
	}

	// texture; depends on the color of piece;
	if (pieceColor == BLACK)
		rectangle.setTexture(&texture_blackKing);
	else if (pieceColor == WHITE)
		rectangle.setTexture(&texture_whiteKing);
}

King::King(bool color, bool diagonal)
{
	pieceColor = color;
	pieceDiagonal = diagonal;

	initTextureKing();
	initRectangle();
	initPosition();
	initGetPosition();
}

King::~King()
{
}

void King::initGetPosition()
{
	currentPosition = rectangle.getPosition();
}

void King::move(sf::Vector2f destination_Position)
{
	rectangle.setPosition(sf::Vector2f(destination_Position.x, destination_Position.y));

}

bool King::isLegal(sf::Vector2f destination_Position)
{
	float fileDiff = abs(destination_Position.x - currentPosition.x);
	float rankDiff = abs(destination_Position.y - currentPosition.y);

	if (fileDiff == 100 && rankDiff == 100 || (fileDiff == 100 && rankDiff == 0) || (fileDiff == 0 && rankDiff == 100))
		return true;
	else
		return false;

}

void King::updateKing()
{
	this->initGetPosition();
}

void King::renderKing(sf::RenderTarget& target)
{
	target.draw(rectangle);
}


