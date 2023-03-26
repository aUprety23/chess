#pragma once

#include "Pieces.h"

class King: public Pieces
{
private:
	//King PIECE

	//initialize textures of the King
	sf::Texture texture_blackKing;
	sf::Texture texture_whiteKing;
	void initTextureKing();

	//set the position and texture of the king piece
	void initPosition();
	sf::Vector2i mousePosition;

public:
	//constructors and destructors
	King(bool color, bool diagonal);
	virtual ~King();

	//get the current position of the piece
	sf::Vector2f currentPosition;
	void initGetPosition();

	//move the piece
	void move(sf::Vector2f destination_Position);

	//check if the move is legal
	bool isLegal(sf::Vector2f destination_Position);

	//update the change in the piece and render image
	void updateKing();
	void renderKing(sf::RenderTarget& target);

};