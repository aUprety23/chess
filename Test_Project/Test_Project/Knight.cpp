#include "Knight.h"

void Knight::initTextureKnight()
{
	
		if (!texture_blackKnight.loadFromFile("images/blackKnight.png"))
			std::cout << "ERROR::KNIGHT::initTEXTURE KNIGHT::COULD NOT LOAD 'BLACK KNIGHT' TEXTURE FROM FILE " << std::endl;


		if (!texture_whiteKnight.loadFromFile("images/whiteKnight.png"))
			std::cout << "ERROR::KNIGHT::initTEXTUREKNIGHT::COULD NOT LOAD 'WHITE KNIGHT' TEXTURE FORM FILE " << std::endl;

		texture_blackKnight.setSmooth(true);
		texture_whiteKnight.setSmooth(true);
}

void Knight::initPosition()
{

		//position ; depends on diagonal of bishop and color of the piece;
		if (pieceColor == BLACK && pieceDiagonal == WHITE)
		{
			rectangle.setPosition(sf::Vector2f(100, 0));
		}

		if (pieceColor == BLACK && pieceDiagonal == BLACK)
		{
			rectangle.setPosition(sf::Vector2f(600, 0));
		}
		if (pieceColor == WHITE && pieceDiagonal == WHITE)
		{
			rectangle.setPosition(sf::Vector2f(600, 700));
		}
		if (pieceColor == WHITE && pieceDiagonal == BLACK)
		{
			rectangle.setPosition(sf::Vector2f(100, 700));
		}


		// texture; depends on the color of piece;
		if (pieceColor == BLACK)
			rectangle.setTexture(&texture_blackKnight);
		if (pieceColor == WHITE)
			rectangle.setTexture(&texture_whiteKnight);
}

Knight::Knight(bool color, bool diagonal)
{
	pieceColor = color;
	pieceDiagonal = diagonal;

	initTextureKnight();
	initRectangle();
	initPosition();
	initGetPosition();
}

Knight::~Knight()
{
}

void Knight::initGetPosition()
{
	currentPosition = rectangle.getPosition();
}


bool Knight::isLegal(sf::Vector2f destination_Position)
{
	float fileDiff = abs(destination_Position.x - currentPosition.x);
	float rankDiff = abs(destination_Position.y - currentPosition.y);
	if ((fileDiff == 100 && rankDiff == 200) || (fileDiff == 200 && rankDiff == 100))
		return true;
	else
		return false;

}

void Knight::move(sf::Vector2f destination_Position)
{
	rectangle.setPosition(sf::Vector2f(destination_Position.x, destination_Position.y));
}

void Knight::updateKnight()
{
	this->initGetPosition();
}

void Knight::renderKnight(sf::RenderTarget& target)
{
	target.draw(rectangle);
}
