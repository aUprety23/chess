#pragma once
#include "Pieces.h"

class Pawn : public Pieces
{
private:
	//Pawn piece


	//holds the value of the file where the pawn stands
	int file;

	//holds if the pawn has been moved once
	bool firstMove;

	//initialize texture
	sf::Texture texture_blackPawn;
	sf::Texture texture_whitePawn;
	void initTexturePawn();

	//initialize position and fill the texture on the pawn
	void initPosition();
	sf::Vector2i mousePosition;
	

public:

	//constructiors and destructors
	Pawn(bool color, bool diagonal, int fileNumber);
	virtual ~Pawn();
	
	//check if the pawn has been moved once & set the value if moved
	void isMovedOnce();
	bool getFirstMove();

	//get current position of the pawn
	sf::Vector2f currentPosition;
	void initGetPosition();
	

	//move the pawn
	void move(sf::Vector2f destination_Position);

	//check if the move is legal
	bool isLegal(sf::Vector2f destination_Position);

	//update and render changes
	void updatePawn();
	void renderPawn(sf::RenderTarget& target);

};