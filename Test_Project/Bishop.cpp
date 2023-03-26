#include "Bishop.h"


//LOAD TEXTURE
void Bishop::initTextureBishop()
{
	if (!texture_blackBishop.loadFromFile("images/blackBishop.png"))
		std::cout << "ERROR::BISHOP::initTextureBishop::COULD NOT LOAD 'BLACK BISHOP' TEXTURE FROM FILE " << std::endl;

	
	if (!texture_whiteBishop.loadFromFile("images/whiteBishop.png"))
		std::cout << "ERROR::BISHOP::initTEXTUREBISHOP::COULD NOT LOAD 'WHITE BISHOP' TEXTURE FORM FILE " << std::endl;
	
	texture_blackBishop.setSmooth(true);
	texture_whiteBishop.setSmooth(true);
}


void Bishop::initPosition()
{
	//position ; depends on diagonal of bishop and color of the piece;
	if (pieceColor == BLACK && pieceDiagonal == WHITE)
	{
		rectangle.setPosition(sf::Vector2f(200, 0));
	}

	else if (pieceColor == BLACK && pieceDiagonal == BLACK)
	{
		rectangle.setPosition(sf::Vector2f(500, 0));
	}
	else if (pieceColor == WHITE && pieceDiagonal == WHITE)
	{
		rectangle.setPosition(sf::Vector2f(500, 700));
	}
	else if (pieceColor == WHITE && pieceDiagonal == BLACK)
	{
		rectangle.setPosition(sf::Vector2f(200, 700));
	}


	// texture; depends on the color of piece;
	if (pieceColor == BLACK)
		rectangle.setTexture(&texture_blackBishop);
	else if(pieceColor == WHITE)
		rectangle.setTexture(&texture_whiteBishop);
}


//CONSTRUCTORS AND DESTRUCTORS
Bishop::Bishop(bool color, bool diagonal)
{
	pieceColor = color;
	pieceDiagonal = diagonal;

	initTextureBishop();
	initRectangle();
	initPosition();
	initGetPosition();
}

Bishop::~Bishop()
{
}




//SET CURRENT POSITION OF BISHOP
void Bishop::initGetPosition()
{
	currentPosition = rectangle.getPosition();

}


//MOVE THE BISHOP
void Bishop::move(sf::Vector2f destination_Position)
{
	rectangle.setPosition(sf::Vector2f(destination_Position.x, destination_Position.y));
}


//CHECK IF THE MOVE IS LEGAL
bool Bishop::isLegal(sf::Vector2f destinationPosition)
{
	float fileDiff = abs(destinationPosition.x - currentPosition.x);
	float rankDiff = abs(destinationPosition.y - currentPosition.y);
	if ( fileDiff == rankDiff)
		return true;
	else
		return false;
}


//UPDATE THE CHANGE IN POSITION OF BISHOP
void Bishop::updateBishop()
{
	initGetPosition();
}

//RENDER BISHOP
void Bishop::renderBishop(sf::RenderTarget& target)
{
	target.draw(rectangle);
}

