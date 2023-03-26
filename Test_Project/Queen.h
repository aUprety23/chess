#pragma once

#include "Pieces.h"

class Queen : public Pieces
{
private:
	//King PIECE
	sf::Texture texture_blackQueen;
	sf::Texture texture_whiteQueen;
	void initTextureQueen();

	void initPosition();
	sf::Vector2i mousePosition;

public:
	Queen(bool color, bool diagonal);
	virtual ~Queen();

	sf::Vector2f currentPosition;
	void initGetPosition();

	//void move(sf::Vector2f destination_Position);
	void moveDiagonally(sf::Vector2f destination_position);
	void moveLinearly(sf::Vector2f destination_position);


	bool isLegal(sf::Vector2f destination_Position);


	void updateQueen();
	void renderQueen(sf::RenderTarget& target);

};