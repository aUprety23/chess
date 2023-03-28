#include "Queen.h"

void Queen::initTextureQueen()
{
	if (!texture_blackQueen.loadFromFile("images/blackQueen.png"))
		std::cout << "ERROR::QUEEN::initTEXTUREQUEEN::COULD NOT LOAD 'BLACK QUEEN' TEXTURE FROM FILE " << std::endl;


	if (!texture_whiteQueen.loadFromFile("images/whiteQueen.png"))
		std::cout << "ERROR::QUEEN::initTEXTUREQUEEN::COULD NOT LOAD 'WHITE QUEEN' TEXTURE FORM FILE " << std::endl;


	texture_blackQueen.setSmooth(true);
	texture_whiteQueen.setSmooth(true);
}

void Queen::initPosition()
{
	//position ; depends on diagonal of bishop and color of the piece;

	if (pieceColor == BLACK) //&& pieceDiagonal == WHITE)
	{
		rectangle.setPosition(sf::Vector2f(300, 0));
	}


	else if (pieceColor == WHITE)// && pieceDiagonal == WHITE)
	{
		rectangle.setPosition(sf::Vector2f(300, 700));
	}

	// texture; depends on the color of piece;
	if (pieceColor == BLACK)
		rectangle.setTexture(&texture_blackQueen);
	if (pieceColor == WHITE)
		rectangle.setTexture(&texture_whiteQueen);
}

Queen::Queen(bool color, bool diagonal)
{
	pieceColor = color;
	pieceDiagonal = diagonal;

	initTextureQueen();
	initRectangle();
	initPosition();
	initGetPosition();
}

Queen::~Queen()
{
}

void Queen::initGetPosition()
{
	currentPosition = rectangle.getPosition();
}

void Queen::moveDiagonally(sf::Vector2f destination_position)
{
	if (abs(currentPosition.x - destination_position.x) == abs(currentPosition.y - destination_position.y))
		rectangle.setPosition(sf::Vector2f(destination_position.x, destination_position.y));
}

void Queen::moveLinearly(sf::Vector2f destination_position)
{
	if (currentPosition.x - destination_position.x == 0 ||  currentPosition.y - destination_position.y == 0 )
		rectangle.setPosition(sf::Vector2f(destination_position.x, destination_position.y));
}

/*void Queen::move(sf::Vector2f destination_Position)
{
	rectangle.setPosition(sf::Vector2f(destination_Position.x, destination_Position.y));
}*/



bool Queen::isLegal(sf::Vector2f destination_Position)
{
	float fileDiff = abs(destination_Position.x - currentPosition.x);
	float rankDiff = abs(destination_Position.y - currentPosition.y);
	
	if (fileDiff == 0 || rankDiff == 0 || (fileDiff - rankDiff == 0))
		return true;
	else
		return false;
}

void Queen::updateQueen()
{
	this->initGetPosition();
}

void Queen::renderQueen(sf::RenderTarget& target)
{
	target.draw(rectangle);
}
