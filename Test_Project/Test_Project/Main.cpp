#include "Game.h"

int main()
{
    Game game;

    while (game.isRunning())
    {

        game.pollEvent();

        //updates to objects
        game.update();


        //render graphics
        game.render();

    }

    return 0;
}