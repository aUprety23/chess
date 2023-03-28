#pragma once

#include "Game.h"


//MOVE THE PIECE IF POSSIBLE
bool  Game::MovePiece(sf::Vector2f source_position, sf::Vector2f destination_posititon)
{

    //Reset the value of attacker
    for (Pieces* select : piecesList)
    {
        select->isAttacker(false);
    }

    //movement of bishop
    if (bishop_BlackB->currentPosition == source_position)
    {
        if (bishop_BlackB->isLegal(destination_posititon) && BishopPathObstructed(source_position, destination_posititon) !=true)
        {
            bishop_BlackB->move(destination_posititon);
            bishop_BlackB->currentPosition = destination_posititon;
            bishop_BlackB->isAttacker(true);
            return true;
        }
    }

    else if (bishop_BlackW->currentPosition == source_position && BishopPathObstructed(source_position, destination_posititon) != true)
    {
        if (bishop_BlackW->isLegal(destination_posititon))
        {
            bishop_BlackW->move(destination_posititon);
            bishop_BlackW->currentPosition = destination_posititon;
            bishop_BlackW->isAttacker(true);
            return true;
        }
    }

    else if (bishop_WhiteB->currentPosition == source_position && BishopPathObstructed(source_position, destination_posititon) !=true)
    {
        if (bishop_WhiteB->isLegal(destination_posititon))
        {

            bishop_WhiteB->move(destination_posititon);
            bishop_WhiteB->currentPosition = destination_posititon;
            bishop_WhiteB->isAttacker(true);
            return true;
        }
    }

    else if (bishop_WhiteW->currentPosition == source_position && BishopPathObstructed(source_position, destination_posititon)!=true)
    {
        if (bishop_WhiteW->isLegal(destination_posititon))
        {
            bishop_WhiteW->move(destination_posititon);
            bishop_WhiteW->currentPosition = destination_posititon;
            bishop_WhiteW->isAttacker(true);
            return true;
        }
    }

    //movement of knight
    else if (knight_BlackB->currentPosition == source_position)
    {
        if (knight_BlackB->isLegal(destination_posititon))
        {
            knight_BlackB->move(destination_posititon);
            knight_BlackB->currentPosition = destination_posititon;
            knight_BlackB->isAttacker(true);
            return true;
        }
    }

    else if (knight_BlackW->currentPosition == source_position)
    {
        if (knight_BlackW->isLegal(destination_posititon))
        {
            knight_BlackW->move(destination_posititon);
            knight_BlackW->currentPosition = destination_posititon;
            knight_BlackW->isAttacker(true);
            return true;
        }
    }

    else if (knight_WhiteB->currentPosition == source_position)
    {
        if (knight_WhiteB->isLegal(destination_posititon))
        {
            knight_WhiteB->move(destination_posititon);
            knight_WhiteB->currentPosition = destination_posititon;
            knight_WhiteB->isAttacker(true);
            return true;
        }
    }

    else if (knight_WhiteW->currentPosition == source_position)
    {
        if (knight_WhiteW->isLegal(destination_posititon))
        {
            knight_WhiteW->move(destination_posititon);
            knight_WhiteW->currentPosition = destination_posititon;
            knight_WhiteW->isAttacker(true);
            return true;
        }
    }

    //movment of rook
    else if (rook_BlackB->currentPosition == source_position && RookPathObstructed(source_position, destination_posititon) != true)
    {
        if (rook_BlackB->isLegal(destination_posititon))
        {
            rook_BlackB->move(destination_posititon);
            rook_BlackB->currentPosition = destination_posititon;
            rook_BlackB->isAttacker(true);
            return true;
        }
    }

    else if (rook_BlackW->currentPosition == source_position && RookPathObstructed(source_position, destination_posititon) != true)
    {
        if (rook_BlackW->isLegal(destination_posititon))
        {
            rook_BlackW->move(destination_posititon);
            rook_BlackW->currentPosition = destination_posititon;
            knight_BlackW->isAttacker(true);
            return true;
        }
    }

    else if (rook_WhiteB->currentPosition == source_position && RookPathObstructed(source_position, destination_posititon) != true)
    {
        if (rook_WhiteB->isLegal(destination_posititon))
        {

            rook_WhiteB->move(destination_posititon);
            rook_WhiteB->currentPosition = destination_posititon;
            knight_WhiteB->isAttacker(true);
            return true;
        }
    }

    else if (rook_WhiteW->currentPosition == source_position && RookPathObstructed(source_position, destination_posititon) != true)
    {
        if (rook_WhiteW->isLegal(destination_posititon))
        {
            rook_WhiteW->move(destination_posititon);
            rook_WhiteW->currentPosition = destination_posititon;
            knight_WhiteW->isAttacker(true);
            return true;
        }
    }

    //movement of queen

     if (queen_BlackB->currentPosition == source_position && BishopPathObstructed(source_position, destination_posititon) != true)
    {
        if (queen_BlackB->isLegal(destination_posititon) && (abs(source_position.x - destination_posititon.x) == abs(source_position.y - destination_posititon.y)))
        {
            queen_BlackB->moveDiagonally(destination_posititon);
            queen_BlackB->currentPosition = destination_posititon;
            queen_BlackB->isAttacker(true);
            return true;
        }
    }

     if (queen_BlackB->currentPosition == source_position && RookPathObstructed(source_position, destination_posititon) != true)
     {
         if (queen_BlackB->isLegal(destination_posititon) && (source_position.x - destination_posititon.x == 0 ||  source_position.y - destination_posititon.y == 0))
         {
             queen_BlackB->moveLinearly(destination_posititon);
             queen_BlackB->currentPosition = destination_posititon;
             queen_BlackB->isAttacker(true);
             return true;
         }
     }

     if (queen_WhiteW->currentPosition == source_position && BishopPathObstructed(source_position, destination_posititon) != true)
     {
         if (queen_WhiteW->isLegal(destination_posititon) && (abs(source_position.x - destination_posititon.x) == abs(source_position.y - destination_posititon.y)))
         {
             queen_WhiteW->moveDiagonally(destination_posititon);
             queen_WhiteW->currentPosition = destination_posititon;
             queen_WhiteW->isAttacker(true);
             return true;
         }
     }

     if (queen_WhiteW->currentPosition == source_position && RookPathObstructed(source_position, destination_posititon) != true)
     {
         if (queen_WhiteW->isLegal(destination_posititon) && (source_position.x - destination_posititon.x == 0 || source_position.y - destination_posititon.y == 0))
         {
             queen_WhiteW->moveLinearly(destination_posititon);
             queen_WhiteW->currentPosition = destination_posititon;
             queen_WhiteW->isAttacker(true);
             return true;
         }
     }


     




    //movment of king
    else if (king_BlackB->currentPosition == source_position)
    {
        if (king_BlackB->isLegal(destination_posititon))
        {
            king_BlackB->move(destination_posititon);
            king_BlackB->currentPosition = destination_posititon;
            king_BlackB->isAttacker(true);
            return true;
        }
    }

    else if (king_WhiteW->currentPosition == source_position)
    {
        if (king_WhiteW->isLegal(destination_posititon))
        {
            king_WhiteW->move(destination_posititon);
            king_WhiteW->currentPosition = destination_posititon;
            king_WhiteW->isAttacker(true);
            return true;
        }
    }

    


    //movement of pawn white
    else if (pawn_White1->currentPosition == source_position)
    {
        if (pawn_White1->isLegal(destination_posititon))
        {
            pawn_White1->move(destination_posititon);
            pawn_White1->currentPosition = destination_posititon;
            pawn_White1->isAttacker(true);
            return true;
        }
    }

    else if (pawn_White2->currentPosition == source_position)
    {
        if (pawn_White2->isLegal(destination_posititon))
        {
            pawn_White2->move(destination_posititon);
            pawn_White2->currentPosition = destination_posititon;
            pawn_White2->isAttacker(true);
            return true;
        }
    }

    else if (pawn_White3->currentPosition == source_position)
    {
        if (pawn_White3->isLegal(destination_posititon))
        {
            pawn_White3->move(destination_posititon);
            pawn_White3->currentPosition = destination_posititon;
            pawn_White3->isAttacker(true);
            return true;
        }
    }

    else if (pawn_White4->currentPosition == source_position)
    {
        if (pawn_White4->isLegal(destination_posititon))
        {
            pawn_White4->move(destination_posititon);
            pawn_White4->currentPosition = destination_posititon;
            pawn_White4->isAttacker(true);
            return true;
        }
    }

    else if (pawn_White5->currentPosition == source_position)
    {
        if (pawn_White5->isLegal(destination_posititon))
        {
            pawn_White5->move(destination_posititon);
            pawn_White5->currentPosition = destination_posititon;
            pawn_White5->isAttacker(true);
            return true;
        }
    }

    else if (pawn_White6->currentPosition == source_position)
    {
        if (pawn_White6->isLegal(destination_posititon))
        {
            pawn_White6->move(destination_posititon);
            pawn_White6->currentPosition = destination_posititon;
            pawn_White6->isAttacker(true);
            return true;
        }
    }

    else if (pawn_White7->currentPosition == source_position)
    {
        if (pawn_White7->isLegal(destination_posititon))
        {
            pawn_White7->move(destination_posititon);
            pawn_White7->currentPosition = destination_posititon;
            pawn_White7->isAttacker(true);
            return true;
        }
    }

    else if (pawn_White8->currentPosition == source_position)
    {
        if (pawn_White8->isLegal(destination_posititon))
        {
            pawn_White8->move(destination_posititon);
            pawn_White8->currentPosition = destination_posititon;
            pawn_White8->isAttacker(true);
            return true;
        }
    }






    //movment of pawn black
    else if (pawn_Black1->currentPosition == source_position)
    {
        if (pawn_Black1->isLegal(destination_posititon))
        {
            pawn_Black1->move(destination_posititon);
            pawn_Black1->currentPosition = destination_posititon;
            pawn_Black1->isAttacker(true);
            return true;
        }
    }

    else if (pawn_Black2->currentPosition == source_position)
    {
        if (pawn_Black2->isLegal(destination_posititon))
        {
            pawn_Black2->move(destination_posititon);
            pawn_Black2->currentPosition = destination_posititon;
            pawn_Black2->isAttacker(true);
            return true;
        }
    }

    else if (pawn_Black3->currentPosition == source_position)
    {
        if (pawn_Black3->isLegal(destination_posititon))
        {
            pawn_Black3->move(destination_posititon);
            pawn_Black3->currentPosition = destination_posititon;
            pawn_Black3->isAttacker(true);
            return true;
        }
    }

    else if (pawn_Black4->currentPosition == source_position)
    {
        if (pawn_Black4->isLegal(destination_posititon))
        {
            pawn_Black4->move(destination_posititon);
            pawn_Black4->currentPosition = destination_posititon;
        
            pawn_Black4->isAttacker(true);
            return true;
        }
    }

    else if (pawn_Black5->currentPosition == source_position)
    {
        if (pawn_Black5->isLegal(destination_posititon))
        {
            pawn_Black5->move(destination_posititon);
            pawn_Black5->currentPosition = destination_posititon;
            pawn_Black5->isAttacker(true);
            return true;
        }
    }

    else if (pawn_Black6->currentPosition == source_position)
    {
        if (pawn_Black6->isLegal(destination_posititon))
        {
            pawn_Black6->move(destination_posititon);
            pawn_Black6->currentPosition = destination_posititon;
            pawn_Black6->isAttacker(true);
            return true;
        }
    }

    else if (pawn_Black7->currentPosition == source_position)
    {
        if (pawn_Black7->isLegal(destination_posititon))
        {
            pawn_Black7->move(destination_posititon);
            pawn_Black7->currentPosition = destination_posititon;
            pawn_Black7->isAttacker(true);
            return true;
        }
    }

    else if (pawn_Black8->currentPosition == source_position)
    {
        if (pawn_Black8->isLegal(destination_posititon))
        {
            pawn_Black8->move(destination_posititon);
            pawn_Black8->currentPosition = destination_posititon;
            pawn_Black8->isAttacker(true);
            return true;
        }
    }

    else
    {
        return false;
    }

}




//POLL EVENTS
void Game::pollEvent()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case(sf::Event::Closed):
                window->close();

            case(sf::Event::KeyPressed):
                if (event.key.code == sf::Keyboard::Key::Escape)
                    window->close();


                //SELECTION POSITION OF PIECE AND PLACEMENT POSITION OF PIECES
            case(sf::Event::MouseButtonPressed):
            {

                //this acts as a switch so that the value of 'isMoving' and 'isSelected' is different... 
                //if this was not done the ' piece select '  and  ' piece place ' would have same value
                if (isSelected == true) { isMovingSetter(true); }
                if (isSelected == false) { isMovingSetter(false); }





                //SELECT A DESIRED PIECE
                sf::Vector2i localMousePos = sf::Mouse::getPosition(*window);




                //SELECT THE PIECE
                if (event.mouseButton.button == sf::Mouse::Left && isSelected == false)
                {

                    for (sf::Vector2f& select : pieces_currentPosition)
                    {

                        if ((localMousePos.x > select.x && (localMousePos.x < select.x + 100)) && (localMousePos.y > select.y && localMousePos.y < (select.y + 100)))
                        {

                            std::cout << "::PIECE SELECTED::" << std::endl;
                            selectionPosition = select;
                            isSelectedSetter(true);
                            break;


                        }
                    }
                }






                //SELECT THE DESTINATION FOR THE PIECES
                else if (event.mouseButton.button == sf::Mouse::Left && isSelected == true && isMoving == true)
                {

                    //converting the mouse position from Vector2i to Vector2f and stroing on destinationPosition
                    sf::Vector2f select = sf::Vector2f(localMousePos);
                    destinationPosition.x = select.x - (int(select.x) % 100);
                    destinationPosition.y = select.y - (int(select.y) % 100);
                    std::cout << "::PIECE PLACED::" << std::endl;

                    //reseting the value of 'isSelect' and 'isMoving'

                    //move the piece if there is no same piece collision
                    bool pieceMoved = false;
                    if(!samePieceCollision(selectionPosition, destinationPosition))
                        pieceMoved= MovePiece(selectionPosition, destinationPosition);


                    //this updates the current position of the selected piece, so that the capture mechanism can funciton properly
                    this->update();

                    //CAPTURE MECHANISM
                    if (pieceMoved == true)
                    {
                        for (int i = 0; i < 32; i++)
                        {
                            for (int j = 0; j < 32; j++)
                            {

                                if ((pieces_currentPosition[i] == pieces_currentPosition[j]) && (i != j))
                                {
                                    if (piecesList[i]->getIsAttacker() == true)
                                    {
                                        piecesList[j]->remove();

                                    }
                                }
                            }
                        }
                    }


                    isSelectedSetter(false);
                    isMovingSetter(false);

                }
            }
        }
        
    }
}
