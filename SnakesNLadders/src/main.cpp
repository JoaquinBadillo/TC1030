#include <iostream>
#include "myGame.hpp"

int main(void)
{
    MyGame game = MyGame();

    bool startGame = game.start();

    bool keepPlaying = false;
    
    if (startGame)
    {
        do
        {
            keepPlaying = game.turn();
        } while (keepPlaying);

        return 0;
    }

    return 1;

}