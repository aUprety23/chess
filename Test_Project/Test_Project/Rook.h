#pragma once

#include "Pieces.h"

class Rook : public Pieces
{
private:
	//ROOK PIECE
	sf::Texture texture_blackRook;
	sf::Texture texture_whiteRook;
	void initTextureRook();

	void initPosition();
	sf::Vector2i mousePosition;

public:
	Rook(bool color, bool diagonal);
	virtual ~Rook();

	sf::Vector2f currentPosition;
	void initGetPosition();

	void move(sf::Vector2f destination_Position);

	bool isLegal(sf::Vector2f destination_Position);

	void updateRook();
	void renderRook(sf::RenderTarget& target);

};