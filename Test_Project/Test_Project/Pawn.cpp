#include "Pawn.h"

void Pawn::initTexturePawn()
{
	//INITIALIZE TEXTURE OF THE PAWN
	if (!texture_blackPawn.loadFromFile("images/blackPawn.png"))
		std::cout << "ERROR::Pawn::initTexturePawn::COULD NOT LOAD 'BLACK PAWN' TEXTURE FROM FILE " << std::endl;


	if (!texture_whitePawn.loadFromFile("images/whitePawn.png"))
		std::cout << "ERROR::Pawn::initTEXTUREPawn::COULD NOT LOAD 'WHITE PAWN' TEXTURE FORM FILE " << std::endl;

	texture_blackPawn.setSmooth(true);
	texture_whitePawn.setSmooth(true);
}

void Pawn::initPosition()
{
		//POSITION
		if (pieceColor == BLACK)
		{
			rectangle.setPosition(sf::Vector2f((file-1)*100, 100));
		}
		
		else if (pieceColor == WHITE)
		{
			rectangle.setPosition(sf::Vector2f((file - 1) * 100, 600));
		}


		// TEXTURE OF THE PAWN
		if (pieceColor == BLACK)
			rectangle.setTexture(&texture_blackPawn);
		else if (pieceColor == WHITE)
			rectangle.setTexture(&texture_whitePawn);
}


//CONSTRUCTORS AND DESTRUCTORS
Pawn::Pawn(bool color, bool diagonal, int fileNumber)
{
	file = fileNumber;
	pieceColor = color;
	pieceDiagonal = diagonal;
	firstMove = 0;

	initTexturePawn();
	initRectangle();
	initPosition();
	initGetPosition();
}

Pawn::~Pawn()
{
}

void Pawn::isMovedOnce()
{
	//SET THE VALUE IF THE PIECE HAS BEEN MOVED ONCE
	firstMove = 1;
}

bool Pawn::getFirstMove()
{
	//RETURN IF PIECE HAS BEEN MOVED
	return firstMove;
}

void Pawn::initGetPosition()
{
	//RETURN CURRENT POSITION OF THE PAWN
	currentPosition = rectangle.getPosition();
}


void Pawn::move(sf::Vector2f destination_Position)
{
	//MOVE THE PAWN
	rectangle.setPosition(sf::Vector2f(destination_Position.x, destination_Position.y));
}

bool Pawn::isLegal(sf::Vector2f destination_Position)
{
	//CHECK IF THE POSITION IS LEGAL
	float fileDiff = (destination_Position.x - currentPosition.x);
	float rankDiff = (destination_Position.y - currentPosition.y);
	
	if (pieceColor == BLACK && fileDiff == 0  && rankDiff == 200 && !firstMove)
	{
		isMovedOnce();
		return true;
	}

	else if (pieceColor == BLACK && fileDiff == 0 && rankDiff == 100 )
	{
		isMovedOnce();
		return true;
	}

	else if (pieceColor == WHITE && fileDiff == 0 && rankDiff == -200 && !firstMove)
	{
		isMovedOnce();
		return true;
	}

	else if (pieceColor == WHITE && fileDiff == 0 && rankDiff == -100)
	{
		isMovedOnce();
		return true;
	}

	else
		return false;
}



//update changes
void Pawn::updatePawn()
{
	this->initGetPosition();
}

//render the pawn
void Pawn::renderPawn(sf::RenderTarget& target)
{
	target.draw(rectangle);
}
