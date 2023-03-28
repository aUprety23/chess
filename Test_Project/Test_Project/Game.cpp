#include "Game.h"


//INITIALIZATION OF VARIABLES
void Game::initVariables()
{
     this->window = nullptr;
}

//INITIALIZE GAME WINDOW
void Game::initWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "Chess");
    window->setFramerateLimit(60);
}


//INITIALIZE BISHOP
void Game::initBishop()
{
    bishop_BlackB = new Bishop(BLACK, BLACK);
    bishop_BlackW = new Bishop(BLACK, WHITE);
    bishop_WhiteB = new Bishop(WHITE, BLACK);
    bishop_WhiteW = new Bishop(WHITE, WHITE);
}

//INITIALIZE KNIGHT
void Game::initKnight()
{
    knight_BlackB = new Knight(BLACK, BLACK);
    knight_BlackW = new Knight(BLACK, WHITE);
    knight_WhiteB = new Knight(WHITE, BLACK);
    knight_WhiteW = new Knight(WHITE, WHITE);
}

//INITIALIZE ROOK
void Game::initRook()
{
    rook_BlackB = new Rook(BLACK, BLACK);
    rook_BlackW = new Rook(BLACK, WHITE);
    rook_WhiteB = new Rook(WHITE, BLACK);
    rook_WhiteW = new Rook(WHITE, WHITE);
}

//INITIALIZE QUEEN
void Game::initQueen()
{
    queen_BlackB = new Queen(BLACK, BLACK);
    queen_WhiteW = new Queen(WHITE, WHITE);
}

//INITIALIZE KING
void Game::initKing()
{
    king_BlackB = new King(BLACK, BLACK);
    king_WhiteW = new King(WHITE, WHITE);
}

//INITIALIZE PAWN
void Game::initPawn()
{
     pawn_White1 = new Pawn(WHITE, WHITE, 1);
     pawn_White2 = new Pawn(WHITE, BLACK, 2);
     pawn_White3 = new Pawn(WHITE, WHITE, 3);
     pawn_White4 = new Pawn(WHITE, BLACK, 4);
     pawn_White5 = new Pawn(WHITE, WHITE, 5);
     pawn_White6 = new Pawn(WHITE, BLACK, 6);
     pawn_White7 = new Pawn(WHITE, WHITE, 7);
     pawn_White8 = new Pawn(WHITE, BLACK, 8);

     pawn_Black1 = new Pawn(BLACK, BLACK, 1);
     pawn_Black2 = new Pawn(BLACK, WHITE, 2);
     pawn_Black3 = new Pawn(BLACK, BLACK, 3);
     pawn_Black4 = new Pawn(BLACK, WHITE, 4);
     pawn_Black5 = new Pawn(BLACK, BLACK, 5);
     pawn_Black6 = new Pawn(BLACK, WHITE, 6);
     pawn_Black7 = new Pawn(BLACK, BLACK, 7);
     pawn_Black8 = new Pawn(BLACK, WHITE, 8);
}


bool Game::SquareContainsPiece(int x, int y)
{
    std::cout << x <<", " << y << std::endl;
    if (x >= 0 && x <= 700 && y >= 0 && y <= 700)
    {
        std::cout << "Yooo activated \n";
        for (sf::Vector2f select : pieces_currentPosition)
        {
            if ((int)select.x == x && (int)select.y == y)
            {
                std::cout << " BOOL VALUE " << "TRUE" << std::endl;
                return true;

            }
        }
    }
        std::cout << "bool value false" << std::endl;
        return false;
}

bool Game::BishopPathObstructed(sf::Vector2f current_Position, sf::Vector2f destination_Position)
{
    int dx = (destination_Position.x > current_Position.x) ? 100 : -100;
    int dy = (destination_Position.y > current_Position.y) ? 100 : -100;

    int x = current_Position.x + dx;
    int y = current_Position.y + dy;
    while (x != destination_Position.x && y != destination_Position.y)
    {
        if (SquareContainsPiece(x, y))
        {
            return true;
        }

        x += dx;
        y += dy;
            
    }

    return false;
}

bool Game::RookPathObstructed(sf::Vector2f current_Position, sf::Vector2f destination_Position)
{
    int dx, dy;
    if (destination_Position.x - current_Position.x != 0)
        dx = (destination_Position.x > current_Position.x) ? 100 : -100;
    else
        dx = 0;
    if (destination_Position.y - current_Position.y != 0)
        dy = (destination_Position.y > current_Position.y) ? 100 : -100;
    else
        dy = 0;

    int x = current_Position.x + dx;
    int y = current_Position.y + dy;
    while ((current_Position.x == destination_Position.x && y!= destination_Position.y) || (current_Position.y == destination_Position.y && x != destination_Position.x))
    {
        if (SquareContainsPiece(x, y))
        {
            return true;
        }

        x += dx;
        y += dy;

    }

    return false;
}

void Game::Capture()
{
}

bool Game::samePieceCollision(sf::Vector2f selection_Position, sf::Vector2f destination_Position)
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if ((pieces_currentPosition[i] == selection_Position) && (pieces_currentPosition[j] == destination_Position))
            {
                if (piecesList[i]->getPieceColor() == piecesList[j]->getPieceColor())
                    return true;
            }
        }

    }
    return false;
}


//VECTOR TO STORE ALL THE PIECES
void Game::initPiecesList()
{
    piecesList.resize(32);
    piecesList = {
    bishop_BlackB,
    bishop_BlackW,
    bishop_WhiteB,
    bishop_WhiteW,
              
    knight_BlackB,
    knight_BlackW,
    knight_WhiteB,
    knight_WhiteW,
               
    rook_BlackB ,
    rook_BlackW ,
    rook_WhiteB ,
    rook_WhiteW ,
               
    queen_BlackB,
    queen_WhiteW,
             
    king_BlackB ,
    king_WhiteW ,
             
    pawn_White1 ,
    pawn_White2 ,
    pawn_White3 ,
    pawn_White4 ,
    pawn_White5 ,
    pawn_White6 ,
    pawn_White7 ,
    pawn_White8 ,
             
    pawn_Black1 ,
    pawn_Black2 ,
    pawn_Black3 ,
    pawn_Black4 ,
    pawn_Black5 ,
    pawn_Black6 ,
    pawn_Black7 ,
    pawn_Black8

    };
}





//VECTOR TO STORE CURRENT POSITION OF ALL THE PIECES
void Game::initPiecesCurrentPosition()
{
    pieces_currentPosition.resize(32);
    pieces_currentPosition = {
        bishop_BlackB->currentPosition,
        bishop_BlackW->currentPosition,
        bishop_WhiteB->currentPosition,
        bishop_WhiteW->currentPosition,

        knight_BlackB->currentPosition,
        knight_BlackW->currentPosition,
        knight_WhiteB->currentPosition,
        knight_WhiteW->currentPosition,

        rook_BlackB->currentPosition,
        rook_BlackW->currentPosition,
        rook_WhiteB->currentPosition,
        rook_WhiteW->currentPosition,

        queen_BlackB->currentPosition,
        queen_WhiteW->currentPosition,

        king_BlackB->currentPosition,
        king_WhiteW->currentPosition,

        pawn_White1->currentPosition,
        pawn_White2->currentPosition,
        pawn_White3->currentPosition,
        pawn_White4->currentPosition,
        pawn_White5->currentPosition,
        pawn_White6->currentPosition,
        pawn_White7->currentPosition,
        pawn_White8->currentPosition,
                   
        pawn_Black1->currentPosition,
        pawn_Black2->currentPosition,
        pawn_Black3->currentPosition,
        pawn_Black4->currentPosition,
        pawn_Black5->currentPosition,
        pawn_Black6->currentPosition,
        pawn_Black7->currentPosition,
        pawn_Black8->currentPosition

    };
}


//MECHANISMS TO CHECK IF THE PIECE IS SELECTED AND TO MOVE THE PIECES
void Game::isMovingSetter(bool value)
{
    isMoving = value;
}

void Game::isSelectedSetter(bool value)
{
    isSelected = value;
}


//Constructors and destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initBoard();
    
    this->initBishop();
    this->initKnight();
    this->initRook();
    this->initQueen();
    this->initKing();
    this->initPawn();




    this->initPiecesCurrentPosition();
    
}


Game::~Game()
{
    delete this->window;

    //delete objects when game is over/ captured?
    delete this->bishop_BlackB;
    delete this->bishop_BlackW;
    delete this->bishop_WhiteB;
    delete this->bishop_WhiteW;


    delete this->knight_BlackB;
    delete this->knight_BlackW;
    delete this->knight_WhiteB;
    delete this->knight_WhiteW;

   delete this->rook_BlackB;
   delete this->rook_BlackW;
   delete this->rook_WhiteB;
   delete this->rook_WhiteW;

   delete this->queen_BlackB;
   delete this->queen_WhiteW;

   delete this->king_BlackB;
   delete this->king_WhiteW;

   delete this->pawn_White1;
   delete this->pawn_White2;
   delete this->pawn_White3;
   delete this->pawn_White4;
   delete this->pawn_White5;
   delete this->pawn_White6;
   delete this->pawn_White7;
   delete this->pawn_White8;

   delete this->pawn_Black1;
   delete this->pawn_Black2;
   delete this->pawn_Black3;
   delete this->pawn_Black4;
   delete this->pawn_Black5;
   delete this->pawn_Black6;
   delete this->pawn_Black7;
   delete this->pawn_Black8;

}



//checks if the window is open
const bool Game::isRunning() const
{
    return window->isOpen();
}



/*-------------------------------DRAWING BOARD----------------------------------------------*/

//check if the square is white
bool isWhite(int row, int col)
{
    bool result = ((row + col) % 2 == 0) ? true : false;
    return result;
}


//set board properties
void Game::initBoard() 
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            static int count = 0;
            //Set size of each squares
            Square[row][col].setSize(sf::Vector2f(100, 100));

            //setcolumn posiiton
            Square[row][col].setPosition(sf::Vector2f(row * 100, col * 100));

            //set column color
            if (isWhite(row, col))
                Square[row][col].setFillColor(sf::Color(235, 235, 208));
            else
                Square[row][col].setFillColor(sf::Color(119, 148, 85));

            std::cout << "Initilizing " << count++ << "\n" << std::endl;

        }
    }
}




//draw the board
void Game::drawBoard()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            //draw square
            window->draw(Square[row][col]);
        }
    }
}

/*--------------------------------END OF DRAWING BOARD---------------------------------------------*/





void Game::update()
{
    //update all pieces

    bishop_BlackB->updateBishop();
    bishop_BlackW->updateBishop();
    bishop_WhiteB->updateBishop();
    bishop_WhiteW->updateBishop();


    knight_BlackB->updateKnight();
    knight_BlackW->updateKnight();
    knight_WhiteB->updateKnight();
    knight_WhiteW->updateKnight();

    rook_BlackB->updateRook();
    rook_BlackB->updateRook();
    rook_WhiteB->updateRook();
    rook_WhiteW->updateRook();

    queen_BlackB->updateQueen();
    queen_WhiteW->updateQueen();

    king_BlackB->updateKing();
    king_WhiteW->updateKing();

    pawn_White1->updatePawn();
    pawn_White2->updatePawn();
    pawn_White3->updatePawn();
    pawn_White4->updatePawn();
    pawn_White5->updatePawn();
    pawn_White6->updatePawn();
    pawn_White7->updatePawn();
    pawn_White8->updatePawn();

    pawn_Black1->updatePawn();
    pawn_Black2->updatePawn();
    pawn_Black3->updatePawn();
    pawn_Black4->updatePawn();
    pawn_Black5->updatePawn();
    pawn_Black6->updatePawn();
    pawn_Black7->updatePawn();
    pawn_Black8->updatePawn();


    this->initPiecesCurrentPosition();
    this->initPiecesList();

}




//RENDER BOARD AND PIECES
void Game::render()
{
    window->clear();

    this->drawBoard();

    bishop_BlackB->renderBishop(*window);
    bishop_BlackW->renderBishop(*window);
    bishop_WhiteB->renderBishop(*window);
    bishop_WhiteW->renderBishop(*window);

    knight_BlackB->renderKnight(*window);
    knight_BlackW->renderKnight(*window);
    knight_WhiteB->renderKnight(*window);
    knight_WhiteW->renderKnight(*window);

    rook_BlackB->renderRook(*window);
    rook_BlackW->renderRook(*window);
    rook_WhiteB->renderRook(*window);
    rook_WhiteW->renderRook(*window);


    queen_BlackB->renderQueen(*window);
    queen_WhiteW->renderQueen(*window);

    king_BlackB->renderKing(*window);
    king_WhiteW->renderKing(*window);

    pawn_White1->renderPawn(*window);
    pawn_White2->renderPawn(*window);
    pawn_White3->renderPawn(*window);
    pawn_White4->renderPawn(*window);
    pawn_White5->renderPawn(*window);
    pawn_White6->renderPawn(*window);
    pawn_White7->renderPawn(*window);
    pawn_White8->renderPawn(*window);
               
    pawn_Black1->renderPawn(*window);
    pawn_Black2->renderPawn(*window);
    pawn_Black3->renderPawn(*window);
    pawn_Black4->renderPawn(*window);
    pawn_Black5->renderPawn(*window);
    pawn_Black6->renderPawn(*window);
    pawn_Black7->renderPawn(*window);
    pawn_Black8->renderPawn(*window);



    window->display();
}
