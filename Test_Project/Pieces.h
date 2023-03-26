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

	void isAttacker(bool value);
	bool getIsAttacker();

	bool getPieceColor();

	void highlight();

	void remove();

	void updatePieces();
	void renderPieces(sf::RenderTarget& target);


};