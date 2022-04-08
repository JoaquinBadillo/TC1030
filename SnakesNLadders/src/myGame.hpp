#ifndef myGame_h
#define myGame

#include <iostream>
#include <cctype>
#include <stdlib.h>

#include "grid.hpp"
#include "player.hpp"
#include "dice.hpp"

class MyGame: public Grid
{
    private:
        Player player1 = Player();
        Player player2 = Player();
        Dice dice = Dice();

        int turnNum = 1;

        int diceScore = 0;

        char option = '\0';

    public:
        MyGame() : Grid()
        {

        }

        bool start()
        {
            std::cout << "Welcome to Snakes and Ladders!" << std::endl;
            std::cout << "This version of the game supports only 2 players" << std::endl;
            std::cout << "For a better UX we encourage using the terminal in full screen" << std::endl;
            std::cout << "At the end of each turn you must do one of the following:" << std::endl;
            std::cout << "\tPress 'C' to continue playing." << std::endl;
            std::cout << "\tPress 'T' to end the game." << std::endl;

            std::cout << std::endl;

            std::cout << "\tPress 'S' or 'C' to start the game." << std::endl;
            std::cout << "\tPress 'Q' to quit." << std::endl;

            std::cout << "Option chosen: ";

            while ((std::tolower(option) != 's') && (std::tolower(option) != 'c') && (std::tolower(option) != 'q'))
            {
                std::cin >> option;

                if ((std::tolower(option) != 's') && (std::tolower(option) != 'c') && (std::tolower(option) != 'q'))
                {
                    std::cout << "Please use a valid character: ";
                }
            }

            std::system("clear");

            updateLayout(player1, 1);
            updateLayout(player2, 2);

            return (std::tolower(option) == 's') || (std::tolower(option) == 'c');
        }

        bool turn()
        {
            if ((std::tolower(option) != 's') && (std::tolower(option) != 'c'))
            {
                return false;
            }

            if (turnNum == 16) // Turn limit
            {
                std::cout << "-- GAME OVER --" << std::endl;
                std::cout << std::endl;

                int score1 = (player1.getPositionX() + 1) * (player1.getPositionY() + 1);
                int score2 = (player2.getPositionX() + 1) * (player2.getPositionY() + 1);

                if (score1 > score2)
                {
                    std::cout << "P1 got farther than P2!" << std::endl;
                }

                else if (score2 > score1)
                {
                    std::cout << "P2 got farther than P1!" << std::endl;
                }

                else
                {
                    std::cout << "Draw!" << std::endl;
                }

                return false;
            }

            std::cout << "Turn " << turnNum << " (Player 1)\n\n";

            int previousX = player1.getPositionX();
            int previousY = player1.getPositionY();

            int tileNumber = tileNum(previousX, previousY);

            diceScore = dice.roll();
            std::cout << "Player 1: threw a " << diceScore << std::endl;
            std::cout << std::endl;

            std::cout << "Player 1 moved from tile " << tileNumber << " ";

            player1.move(diceScore);

            player1.bonusMove(tileBonus(player1.getPositionX(), player1.getPositionY()));

            tileNumber = tileNum(player1.getPositionX(), player1.getPositionY());

            std::cout << "to tile " << tileNumber << std::endl;
            std::cout << std::endl;

            updateLayout(previousX, previousY, player1, 1);
            printGrid();          

            if((player1.getPositionX() + 1) * (player1.getPositionY() + 1) == 30)
            {
                std::cout << "-- GAME OVER --" << std::endl;
                std::cout << std::endl;

                std::cout << "Player 1 Wins!" << std::endl;
                return false;
            }

            turnNum++;

            std::cout << "Turn " << turnNum << " (Player 2)\n\n";

            previousX = player2.getPositionX();
            previousY = player2.getPositionY();

            tileNumber = tileNum(previousX, previousY);

            diceScore = dice.roll();
            std::cout << "Player 2: threw a " << diceScore << std::endl;
            std::cout << std::endl;

            std::cout << "Player 2 moved from tile " << tileNumber << " ";
            
            player2.move(diceScore);

            player2.bonusMove(tileBonus(player2.getPositionX(), player2.getPositionY()));

            tileNumber = tileNum(player2.getPositionX(), player2.getPositionY());

            std::cout << "to tile " << tileNumber << std::endl;
            std::cout << std::endl;

            updateLayout(previousX, previousY, player2, 2);
            printGrid();

            if((player2.getPositionX() + 1) * (player2.getPositionY() + 1) == 30)
            {
                std::cout << "-- GAME OVER --" << std::endl;
                std::cout << std::endl;

                std::cout << "Player 2 Wins!" << std::endl;
                return false;
            }

            turnNum++;

            do
            {
                std::cout << "Do you want to continue (c) or end (t) the game? ";
                std::cin >> option;
            } while ((std::tolower(option) != 'c') && (std::tolower(option) != 't'));

            std::cout << std::endl;

            if (option == 't')
            {
                std::cout << "-- Thanks for playing! --" << std::endl;
                std::cout << std::endl;

                int score1 = (player1.getPositionX() + 1) * (player1.getPositionY() + 1);
                int score2 = (player2.getPositionX() + 1) * (player2.getPositionY() + 1);

                if (score1 > score2)
                {
                    std::cout << "P1 got farther than P2!" << std::endl;
                }

                else if (score2 > score1)
                {
                    std::cout << "P2 got farther than P1!" << std::endl;
                }

                else
                {
                    std::cout << "Draw!" << std::endl;
                }
            }

            return true;
        }
};


#endif