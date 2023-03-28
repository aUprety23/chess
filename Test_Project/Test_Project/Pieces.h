#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>



#define WHITE 1
#define BLACK 0

class Pieces
{
protected:
	void initRectangle();

	bool pieceColor;
	bool pieceDiagonal;

	bool attacker = false;

public:
	Pieces();
	Pieces(bool color, bool diagonal);
	~Pieces();

	sf::RectangleShape rectangle;

	sf::Vector2f currentPosition;
	sf::Vector2f nextPosition;

	// check if the piece is attacker or not
	void isAttacker(bool value);
	bool getIsAttacker();

	//Piece = white or black?
	bool getPieceColor();

	void highlight();

	//move the piece outside the board
	void remove();

	void updatePieces();
	void renderPieces(sf::RenderTarget& target);


};