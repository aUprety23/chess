#pragma once
#include "Pieces.h"

class Bishop : public Pieces
{
private:
	//BISHOP PIECE

	//initialize bishop's texture
	sf::Texture texture_blackBishop;
	sf::Texture texture_whiteBishop;
	void initTextureBishop();

	//set texture and position of the bishop
	void initPosition();
	sf::Vector2i mousePosition;

public:
	//constructors and destructors
	Bishop(bool color, bool diagonal);
	virtual ~Bishop();

	//get current position of the bisohop
	sf::Vector2f currentPosition;
	void initGetPosition();

	//move the bishop
	void move(sf::Vector2f destination_Position);

	//check if the move is legal
	bool isLegal(sf::Vector2f destination_Position);

	//update the bishop changes and render the image
	void updateBishop();
	void renderBishop(sf::RenderTarget &target);

};