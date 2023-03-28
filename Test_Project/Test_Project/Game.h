#pragma once

#include<iostream>
#include <vector>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Pawn.h"


class Game
{

	private:
	//INITIALIZATION OF WINDOW AND EVENT
	sf::RenderWindow* window;
	sf::Event event;

	void initVariables();
	void initWindow();


	//BOARD SQAURE DECLARATION AND INITIALIZATION

	sf::RectangleShape Square[8][8];
	void initBoard();


	//Mouse Position
	sf::Vector2f localMousePos;

	//Piece Selection Position
	sf::Vector2f selectionPosition;

	//Piece Destination Position
	sf::Vector2f destinationPosition;


	//isSelected
	bool isSelected;
	bool isMoving;

	void isSelectedSetter(bool value);
	void isMovingSetter(bool value);


	//Bishop
	Bishop* bishop_BlackB;
	Bishop* bishop_BlackW;
	Bishop* bishop_WhiteB;
	Bishop* bishop_WhiteW;
	void initBishop();

	//Knight
	Knight* knight_BlackB;
	Knight* knight_BlackW;
	Knight* knight_WhiteB;
	Knight* knight_WhiteW;
	void initKnight();

	//Rook
	Rook* rook_BlackB;
	Rook* rook_BlackW;
	Rook* rook_WhiteB;
	Rook* rook_WhiteW;
	void initRook();

	//Queen
	Queen* queen_BlackB;
	Queen* queen_WhiteW;
	void initQueen();
	
	//King
	King* king_BlackB;
	King* king_WhiteW;
	void initKing();

	//Pawns
	Pawn* pawn_White1;
	Pawn* pawn_White2;
	Pawn* pawn_White3;
	Pawn* pawn_White4;
	Pawn* pawn_White5;
	Pawn* pawn_White6;
	Pawn* pawn_White7;
	Pawn* pawn_White8;

	Pawn* pawn_Black1;
	Pawn* pawn_Black2;
	Pawn* pawn_Black3;
	Pawn* pawn_Black4;
	Pawn* pawn_Black5;
	Pawn* pawn_Black6;
	Pawn* pawn_Black7;
	Pawn* pawn_Black8;

	void initPawn();


	//LIST TO STORE ALL THE OBJECTS
	std::vector <Pieces*> piecesList;
	void initPiecesList();

	//LIST TO STORE ALL THE CURRENT PIECE POSITION
	std::vector<sf::Vector2f> pieces_currentPosition;
	void initPiecesCurrentPosition();

	std::vector<sf::RectangleShape> rectanglesCollected;
	void initRectanglesCollected();


public:
	//CONSTRUCTORS AND DESTRUCTORS
	Game();
	virtual ~Game();


	//CHECK IF WINDOW IS RUNNING
	const bool isRunning() const;

	//UPDATE MOUSE POSITION
	void updateMousePosition();

	//MOVE OBJECTS
	bool MovePiece(sf::Vector2f selectionPosition, sf::Vector2f destinationPosition);

	//POOL EVENT
	void pollEvent();

	//UPDATING
	void update();

	//CHECKS IF THE BOARD SQUARE CONTAINS A PIECE
	bool SquareContainsPiece(int x, int y);

	//check if the Path is Obstructed
	bool BishopPathObstructed(sf::Vector2f current_Position, sf::Vector2f destination_Position);
	bool RookPathObstructed(sf::Vector2f current_Position, sf::Vector2f destination_Position);

	bool samePieceCollision(sf::Vector2f selection_Position, sf::Vector2f destination_Position);

	void Capture();

	//draw board
	void drawBoard();

	//RENDERING
	void render();

};
