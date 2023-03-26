#pragma once

#include "Pieces.h"

class Knight : public Pieces
{
private:
	//KNIGHT PIECE

	//initialize the texture of knight
	sf::Texture texture_blackKnight;
	sf::Texture texture_whiteKnight;
	void initTextureKnight();

	//set the position and texture of the knight piece
	void initPosition();
	sf::Vector2i mousePosition;

public:
	//constructors and destructors
	Knight(bool color, bool diagonal);
	virtual ~Knight();

	//get the current position of the knight
	sf::Vector2f currentPosition;
	void initGetPosition();

	//move the knightht
	void move(sf::Vector2f destination_Position);

	//check if the move is legal
	bool isLegal(sf::Vector2f destination_Position);

	//update the changes to the piece and render the image
	void updateKnight();
	void renderKnight(sf::RenderTarget& target);

};